#include "lut.h"
#include <cstdio>

LUT::LUT(std::vector<double> gt_data, std::vector<double> measurement, int num_points) {
    if (gt_data.size() != measurement.size()) {
        throw std::logic_error("datasets must be the same size for LUT");
    }
    std::vector<double> correction_data;
    std::vector<double> meas;
    for (int i = 0; i < gt_data.size(); ++i) {
        if (i % int (measurement.size() / (num_points-1)) == 0) {
            correction_data.push_back(gt_data.at(i) - measurement.at(i));
            meas.push_back(measurement.at(i));
        }
    }
    this->parameters = correction_data;
    this->measurement = meas;
    printf("number of stored points: %zu with %lu bytes\n", this->parameters.size(), this->parameters.size() * sizeof(double));
}

double LUT::at(double x) {
    int left = 0;
    int right = this->measurement.size() - 1;
    double largest_left = -100;
    double smalles_right= 100;

    // Finding the left and right indices
    for (int i = 0; i < this->measurement.size(); ++i) {
       if (this->measurement.at(i) <= x && this->measurement.at(i) > largest_left) {
            left = i;
       } 
       if (this->measurement.at(i) >= x && this->measurement.at(i) < smalles_right) {
            right = i;
            break; 
       }
    }

    double d = this->measurement.at(right) - this->measurement.at(left);
    if (d == 0 ) {
        return x + this->parameters.at(left);
    }
    // linear interpolation 
    double correction = this->parameters.at(right) * abs(x - this->measurement.at(right)) / d + this->parameters.at(left) * abs(this->measurement.at(left) - x) / d;
    double value = x + correction;
    return value;
}

std::vector<double> LUT::calc(std::vector<double> x) {
    std::vector<double> ret;
    for (uint i = 0; i < x.size(); i++) {
        ret.push_back(this->at(x.at(i)));
    }
    return ret;
}
