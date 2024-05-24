#include <cstdio>
#include <vector>
#include "sun_sensor.h"
#include "polynomial_fit/polynomial_fit.h"
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;
int main () {
    //std::vector<double> res_v1;
    //std::vector<double> res_v2;
    std::vector<double> res_v3;
    std::vector<double> x;
    std::vector<double> ref;
    Sun_Sensor ss;
    for (double i = - 60; i < 60; i += 0.1) {
        //res_v1.push_back(ss.generate_response_v1(i, i).x /0.00631 );
        //res_v2.push_back(ss.generate_response_v2(i, i).x /0.00631 );
        res_v3.push_back(ss.generate_response_v3(i, i).x /0.00631 );
        printf("%f %f \n", i, ss.generate_response_v3(i, i).x/0.00631);
        ref.push_back(i);
        x.push_back(i);
    }
    std::vector<double> pf_res;
    std::vector<double> pf_cor;
    Polynomial_Fit pf(5, ref, res_v3);
    pf_res = pf.calc(ref);
    pf_cor = pf.calc(res_v3);

    plt::named_plot("gt", x, ref);
    plt::named_plot("polfit", x, pf_res);
    plt::named_plot("polfit_cor", x, pf_cor);
    //plt::named_plot("1. sin (x) term", x, res_v1);
    //plt::named_plot("3. sine (x) terms", x, res_v2);
    plt::named_plot("6. sine (x) terms", x, res_v3);
    plt::legend();
    plt::xlabel("INCIDENT LIGHT ANGLE (Degrees)");
    plt::ylabel("ANGULAR RESPONSE (Ratio)");
    plt::show();

}
