#include "black_body.h"
#include <cmath>
#include <random>

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
        for (int i = 0; i < count; i++) {
            // Generate particle on plane and transform to global frame
            double pos_x = dis_x(gen);
            double pos_y = dis_y(gen);
            
            Vector_3D pos_G_prime;
            Vector_3D pos_G;
            Vector_3D pos_S(pos_x, pos_y, 0);
            pos_G_prime = it->dcm_BN * pos_S;
            pos_G = pos_G_prime + it->origin; // this is not needed

            // Propagate particle along direction vector from bb to pane
            Vector_3D bb_to_plane;
            Vector_3D particle_position;

            bb_to_plane = it->origin - this->position;
            particle_position = this->position + pos_G_prime;

            // generate wavelength for particle
            double wavelength = this->generate_photon(5770, 300, 1300);

            Particle particle(particle_position, bb_to_plane, wavelength, this->particle_enegery);

            particles.push_back(particle);
        } 
    }
    return particles;
}
