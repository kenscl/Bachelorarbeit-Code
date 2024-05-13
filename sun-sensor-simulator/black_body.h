#include "light_source.h"
#include "plane.h"

#ifndef __BLACK_BODY
#define __BLACK_BODY
class black_body : public light_source{
    public:
        std::vector<Plane> glass_planes;
        double particle_enegery;
        double wavelength_max, wavelength_min;
    public:
        black_body();
        black_body(std::vector<Plane> glass_planes, double particle_energy, double wavelength_max, double wavelength_min);
        double Uv(double frequency, double Temperature_K);
        double generate_photon(double temperature, double max_wavelength, double min_wavelenth);
        /*
         * This function generates count particles for every slit in the sensor.
         * Before calling this function first set glass_planes to your slits.
         */
        std::vector<Particle> generate_particles(int count) override;
};
#endif
