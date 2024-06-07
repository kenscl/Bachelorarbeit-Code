#include "sat_model.h"
Sat_Model::Sat_Model(Matrix<double> mag_misalignment, Matrix<double> gyro_misalignments, std::vector<Matrix<double>> ss_misaligments, Vector<double> sun_vector, Vector<double> mag_vector) {
    this->mag_misalignment = mag_misalignment;
    this->gyro_misalignments = gyro_misalignments;
    this->ss_misaligments = ss_misaligments;

    // init Sensor to Body dcms
    Matrix<double> mag_dcm_SB(3,3);
    mag_dcm_SB.data.at(0).at(0) = 1;
    mag_dcm_SB.data.at(1).at(1) = 1;
    mag_dcm_SB.data.at(2).at(2) = 1;
    this->dcm_SB_mag = mag_dcm_SB;

    Matrix<double> gyro_dcm_SB(3,3);
    gyro_dcm_SB.data.at(0).at(0) = 1;
    gyro_dcm_SB.data.at(1).at(1) = 1;
    gyro_dcm_SB.data.at(2).at(2) = 1;
    this->dcm_SB_gyro = gyro_dcm_SB;

    std::vector<Matrix<double>> ss_SB;
    Matrix<double> ss_xp_dcm_SB(3,3);
    ss_xp_dcm_SB.data.at(0).at(0) = 1;
    ss_xp_dcm_SB.data.at(2).at(1) = -1;
    ss_xp_dcm_SB.data.at(1).at(2) = 1;
    ss_SB.push_back(ss_xp_dcm_SB);
    
    Matrix<double> ss_xm_dcm_SB(3,3);
    ss_xm_dcm_SB.data.at(0).at(0) = -1;
    ss_xm_dcm_SB.data.at(2).at(1) = 1;
    ss_xm_dcm_SB.data.at(1).at(2) = 1;
    ss_SB.push_back(ss_xm_dcm_SB);

    Matrix<double> ss_yp_dcm_SB(3,3);
    ss_yp_dcm_SB.data.at(1).at(0) = 1;
    ss_yp_dcm_SB.data.at(0).at(1) = 1;
    ss_yp_dcm_SB.data.at(2).at(2) = -1;
    ss_SB.push_back(ss_yp_dcm_SB);

    Matrix<double> ss_ym_dcm_SB(3,3);
    ss_ym_dcm_SB.data.at(1).at(0) = -1;
    ss_ym_dcm_SB.data.at(0).at(1) = 1;
    ss_ym_dcm_SB.data.at(2).at(2) = 1;
    ss_SB.push_back(ss_ym_dcm_SB);

    Matrix<double> ss_zp_dcm_SB(3,3);
    ss_zp_dcm_SB.data.at(2).at(0) = 1;
    ss_zp_dcm_SB.data.at(0).at(1) = 1;
    ss_zp_dcm_SB.data.at(1).at(2) = 1;
    ss_SB.push_back(ss_zp_dcm_SB);


    Matrix<double> ss_zm_dcm_SB(3,3);
    ss_zm_dcm_SB.data.at(2).at(0) = -1;
    ss_zm_dcm_SB.data.at(0).at(1) = 1;
    ss_zm_dcm_SB.data.at(1).at(2) = 1;
    ss_SB.push_back(ss_zm_dcm_SB);
    
    this->dcm_SB_ss = ss_SB;
}

std::vector<Vector<double>> Sat_Model::get_sun_vectors() {
    std::vector<Vector<double>> ret;
    for (uint i = 0; i < this->dcm_SB_ss.size(); i++) {
        Vector<double> normal_S(3);
        Vector<double> result;
        normal_S.data.at(2) = 1;
        Vector<double> normal = this->dcm_SB_ss.at(i) * normal_S;

        Vector_3D normal_G, sun_vector;
        normal_G.x = normal.data.at(0);
        normal_G.y = normal.data.at(1);
        normal_G.z = normal.data.at(2);
        sun_vector.x = this->sun_vector.data.at(0);
        sun_vector.y = this->sun_vector.data.at(1);
        sun_vector.z = this->sun_vector.data.at(2);

        Matrix<double> mounting_matrix = this->ss_misaligments.at(i) * this->dcm_SB_ss.at(i); 

        result = mounting_matrix.inverse() * this->sun_vector;

        double angle = normal_G.calculate_angle(sun_vector);
        if (angle > 90 * D2R) {
            result.data.at(0) = 0;
            result.data.at(1) = 0;
            result.data.at(2) = 0;
        }
        if (angle < -90 * D2R) {
            result.data.at(0) = 0;
            result.data.at(1) = 0;
            result.data.at(2) = 0;
        }

        ret.push_back(result);
    }
    return ret;
}

Vector<double> Sat_Model::get_mag_vector() {
        Vector<double> result;
        Matrix<double> mounting_matrix = this->mag_misalignment * this->dcm_SB_mag;
        result = mounting_matrix.inverse() * this->mag_vector;
        return result;
}


Vector<double> Sat_Model::get_gyro_vector() {
    Vector<double> rotation, result;
    rotation.data.at(0) = this->angle_x;
    rotation.data.at(1) = this->angle_y;

    Matrix<double> mounting_matrix = this->gyro_misalignments * this->dcm_SB_gyro;

    result = mounting_matrix.inverse() * rotation;
    return result;
}

void Sat_Model::set_vector_delta(double angle_x, double angle_y) {
    this->angle_x = angle_x;
    this->angle_y = angle_y;
    Vector<double> e_x, e_y;
    e_x.data.at(0) = 1;
    e_y.data.at(1) = 1;

    Quaternion<double> q_x(angle_x, e_x);
    Quaternion<double> q_y(angle_y, e_y);
    Quaternion<double> rotation = q_y * q_x;

    Quaternion<double> mag_q, sun_q;
    mag_q = Quaternion<double>(0, this->mag_vector.data.at(0), this->mag_vector.data.at(1), this->mag_vector.data.at(2));
    sun_q = Quaternion<double>(0, this->sun_vector.data.at(0), this->sun_vector.data.at(1), this->sun_vector.data.at(2));

    mag_q = rotation * mag_q * rotation.conjugate();
    sun_q = rotation * sun_q * rotation.conjugate();
    
    this->mag_vector.data.at(0) = mag_q.i;
    this->mag_vector.data.at(1) = mag_q.j;
    this->mag_vector.data.at(2) = mag_q.k;

    this->sun_vector.data.at(0) = sun_q.i;
    this->sun_vector.data.at(1) = sun_q.j;
    this->sun_vector.data.at(2) = sun_q.k;
}
