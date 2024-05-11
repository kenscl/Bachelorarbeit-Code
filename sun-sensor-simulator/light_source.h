#include "math/matlib.h"
#include "particle.h"
#include <cstdio>
#include <vector>
#ifndef __LIGH_SOURCE
#define __LIGH_SOURCE
class light_source {
    public:
        Vector_3D position;
        std::vector<Particle> particles;

    public: 
        light_source();
        light_source(Vector_3D position);
        virtual std::vector<Particle> generate_particles(int count){
            printf("You called generate_particles() from the light source class. \n This function is only ment to be a placeholder for other classes that should override it. \n Please implement your own generate_particles in a custome calss. \n");
            return std::vector<Particle>();
        }
};

#endif
