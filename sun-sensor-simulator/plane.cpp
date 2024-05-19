#include "plane.h"
#include <cmath>
#include <cstdio>

Plane::Plane(Vector_3D origin, Vector_3D normal_G, double size_x, double size_y){
    this->origin = origin;
    this->normal_S = Vector_3D(0,0,1);
    this->normal_G = normal_G;
    this->dcm_BN = this->normal_S.rmat_to(normal_G);
    this->size_x = size_x;
    this->size_y = size_y;
    this->n = 0;
}

Plane::Plane(Vector_3D origin, Matrix_3D dcm_BN, double size_x, double size_y){
    this->origin = origin;
    this->normal_S = Vector_3D(0,0,1);
    this->dcm_BN = dcm_BN;
    this->normal_G = this->dcm_BN * this->normal_S;
    this->size_x = size_x;
    this->size_y = size_y;
    this->n = 0;
}

Plane::Plane(Vector_3D origin, Matrix_3D dcm_BN, double size_x, double size_y, double n1, double n2){
    this->origin = origin;
    this->normal_S = Vector_3D(0,0,1);
    this->dcm_BN = dcm_BN;
    this->normal_G = this->dcm_BN * this->normal_S;
    this->size_x = size_x;
    this->size_y = size_y;
    this->n = n1 / n2;
}
Plane::Plane(Vector_3D origin, Matrix_3D dcm_BN, double size_x, double size_y, double n){
    this->origin = origin;
    this->normal_S = Vector_3D(0,0,1);
    this->dcm_BN = dcm_BN;
    this->normal_G = this->dcm_BN * this->normal_S;
    this->size_x = size_x;
    this->size_y = size_y;
    this->n = n;
}

Vector_3D Plane::calculate_point_of_contact(Particle particle){ 
    double top_value = this->normal_G * (particle.position - this->origin);
    double bottom_value = this->normal_G * particle.direction;
    double lambda = - top_value / bottom_value;
    Vector_3D point_of_contact = particle.position +  particle.direction * lambda;
    return point_of_contact;
}

int8_t Plane::particle_colission(Particle *particle){
    // check if partile and plane are orthogonal and error return
    if (particle->direction * this->normal_G == 0){
        return 1;
    }
    // check if particle comes from behind -- todo make angle settable
    if (this->normal_G.calculate_angle(particle->direction) >= 90){
        return 2;
    }

    /* 
     * check wether or not the particle is in the designated zone
     * 1. Transfer particle into sensor frame
     * 2. Check bounds
     * 3. if err return unchanged particle
     * 4. if no err change position to contact point
     */

    Vector_3D contact_point_G;
    Vector_3D contact_point_shifted;
    Vector_3D contact_point_S;
    contact_point_G = this->calculate_point_of_contact(*particle);

    contact_point_shifted = contact_point_G - this->origin;

    contact_point_S = this->dcm_BN.inverse() * contact_point_shifted; 

    if (contact_point_S.x > this->size_x) return 3;
    if (contact_point_S.y > this->size_y) return 3;
    if (contact_point_S.x < -this->size_x) return 3;
    if (contact_point_S.y < -this->size_y) return 3;

    particle->position = contact_point_G;

    /*
     * we also need to change the angle of the vector.
     * To do this we view the vector in the sensor Frame and center the view around the point of contact
     * We can then describe our vector by the angle around the z axis and the angle around the axis made from normal x particle direction
     * this second vector is the one effected by snell's law
     * the rotation can the be done by use of the Rodrigues' rotation formula
     */

    // snell's law
    Vector_3D particle_direction_S = (this->dcm_BN.inverse() * particle->direction).normalize();
    double angle_of_incidence = this->normal_S * particle_direction_S;
    double theat = asin(this->n * sin (angle_of_incidence));

    // rotation axis
    Vector_3D axis;
    axis = this->normal_S.cross_product(particle_direction_S);

    // rr formula
    Vector_3D particle_direction_rot_S;
    Vector_3D particle_direction_rot_G;
    Vector_3D k;
    k = axis.normalize();
    particle_direction_rot_S = particle_direction_S * cos (theat) 
        + k.cross_product(particle_direction_S) * sin(theat) 
    + k * (k * particle_direction_S) * (1 - cos (theat));

    particle_direction_rot_G = this->dcm_BN * particle_direction_rot_S;
    particle->direction = particle_direction_rot_G;

    return 0;

}


void Plane::get_directional_angles(Vector_3D direction, double *x, double *y){
    /*
     * To get the angles we firts project to the local frame and then decompose to the x and y componennts
     */

    Vector_3D part_x, part_y, direction_B;
    direction_B = this->dcm_BN * direction;
    part_x.x = direction_B.x;
    part_x.z = direction_B.z;
    part_y.y = direction_B.y;
    part_y.z = direction_B.z;
    *x = this->normal_S.calculate_angle(part_x);
    *y = this->normal_S.calculate_angle(part_y);
}

void Plane::set_light_source_relative_postion_at_angle(light_source * source, double angle_x, double angle_y) {
    /*
     * 1. get distance to ls
     * 2. Generate unit vector and multiply with distance
     * 3. Transform to global frame
     */
    double distance;
    Vector_3D unit;
    Vector_3D position_G;

    distance = (this->origin - source->position).norm();

    unit.z = sqrt (1 / (tan(angle_x) * tan(angle_x) + tan(angle_y) * tan(angle_y) + 1) );
    unit.x = unit.z * tan (angle_x);
    unit.y = unit.z * tan (angle_y);

    position_G = (this->dcm_BN * unit) * distance; 

    source->position = position_G;

}
