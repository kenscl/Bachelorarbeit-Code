#ifndef __SIN_FIT
#define __SIN_FIT
#include "../math/matlib.h"
#include <vector>

class Sin_Fit {
    public:
        int64_t degree;
        Vector<double> parameters;

    private:
        Matrix<double> Jacobian(int64_t degree, std::vector<double> gt_data, std::vector<double> measurement);

    public:
        /*
         * Constructor, generates the sin fit.
         * gt_data is the actual data
         * measurement is the measurement
         * degree is the number of terms in the sine, so degree = 2 would be b_1 * sin (g_1 * x) + b_2 * sin (g_2 * x) 
         * see: https://de.wikipedia.org/wiki/Levenberg-Marquardt-Algorithmus, minimisaton happens at the origin
         */
        Sin_Fit(int64_t degree, int64_t steps, std::vector<double> gt_data, std::vector<double> measurement);
        /*
         * evaluate the polynomial at a certain point
         */
        double at(double x);
        /*
         * returns the values in x evaluated by at(double x);
         */
        std::vector<double> calc(std::vector<double> x);
};
#endif
