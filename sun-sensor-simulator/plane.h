# include "math/matlib.h"
# include "particle.h"
#ifndef __PLANE
#define __PLANE
class Plane {
    public:
        Vector_3D origin, normal_S, normal_G;
        double size_x, size_y;
        Matrix_3D dcm_BN;
        double n;
    public: 
        Plane(Vector_3D origin, Vector_3D normal_G, double size_x, double size_y);
        Plane(Vector_3D origin, Matrix_3D dcm_BN, double size_x, double size_y);
        Plane(Vector_3D origin, Matrix_3D dcm_BN, double size_x, double size_y, double n1, double n2);
        /*
         * n = n1/n2
         */
        Plane(Vector_3D origin, Matrix_3D dcm_BN, double size_x, double size_y, double n);

        Vector_3D calculate_point_of_contact(Particle particle);
        int8_t particle_colission(Particle *particle);
        


        
};
#endif