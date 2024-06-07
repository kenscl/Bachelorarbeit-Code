#include "../math/matlib.h"
class Sat_Model {
    public: 
        Matrix<double> mag_misalignment;
        Matrix<double> gyro_misalignments;
        std::vector<Matrix<double>> ss_misaligments;
        Vector<double> sun_vector;
        Vector<double> mag_vector;

        Matrix<double> dcm_SB_mag;
        Matrix<double> dcm_SB_gyro;
        std::vector<Matrix<double>> dcm_SB_ss;

        double angle_x;
        double angle_y;

    public: 
        Sat_Model(Matrix<double> mag_misalignment, Matrix<double> gyro_misalignments, std::vector<Matrix<double>> ss_misaligments, Vector<double> sun_vector, Vector<double> mag_vector);
        std::vector<Vector<double>> get_sun_vectors();
        Vector<double> get_mag_vector();
        Vector<double> get_gyro_vector();
        void set_vector_delta(double angle_x, double angle_y);
};
