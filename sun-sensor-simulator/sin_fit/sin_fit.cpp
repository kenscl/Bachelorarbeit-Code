#include "sin_fit.h"
#include <cstdio>

Matrix<double> Sin_Fit::Jacobian(int64_t degree, std::vector<double> gt_data, std::vector<double> measurement) {
    Matrix<double> jacobian(measurement.size(), 2 * degree); 

    for (uint j = 0; j < measurement.size(); j++) {
        for (int i = 0; i < degree; i++) {
            double x = measurement.at(j);
            double amp_param = this->parameters.data.at(2 * i);  
            double freq_param = this->parameters.data.at(2 * i + 1);

            jacobian.data.at(j).at(2 * i) = sin(freq_param * x);
            jacobian.data.at(j).at(2 * i + 1) = amp_param * x * cos(freq_param * x);
        }
    }

    return jacobian;
}

Sin_Fit::Sin_Fit(int64_t degree, int64_t steps, std::vector<double> gt_data, std::vector<double> measurement) {
    this->degree = degree;

    double ak = 0.0001;
    double bk = 0.0001;
    Vector<double> params = Vector<double>((int) 2 * degree);
    this->parameters = params;
    for (int i = 0; i < params.size; i++) {
        if (i %2 == 0) this->parameters.data.at(i) = 0.3;
        else this->parameters.data.at(i) = 0.01;
    } 

    /*
     * 1. Inital guess
     * 2. calculate the residuals
     * 3. S = sum r^2
     */

    for (int i = 0; i < steps; i++) {
    this->parameters.print();
        // calculating the residuals
        Vector<double> residuals(measurement.size());
        for (uint j = 0; j < measurement.size(); j++) {
            residuals.data.at(j) = measurement.at(j) - this->at(gt_data.at(j));
        }

        // calculating S
        double S = 0;
        for (uint j = 0; j < residuals.size; j++) {
            S += residuals.data.at(j) * residuals.data.at(j);
        }

        Matrix<double> jacobian = this->Jacobian(degree, gt_data, measurement);

        Matrix<double> I = Matrix<double>::Identity(jacobian.cols);

        Matrix<double> JtJ = jacobian.transpose() * jacobian;
        Matrix<double> JtJ_reg = JtJ + I * bk;

        Matrix<double> inv = JtJ_reg.moore_penrose();

        Vector<double> delta_params = inv * jacobian.transpose() * residuals * ak;
        this->parameters = this->parameters - delta_params;
    }

}

double Sin_Fit::at(double x) {
    double sum = 0;
    for (int k = 0; k < this->degree; ++k) {
        double amp_param = this->parameters.data.at(2 * k);
        double freq_param = this->parameters.data.at(2 * k + 1);
        sum += amp_param * sin(freq_param * x);
    }
    return sum;
}

std::vector<double> Sin_Fit::calc(std::vector<double> x) {
    std::vector<double> ret;
    for (uint i = 0; i < x.size(); i++) {
        ret.push_back(this->at(x.at(i)));
    }
    return ret;
}
