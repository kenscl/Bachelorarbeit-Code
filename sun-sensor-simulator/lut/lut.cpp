#include "lut.h"
#include <cstdio>

LUT::LUT(std::vector<double> gt_data, std::vector<double> measurement) {
    if (gt_data.size() != measurement.size()) {
        throw std::logic_error("datasets must be the same size for LUT");
    }
    std::vector<double> correction_data;
    for (int i = 0; i < gt_data.size(); ++i) {
        correction_data.push_back(gt_data.at(i) - measurement.at(i));
        printf("gt: %f, measurement: %f, correction: %f \n", gt_data.at(i), measurement.at(i), correction_data.at(i));
    }
    this->parameters = correction_data;
    this->measurement = measurement;
    printf("number of stored points: %zu with %lu bytes\n", this->parameters.size(), this->parameters.size() * sizeof(double));
}

double LUT::at(double x) {
    int left = 0;
    int right = this->measurement.size() - 1;

    // Finding the left and right indices
    for (int i = 0; i < this->measurement.size(); ++i) {
       if (this->measurement.at(i) <= x) {
            left = i;
       } 
       if (this->measurement.at(i) >= x) {
            right = i;
            break; 
       }
    }

    double d = this->measurement.at(right) - this->measurement.at(left);
    if (d == 0 ) {
        return x + this->parameters.at(left);
    }
    // linear interpolation 
    double value = this->parameters.at(left) + (x - this->measurement.at(left)) * (this->parameters.at(right) - this->parameters.at(left)) / d;
    return value;
}

std::vector<double> LUT::calc(std::vector<double> x) {
    std::vector<double> ret;
    for (uint i = 0; i < x.size(); i++) {
        ret.push_back(this->at(x.at(i)));
    }
    return ret;
}
