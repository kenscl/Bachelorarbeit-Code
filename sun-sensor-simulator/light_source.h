#include "math/matlib.h"
#include "particle.h"
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
};

#endif
