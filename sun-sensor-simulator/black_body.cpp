#include "black_body.h"
#include <cmath>
#include <random>

black_body::black_body() {
    this->wavelength_max = 1102;
    this->wavelength_min = 359;
    this->position = Vector_3D(0,0,0);
    this->particle_enegery = 0;
}
black_body::black_body(std::vector<Plane> glass_planes, double particle_energy, double wavelength_max, double wavelength_min) {

    this->wavelength_max = wavelength_max;
    this->wavelength_min = wavelength_min;
    this->particle_enegery = particle_energy;
    this->glass_planes = glass_planes;
}
double black_body::Uv(double wavelength_nm, double temperature_K){
    double wavelength_m = wavelength_nm * 1e-9;
    double numerator = 2 * PLANCK_CONSTANT * pow(C, 2);
    double denominator = pow(wavelength_m, 5) * (exp((PLANCK_CONSTANT * C) / (wavelength_m * BOLTZMANN_CONSTANT * temperature_K)) - 1);
    return numerator / denominator;
}

double black_body::generate_photon(double temperature, double min_wavelength, double max_wavelength) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    
    double wavelength = min_wavelength + dis(gen) * (max_wavelength - min_wavelength);
    double radiance = this->Uv(wavelength, temperature);
    double probability = dis(gen);

    if (probability < radiance) {
        return wavelength;
    } else {
        return 0.0; 
    }
}


std::vector<Particle> black_body::generate_particles(int count) {
    std::vector<Particle> particles;
    std::vector<Plane>::iterator it;
    
    /* 
     * The particles need to be generated in the glass planes frame and in the bound of the glass plane.
     * Therefore:
     * 1. Determine count random positions on the pane.
     * 2. Propagate particles backwards
     */
    for (it = this->glass_planes.begin(); it != this->glass_planes.end(); it++) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis_x(-it->size_x, it->size_x);
        std::uniform_real_distribution<> dis_y(-it->size_y, it->size_y);
        std::vector<Vector_3D> generated;

        for (int i = 0; i < count; i++) {
            Vector_3D pos_S;
            // Generate particle on plane and transform to global frame
            bool pass = false;
            while (pass == false) {
                double pos_x = dis_x(gen);
                double pos_y = dis_y(gen);
                pos_S = Vector_3D(pos_x, pos_y, 0);
                pass = true;
                for (int j = 0; j < generated.size(); j++){
                    if (generated[j].distance_to(pos_S) < (it->size_x + it->size_y) / (16 * count)) pass = false;
                }
            }
            generated.push_back(pos_S);

            Vector_3D pos_G_prime;
            Vector_3D pos_G;
            pos_G_prime = it->dcm_BN * pos_S;
            pos_G = pos_G_prime + it->origin; // this is not needed

            // Propagate particle along direction vector from bb to pane
            Vector_3D bb_to_plane;
            Vector_3D particle_position;

            bb_to_plane = it->origin - this->position;
            particle_position = this->position + pos_G_prime;

            // generate wavelength for particle
            double wavelength = this->generate_photon(5770, this->wavelength_min, this->wavelength_max);

            Particle particle(particle_position, bb_to_plane, wavelength, this->particle_enegery);
            printf("%f %f \n", pos_S.x, pos_S.y);

            particles.push_back(particle);
        } 
    }

    return particles;
}
