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

    double ak = 1;
    double bk = 0;
    Vector<double> params = Vector<double>((int) 2 * degree);
    this->parameters = params;
    for (int i = 0; i < params.size; i++) {
        this->parameters.data.at(i) = 1;
    } 

    /*
     * 1. Inital guess
     * 2. calculate the residuals
     * 3. S = sum r^2
     */

    for (int i = 0; i < steps; i++) {
        // calculating the residuals
        std::vector<double> residuals = std::vector<double>(measurement.size());
        for (uint j = 0; j < measurement.size(); j++) {
            residuals.at(j) = measurement.at(j) - this->at(gt_data.at(j));
        }
        // calculating S
        double S = 0;
        for (uint j = 0; j < residuals.size(); j++) {
            S += residuals.at(j) * residuals.at(j);
        }

        //calculationg Jacobian
        Matrix<double> jacobian = this->Jacobian(degree, gt_data, measurement);
        Matrix<double> I = Matrix<double>::Identity(jacobian.cols);
        Matrix<double> inv_pre((jacobian.transpose() * jacobian + I * bk));

        //we usue moore penrose inversion as the matrix is often singular
        Matrix<double> inv = inv_pre.moore_penrose();

        jacobian.print();
        (inv * jacobian.transpose()).print();
        printf("hre \n");
        this->parameters = this->parameters - inv * jacobian.transpose() * this->parameters * ak;
    }


}

double Sin_Fit::at(double x) {
    double sum = 0;
    for (int i = 0; i < this->degree; i+=2) { 
        sum += this->parameters.data.at(i) * sin (this->parameters.data.at(i+1) * x);
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
