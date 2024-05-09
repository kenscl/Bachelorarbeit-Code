#include "plane.h"
#include "light_source.h"
#include <vector>

#ifndef __SUN_SENSOR 
#define __SUN_SENSOR
class Sun_sensor {
    public:
        std::vector<Plane> diodes;
        std::vector<Plane> slits_top;
        std::vector<Plane> slits_bottom;
        Vector_3D position;
        Matrix_3D dcm_BN;

    public: 
        Sun_sensor();
        Sun_sensor(Vector_3D position, Matrix_3D dcm_BN, std::vector<Plane> diodes, std::vector<Plane> slits_top, std::vector<Plane> slits_bottom);

        std::vector<double> simulate(light_source source);
};

class ADPD2140 : Sun_sensor {

    public: 
        ADPD2140(Vector_3D position, Matrix_3D dcm_BN);
};
#endif
