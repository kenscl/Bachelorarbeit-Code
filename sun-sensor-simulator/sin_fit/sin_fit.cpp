#include "sin_fit.h"
#include <cstdio>

Matrix<double> Sin_Fit::Jacobian(int64_t degree, const std::vector<double>& gt_data) {
    Matrix<double> jacobian(gt_data.size(), 2 * degree); 

    for (size_t j = 0; j < gt_data.size(); j++) {
        double x = gt_data.at(j);
        for (int i = 0; i < degree; i++) {
            double amp_param = this->parameters.data.at(2 * i);  
            double freq_param = this->parameters.data.at(2 * i + 1);

            jacobian.data.at(j).at(2 * i) = sin(freq_param * x); // dR/d(b1)
            jacobian.data.at(j).at(2 * i + 1) = amp_param * x * cos(freq_param * x); // dR/d(b2)
        }
    }

    return jacobian;
}

Sin_Fit::Sin_Fit(int64_t degree, int64_t steps, std::vector<double> gt_data, std::vector<double> measurement) {
    this->degree = degree;

    double ak = .1;
    double bk = 0;
    Vector<double> params = Vector<double>((int) 2 * degree);
    this->parameters = params;
    for (int i = 0; i < params.size; i++) {
        if (i %2 == 0) this->parameters.data.at(i) = 1;
        else this->parameters.data.at(i) = 1;
    } 

    /*
     * 1. Inital guess
     * 2. calculate the residuals
     * 3. S = sum r^2
     */

    //for (int i = 0; i < steps; i++) {
    double S = 100;
    while (S > 1e-3) {
    //this->parameters.print();
        // calculating the residuals
        Vector<double> residuals(measurement.size());
        for (uint j = 0; j < measurement.size(); j++) {
            residuals.data.at(j) = measurement.at(j) - this->at(gt_data.at(j));
        }

        // calculating S
        S = 0;
        for (uint j = 0; j < residuals.size; j++) {
            S += residuals.data.at(j) * residuals.data.at(j);
        }

        Matrix<double> jacobian = this->Jacobian(degree, gt_data);

        Matrix<double> I = Matrix<double>::Identity(jacobian.cols);

        Matrix<double> JtJ = jacobian.transpose() * jacobian;
        Matrix<double> JtJ_reg = JtJ + I * bk;

        Matrix<double> inv = JtJ_reg.inverse();

        Vector<double> delta_params = inv * jacobian.transpose() * residuals * ak;
        this->parameters = this->parameters + delta_params;
        double S_new = 0;
        for (uint j = 0; j < measurement.size(); j++) {
            double new_residual = measurement.at(j) - this->at(gt_data.at(j));
            S_new += new_residual * new_residual;
        }

        if (S_new < S) {
            bk /= 10; // Reduce damping factor
        } else {
            bk *= 10; // Increase damping factor
        }
        printf("%f \n", S);
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
