#include "particle.h"
Particle::Particle(){
    this->position = Vector_3D(0,0,0);
    this->direction = Vector_3D(0,0,0);
    this->wavelength = 0;
    this->power = 0;
}

Particle::Particle(Vector_3D position, Vector_3D direction, double wavelength, double power){
    this->position = position;
    this->direction = direction;
    this->wavelength = wavelength;
    this->power = power;
}
