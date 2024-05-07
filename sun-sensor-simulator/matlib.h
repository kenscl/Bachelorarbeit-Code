# include "math.h"
# define PI                 3.14159265359
# define C                  299792458.0
# define PLANCK_CONSTANT    6.62607015e-34
# define BOLTZMANN_CONSTANT 1.380649e-23
class Vector_3D {
    public: 
        double x,y,z;

    public: 
        Vector_3D();
        Vector_3D(double x, double y, double z);
        Vector_3D(Vector_3D const &other);
};
