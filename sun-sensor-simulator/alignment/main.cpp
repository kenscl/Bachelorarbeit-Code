#include "sat_model.h"
#include <vector>

int main () {
    // Sat_Model(Matrix<double> mag_misalignment, Matrix<double> gyro_misalignments, std::vector<Matrix<double>> ss_misaligments, Vector<double> sun_vector, Vector<double> mag_vector);
    std::vector<Matrix<double>> ss_alignments;
    ss_alignments.push_back(Matrix<double>().Identity(3));
    ss_alignments.push_back(Matrix<double>().Identity(3));
    ss_alignments.push_back(Matrix<double>().Identity(3));
    ss_alignments.push_back(Matrix<double>().Identity(3));
    ss_alignments.push_back(Matrix<double>().Identity(3));
    ss_alignments.push_back(Matrix<double>().Identity(3));
    
    Vector<double> sun_vector(3);
    sun_vector.data.at(0) = 1;

    Vector<double> mag_vector(3);


    Sat_Model sat_model((Matrix<double>().Identity(3)), Matrix<double>().Identity(3), ss_alignments, sun_vector, mag_vector);
    std::vector<Vector<double>> sun_meas;
    for (double i = 0; i < 360 * D2R; i+=1*D2R) {
        sun_meas = sat_model.get_sun_vectors();
        for (uint i = 0; i < sun_meas.size(); ++i) {
            if (sun_meas.at(i).norm() != 0) {
                sun_meas.at(i).print();
            }
        }
        sat_model.set_vector_delta(1 * D2R, 0);
    }
}
