#include <cstdio>
#include <vector>
#include "sun_sensor.h"
#include "sun_sensor_data_parser.h"

// Plotting includes
#include "polynomial_fit/polynomial_fit.h"
#include "sin_fit/sin_fit.h"
#include "lut/lut.h"
#include "matplotlibcpp.h"
#include "sin_fit/extended_sin_fit.h"
#include "sin_fit/extended_sin_fit_alt.h"

namespace plt = matplotlibcpp;

int main () {

    std::vector<std::vector<double>> data;
    data = parse_csv("../../Sunsensor_Data/28.08.2021 17.20.54 ADPD2140_X.txt");
    std::vector<double> stage_angle = data.at(0);
    std::vector<double> X = data.at(1);
    std::vector<double> Y = data.at(2);

    std::vector<double> pf_cor;
    std::vector<double> sf_cor;
    std::vector<double> ef_cor;
    std::vector<double> ef_alt_cor;
    std::vector<double> lut_cor;

    Polynomial_Fit pf(5, stage_angle, X);
    pf_cor = pf.calc(stage_angle);

    Sin_Fit sf(2, 5000, 1e-6, stage_angle, X);
    sf_cor = sf.calc(X, 1e-3);

    Extended_sin_fit ef(5000, 1e-6, stage_angle, X);
    ef_cor = ef.calc(X, 1e-3);
    printf("esf parameters: %f %f %f %f %f \n", ef.parameters.data.at(0), ef.parameters.data.at(1), ef.parameters.data.at(2), ef.parameters.data.at(3), ef.parameters.data.at(4));

    Alt_sin_fit ef_alt(5000, 1e-6, stage_angle, X);
    ef_alt_cor = ef_alt.calc(X, 1e-3);
    printf("esf_alt parameters: %f %f %f %f %f %f \n", ef_alt.parameters.data.at(0), ef_alt.parameters.data.at(1), ef_alt.parameters.data.at(2), ef_alt.parameters.data.at(3), ef_alt.parameters.data.at(4), ef_alt.parameters.data.at(5));

    LUT lut(stage_angle, X);
    lut_cor = lut.calc(X);

    printf("Polyfit rmse: %f \n", rmse(pf_cor, stage_angle));
    printf("Sinfit rmse: %f \n", rmse(sf_cor, stage_angle));
    printf("Extended sinfit rmse: %f \n", rmse(ef_cor, stage_angle));
    printf("Extended sinfit alt rmse: %f \n", rmse(ef_alt_cor, stage_angle));
    printf("LUT rmse: %f \n", rmse(lut_cor, stage_angle));

    plt::named_plot("gt", stage_angle, stage_angle);
    plt::named_plot("X", stage_angle, X);
    plt::named_plot("Y", stage_angle, Y);
    //plt::named_plot("polynomial fit", stage_angle, pf_cor);
    //plt::named_plot("sin fit", stage_angle, sf_cor);
    //plt::named_plot("extended sin fit", stage_angle, ef_cor);
    //plt::named_plot("extended sin fit alt", stage_angle, ef_alt_cor);
    plt::named_plot("LUT", stage_angle, lut_cor);
    plt::legend();
    plt::xlabel("INCIDENT LIGHT ANGLE (RAD)");
    plt::ylabel("ANGULAR RESPONSE (RAD)");
    plt::show();


}
