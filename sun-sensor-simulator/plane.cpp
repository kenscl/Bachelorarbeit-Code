#include "plane.h"
#include <cstdio>

Plane::Plane(Vector_3D origin, Vector_3D normal_G, double size_x, double size_y){
    this->origin = origin;
    this->normal_S = Vector_3D(0,0,1);
    this->dcm_BN = this->normal_S.rmat_to(normal_G);
    this->size_x = size_x;
    this->size_y = size_y;

}

Plane::Plane(Vector_3D origin, Matrix_3D dcm_BN, double size_x, double size_y){
    this->origin = origin;
    this->normal_S = Vector_3D(0,0,1);
    this->dcm_BN = dcm_BN;
    this->size_x = size_x;
    this->size_y = size_y;
}

Vector_3D Plane::calculate_point_of_contact(Particle particle){ 
    double top_value = this->normal_G * (particle.position - this->origin);
    double bottom_value = this->normal_G * particle.direction;
    double lambda = - top_value / bottom_value;
    Vector_3D point_of_contact = particle.position +  particle.direction * lambda;
    return point_of_contact;
}

int8_t Plane::particle_colission(Particle particle){
    if (particle.direction * this->normal_G == 0){
        return 1;
    }

    if (this->normal_G.calculate_angle(particle.direction) >= 90){
        return 2;
    }
    Vector_3D contact_point = this->calculate_point_of_contact(particle);
}

int main(){
   // Plane plane = Plane(Vector_3D(0,0,0), Vector_3D(0,0,1), 0, 0);
   // Particle particle = Particle(Vector_3D(0,0,1), Vector_3D (0,0,1), 0);
   // plane.calculate_point_of_contact(particle).print();
    Vector_3D v1(1,2,3);
    Vector_3D v2(3,2,1);
    v2.normalize().print();
    Matrix_3D rmat = v1.rmat_to(v2);
    printf("v2 t: \n");
    (rmat * v1).normalize().print();
}

