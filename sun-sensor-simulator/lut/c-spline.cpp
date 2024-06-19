#include "c-spline.h"
#include <cstdio>
#include <vector>

CSpline::CSpline(std::vector<double> gt_data, std::vector<double> measurement, int num_points) {
    std::vector<double> x, y;

    for (int i = 0; i < gt_data.size(); ++i) {
        if (i % int (measurement.size() / (num_points-1)) == 0) {
            y.push_back(gt_data.at(i) - measurement.at(i));
            x.push_back(gt_data.at(i));
        }
    }
    this->coefficients = generate_coefficients(x, y);
}


std::vector<std::vector<double>> CSpline::generate_coefficients(std::vector<double> x, std::vector<double> y) {
    // caclulate h
    std::vector<double> h;
    for (int i = 0; i < x.size() - 1; ++i) {
        h.push_back(x.at(i+1) - x.at(i));
    }
    // generate matrix A
    Matrix<double> A(x.size(), x.size());
    A.data[0][0] = 1;
    A.data[x.size() - 1][x.size() - 1] = 1;

    for (int i = 1; i < x.size() - 1; ++i) {
        A.data[i][i-1] = h.at(i-1);
        A.data[i][i] = 2 * (h.at(i-1) + h.at(i));
        A.data[i][i+1] = h.at(i);
    }

    // generate vector
    Vector<double> b(x.size());
    b.data[0] = 0;
    b.data[x.size() - 1] = 0;
    for (uint i = 1; i < b.size - 1; ++i) {
        b.data[i] = 3 / h.at(i) * (y.at(i+1) - y.at(i)) - 3 / h.at(i-1) * (y.at(i) - y.at(i-1));
    }

    // Thomas algorithm for solving A * c = b
    Vector<double> c_prime(x.size()), d_prime(x.size());
    d_prime.data[0] = b.data[0];
    c_prime.data[0] = A.data[0][1] / A.data[0][0];
    for (uint i = 1; i < b.size ; ++i) {
        c_prime.data[i] = A.data[i][i+1]/ (A.data[i][i] - b.data[i-1] * A.data[i][i-1]);
    }
    d_prime.data[0] = b.data[0] / A.data[0][0];
    for (uint i = 1; i < b.size ; ++i) {
        d_prime.data[i] = (b.data[i] - d_prime.data[i-1] * A.data[i][i-1]) / (A.data[i][i] - c_prime.data[i-1] * A.data[i][i-1]);
    }

    Vector<double> c(x.size());
    c.data[c.size - 1] = 0;
    for (int i = c.size - 2; i >= 0; --i) {
        c.data[i] = d_prime.data[i] - c_prime.data[i] * c.data[i+1];
    }

    // generate coefficients
    Vector<double> a(x.size()), b_vec(x.size()), d(x.size());
    for (int i = 0; i < x.size(); ++i) {
        a.data[i] = y [i];
    }

    for ( int i = 0; i < x.size() - 1; ++i) {
        b_vec.data[i] = 1 / h.at(i) * (a.data[i+1] - a.data[i]) - h.at(i) / 3 * (2 * c.data[i] + c.data[i+1]); 
        d.data[i] = (c.data[i+1] - c.data[i]) / (3 * h.at(i));
    }

    std::vector<std::vector<double>> coefficients;
    for (uint i = 0; i < x.size(); ++i) {
        std::vector<double> temp;
        temp.push_back(x.at(i));
        temp.push_back(a.data[i]);
        temp.push_back(b_vec.data[i]);
        temp.push_back(c.data[i]);
        temp.push_back(d.data[i]);
        coefficients.push_back(temp);
    }
    return coefficients;
}


double CSpline::get_value(double x) {
    for (uint i = 0; i < this->coefficients.size() - 1 ; ++i) {
        if (x >= this->coefficients.at(i).at(0) && x <= this->coefficients.at(i+1).at(0)) {
            double x_i = this->coefficients.at(i).at(0);
            double a = this->coefficients.at(i).at(1);
            double b = this->coefficients.at(i).at(2);
            double c = this->coefficients.at(i).at(3);
            double d = this->coefficients.at(i).at(4);
            return a + b * (x - x_i) + c * (x - x_i) * (x - x_i) + d * (x - x_i) * (x - x_i) * (x - x_i);
        }
    }
    double x_i = this->coefficients.at(this->coefficients.size() - 1).at(0);
    double a = this->coefficients.at(this->coefficients.size() - 1).at(1);
    double b = this->coefficients.at(this->coefficients.size() - 1).at(2);
    double c = this->coefficients.at(this->coefficients.size() - 1).at(3);
    double d = this->coefficients.at(this->coefficients.size() - 1).at(4);
    return a + b * (x - x_i) + c * (x - x_i) * (x - x_i) + d * (x - x_i) * (x - x_i) * (x - x_i);

    return 0;
}

std::vector<double> CSpline::get_value(std::vector<double> x) {
std::vector<double> ret;
    for (uint i = 0; i < x.size(); ++i) {
        ret.push_back(this->get_value(x.at(i)));
    }
    return ret;
}

double CSpline::at(double x) {
    return x + this->get_value(x);
}

std::vector<double> CSpline::calc(std::vector<double> x) {
    std::vector<double> ret;
    for (uint i = 0; i < x.size(); i++) {
        ret.push_back(this->at(x.at(i)));
    }
    return ret;
}
