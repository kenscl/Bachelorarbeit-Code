#include <cstdio>
#include <vector>
#include "sun_sensor.h"
#include "polynomial_fit/polynomial_fit.h"
#include "sin_fit/sin_fit.h"
#include "lut/lut.h"
#include "sun_sensor_data_parser.h"
#include "matplotlibcpp.h"


namespace plt = matplotlibcpp;

int main () {

    std::vector<std::vector<double>> data;
    data = parse_csv("../Sunsensor_Data/28.08.2021 17.20.54 ADPD2140_X.txt");
    std::vector<double> stage_angle = data.at(0);
    std::vector<double> X = data.at(1);
    std::vector<double> Y = data.at(2);

    //std::vector<double> pf_cor;
    //std::vector<double> sf_cor;
    //std::vector<double> lut_cor;

    //Polynomial_Fit pf(7, ref, res_v3);
    //pf_cor = pf.calc(res_v3);

    //Sin_Fit sf(2, 5000, 1e-6, ref, res_v3);
    //sf_cor = sf.calc(res_v3, 1e-3);

    //LUT lut(ref, res_v3);
    //lut_cor = lut.calc(res_v3);
    //
    //for ( int i = 0; i < pf_cor.size(); ++i) {
    //    printf("%f %f \n", pf_cor.at(i), ref.at(i));
    //}

    //printf("Polyfit rmse: %f \n", rmse(pf_cor, ref));
    //printf("Sinfit rmse: %f \n", rmse(sf_cor, ref));
    //printf("LUT rmse: %f \n", rmse(lut_cor, ref));

    plt::named_plot("gt", stage_angle, stage_angle);
    plt::named_plot("X", stage_angle, X);
    plt::named_plot("Y", stage_angle, Y);
    //plt::named_plot("polynomial fit", x, pf_cor);
    //plt::named_plot("sin fit", x, sf_cor);
    //plt::named_plot("LUT", x, lut_cor);
    plt::legend();
    plt::xlabel("INCIDENT LIGHT ANGLE (RAD)");
    plt::ylabel("ANGULAR RESPONSE (RAD)");
    plt::show();

}
