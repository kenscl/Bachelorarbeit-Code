#include "sat_model.h"

int main () {
    // Sat_Model(Matrix<double> mag_misalignment, Matrix<double> gyro_misalignments, std::vector<Matrix<double>> ss_misaligments, Vector<double> sun_vector, Vector<double> mag_vector);
    Sat_Model sat_model((Matrix<double>()), Matrix<double>(), std::vector<Matrix<double>>(), Vector<double>(), Vector<double>());
}
