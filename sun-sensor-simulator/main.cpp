#include <cstdio>
#include <vector>
#include "sun_sensor.h"
#include "polynomial_fit/polynomial_fit.h"
#include "sin_fit/sin_fit.h"
#include "lut/lut.h"
#include "matplotlibcpp.h"


namespace plt = matplotlibcpp;
int main () {
    std::vector<double> res_v1;
    std::vector<double> res_v2;
    std::vector<double> res_v3;
    std::vector<double> x;
    std::vector<double> ref;
    Sun_Sensor ss;
    for (double i = - 60 * D2R; i < 60 * D2R; i += 1 * D2R) {
        res_v3.push_back(ss.generate_response_v3(i, i).x );
        printf("%f %f \n", i, ss.generate_response_v3(i, i).x);
        ref.push_back(i);
        x.push_back(i);
    }

    std::vector<double> pf_cor;
    std::vector<double> sf_cor;
    std::vector<double> lut_cor;

    Polynomial_Fit pf(7, ref, res_v3);
    pf_cor = pf.calc(res_v3);

    Sin_Fit sf(3, 5000, 1e-6, ref, res_v3);
    sf_cor = sf.calc(res_v3, 1e-3);

    LUT lut(ref, res_v3);
    lut_cor = lut.calc(res_v3);
    
    for ( int i = 0; i < pf_cor.size(); ++i) {
        printf("%f %f \n", pf_cor.at(i), ref.at(i));
    }

    printf("Polyfit rmse: %f \n", rmse(pf_cor, ref));
    printf("Sinfit rmse: %f \n", rmse(sf_cor, ref));
    printf("LUT rmse: %f \n", rmse(lut_cor, ref));

    plt::named_plot("gt", x, ref);
    plt::named_plot("polynomial fit", x, pf_cor);
    plt::named_plot("sin fit", x, sf_cor);
    plt::named_plot("LUT", x, lut_cor);
    //plt::named_plot("1. sin (x) term", x, res_v1);
    //plt::named_plot("3. sine (x) terms", x, res_v2);
    plt::named_plot("6. sine (x) terms", x, res_v3);
    plt::legend();
    plt::xlabel("INCIDENT LIGHT ANGLE (Degrees)");
    plt::ylabel("ANGULAR RESPONSE (Ratio)");
    plt::show();

}
