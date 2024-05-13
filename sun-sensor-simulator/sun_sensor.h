#include "plane.h"
#include "light_source.h"
#include <cstdint>
#include <vector>

#ifndef __SUN_SENSOR 
#define __SUN_SENSOR

struct rvw_data {
    double responsivity;
    double wavelength;
};
class Sun_sensor {
    public:
        std::vector<Plane> diodes;
        std::vector<Plane> slits_top;
        std::vector<Plane> slits_bottom;
        Vector_3D position;
        Matrix_3D dcm_BN;
        char * rvw_file; 
        std::vector<rvw_data> rvw;
        double rvw_len;

    public: 
        Sun_sensor();
        Sun_sensor(Vector_3D position, Matrix_3D dcm_BN, std::vector<Plane> diodes, std::vector<Plane> slits_top, std::vector<Plane> slits_bottom);

        std::vector<double> simulate(light_source * source, uint64_t particle_count);
        void read_rvw(char * file);
        void read_rvw();
};

class ADPD2140 : Sun_sensor {

    public: 
        ADPD2140(Vector_3D position, Matrix_3D dcm_BN);
};
#endif
