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
}

Plane::Plane(Vector_3D origin, Matrix_3D dcm_BN, double size_x, double size_y){
    this->origin = origin;
    this->normal_S = Vector_3D(0,0,1);
    this->dcm_BN = dcm_BN;
    this->normal_G = this->dcm_BN * this->normal_S;
    this->size_x = size_x;
    this->size_y = size_y;
}

Plane::Plane(Vector_3D origin, Matrix_3D dcm_BN, double size_x, double size_y, double n1, double n2){
    Plane(origin, dcm_BN, size_x, size_y);
    this->n = n1 / n2;
}
Plane::Plane(Vector_3D origin, Matrix_3D dcm_BN, double size_x, double size_y, double n){
    Plane(origin, dcm_BN, size_x, size_y);
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

int main(){
    Plane plane = Plane(Vector_3D(1,0,0), Vector_3D(1,1,1), 10, 10);
    Particle particle = Particle(Vector_3D(0,1,1), Vector_3D (0,0,-1), 0);
    plane.particle_colission(&particle);
}

