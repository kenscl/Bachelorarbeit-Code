#include "../plane.h"
#include "../light_source.h"
#include <cstdint>
#include <vector>

#ifndef __SUN_SENSOR 
#define __SUN_SENSOR

struct rvw_data {
    double responsivity;
    double wavelength;
};

struct radiant_senitivity_data{
    double angle, sensitivity;
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
        int rvw_len;

        char * radiant_senitivity_file; 
        std::vector<radiant_senitivity_data> radiant_senitivity_x;
        std::vector<radiant_senitivity_data> radiant_senitivity_y;
        int radiant_senitivity_len_x;
        int radiant_senitivity_len_y;

        std::vector<Plane> light_source_vector;

    public: 
        Sun_sensor();
        Sun_sensor(Vector_3D position, Matrix_3D dcm_BN, std::vector<Plane> diodes, std::vector<Plane> slits_top, std::vector<Plane> slits_bottom);

        std::vector<double> simulate(light_source * source, uint64_t particle_count);
        void read_rvw(char * file);
        void read_rvw();
        void read_radiant_sensitivity(char* file);
        void read_radiant_sensitivity();
};

#endif
