#include "black_body.h"
#include <cmath>

double black_body::Uv(double wavelength_nm, double temperature_K){
    double wavelength_m = wavelength_nm * 1e-9;
    double numerator = 2 * PLANCK_CONSTANT * pow(C, 2);
    double denominator = pow(wavelength_m, 5) * (exp((PLANCK_CONSTANT * C) / (wavelength_m * BOLTZMANN_CONSTANT * temperature_K)) - 1);
    return numerator / denominator;
}



