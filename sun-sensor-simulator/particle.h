#include "math/matlib.h"
class Particle {
    public:
        Vector_3D position;
        Vector_3D direction;
        double wavelength;

    public: 
        Particle();
        Particle(Vector_3D position, Vector_3D direction, double wavelength);
};
