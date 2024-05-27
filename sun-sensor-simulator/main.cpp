#include <cstdio>
#include <vector>
#include "sun_sensor.h"
#include "polynomial_fit/polynomial_fit.h"
#include "sin_fit/sin_fit.h"
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;
int main () {
    //Matrix<double> A(3,3);
    //A.data[0][0] = 1;
    //A.data[0][1] = 2;
    //A.data[0][2] = 2;

    //A.data[1][0] = 2;
    //A.data[1][1] = 2;
    //A.data[1][2] = 2;

    //A.data[2][0] = 5;
    //A.data[2][1] = 2;
    //A.data[2][2] = 4;

    //Matrix<double> Q, R;
    //A.QR_decomp(A, Q, R);
    //A.print();
    //Q.print();
    //R.print();
    //(Q * R).print();
    //A.moore_penrose().print();
    std::vector<double> res_v1;
    std::vector<double> res_v2;
    std::vector<double> res_v3;
    std::vector<double> x;
    std::vector<double> ref;
    Sun_Sensor ss;
    for (double i = - 60; i < 60; i += 5) {
        res_v1.push_back(ss.generate_response_v1(i, i).x );
        res_v2.push_back(ss.generate_response_v2(i, i).x );
        res_v3.push_back(ss.generate_response_v3(i, i).x );
        printf("%f %f \n", i, ss.generate_response_v3(i, i).x);
        ref.push_back(i * 0.00631);
        x.push_back(i * 0.00631);
    }

    std::vector<double> pf_res;
    std::vector<double> pf_cor;
    //Polynomial_Fit pf(7, ref, res_v3);
    //pf_cor = pf.calc(res_v3);
    Sin_Fit sf(1, 9, x, res_v3);
    pf_cor = sf.calc(res_v3);
    pf_res = sf.calc(ref);
    sf.parameters.print();

    plt::named_plot("gt", x, ref);
    plt::named_plot("polfit", x, pf_res);
    plt::named_plot("polfit_cor", x, pf_cor);
    plt::named_plot("1. sin (x) term", x, res_v1);
    //plt::named_plot("3. sine (x) terms", x, res_v2);
    //plt::named_plot("6. sine (x) terms", x, res_v3);
    plt::legend();
    plt::xlabel("INCIDENT LIGHT ANGLE (Degrees)");
    plt::ylabel("ANGULAR RESPONSE (Ratio)");
    plt::show();

}
