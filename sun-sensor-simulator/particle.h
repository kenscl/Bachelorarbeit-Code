#include "math/matlib.h"
#ifndef __PARTICLE
#define __PARTICLE
class Particle {
    public:
        Vector_3D position;
        Vector_3D direction;
        double wavelength;
        double power;

    public: 
        Particle();
        Particle(Vector_3D position, Vector_3D direction, double wavelength, double power);
};
# endif
