#include <cstdio>
#include <vector>
#include "math/matlib.h"
#include "sun_sensor.h"
#include "sun_sensor_data_parser.h"

// Plotting includes
#include "polynomial_fit/polynomial_fit.h"
#include "sin_fit/sin_fit.h"
#include "lut/lut.h"
#include "matplotlibcpp.h"
#include "sin_fit/extended_sin_fit.h"
#include "sin_fit/extended_sin_fit_alt.h"
#include "lut/c-spline.h"
#include "lut/b-spline.h"

//testing 

#include "test/test.h"

namespace plt = matplotlibcpp;


std::vector<double> filter(std::vector<double> data, int num_points){
    std::vector<double> ret;
    for (int i = 0; i < data.size(); ++i) {
        if (i % (int) (data.size() / (num_points - 1)) == 0) {
            ret.push_back(data.at(i));
        }
    }
    return ret;
}

int main () {

    std::vector<std::vector<double>> data, data_valid;
    data = parse_csv("../../Sunsensor_Data/28.08.2021 17.20.54 ADPD2140_X.txt");
    std::vector<double> stage_angle = data.at(0);
    std::vector<double> X = data.at(1);
    std::vector<double> Y = data.at(2);

    std::vector<double> pf_cor;
    std::vector<double> sf_cor;
    std::vector<double> ef_cor;
    std::vector<double> ef_alt_cor;
    std::vector<double> lut_cor;

    data_valid = parse_csv("../../Sunsensor_Data/repetitions/01.12.2021 18.29.27 ADPD2140_X.txt");
    std::vector<double> stage_angle_valid = data_valid.at(0);
    std::vector<double> X_valid = data_valid.at(1);
    std::vector<double> Y_valid = data_valid.at(2);

    //polyfit_test(stage_angle, X, stage_angle_valid, X_valid);
    //sin_fit_test(stage_angle, X, stage_angle_valid, X_valid);
    //e_sin_fit_test(stage_angle, X, stage_angle_valid, X_valid);
    //alt_sin_fit_test(stage_angle, X, stage_angle_valid, X_valid);
    lut_test(stage_angle, X, stage_angle_valid, X_valid);
    //cspline_test(stage_angle, X, stage_angle_valid, X_valid);
    //bspline_test(stage_angle, X, stage_angle_valid, X_valid);


    Polynomial_Fit pf(10, stage_angle, X);
    pf_cor = pf.calc(X);

    Sin_Fit sf(3, 5000, 1e-9, stage_angle, X);
    sf_cor = sf.calc(X, 1e-3);
    for (int i = 0; i < sf.parameters.size; i++) {
        printf("sf parameters: %f \n", sf.parameters.data.at(i));
    }

    Extended_sin_fit ef(5000, 1e-6, stage_angle, X);
    ef_cor = ef.calc(X, 1e-3);
    printf("esf parameters: %f %f %f %f %f \n", ef.parameters.data.at(0), ef.parameters.data.at(1), ef.parameters.data.at(2), ef.parameters.data.at(3), ef.parameters.data.at(4));

    Alt_sin_fit ef_alt(5000, 1e-6, stage_angle, X);
    ef_alt_cor = ef_alt.calc(X, 1e-3);
    printf("esf_alt parameters: %f %f %f %f %f %f \n", ef_alt.parameters.data.at(0), ef_alt.parameters.data.at(1), ef_alt.parameters.data.at(2), ef_alt.parameters.data.at(3), ef_alt.parameters.data.at(4), ef_alt.parameters.data.at(5));

    LUT lut(stage_angle, X, 100);
    lut_cor = lut.calc(X);

    BSpline bs(stage_angle, X, 100);
    std::vector<double> bspline = bs.calc(X);

    CSpline cs(stage_angle, X, 50);
    std::vector<double> spline, spline_error, spline_coeffs_x;
    spline = cs.calc(X);

    for (int i = 0; i < stage_angle.size(); i++) {
        spline_error.push_back(cs.get_value(stage_angle.at(i)));
    }
    for (int i = 0; i < cs.coefficients.size(); i++) {
        spline_coeffs_x.push_back(cs.coefficients.at(i).at(0));
        //printf("cs.y: %f \n", cs.y.at(i));
    }

    convert_to_deg(stage_angle);
    convert_to_deg(X);
    convert_to_deg(Y);
    convert_to_deg(pf_cor);
    convert_to_deg(sf_cor);
    convert_to_deg(ef_cor);
    convert_to_deg(ef_alt_cor);
    convert_to_deg(lut_cor);
    convert_to_deg(spline);
    convert_to_deg(bspline);


    printf("Polyfit rmse: %f [deg]\n", rmse(pf_cor, stage_angle));
    printf("Sinfit rmse: %f [deg]\n", rmse(sf_cor, stage_angle));
    printf("Extended sinfit rmse: %f [deg]\n", rmse(ef_cor, stage_angle));
    printf("Extended sinfit alt rmse: %f [deg]\n", rmse(ef_alt_cor, stage_angle));
    printf("LUT rmse: %f [deg]\n", rmse(lut_cor, stage_angle));
    printf("Spline rmse: %f [deg]\n", rmse(spline, stage_angle));
    printf("BSpline rmse: %f [deg]\n", rmse(bspline, stage_angle));

    //printf("Polyfit rmse 45: %f [deg]\n", rmse_45(pf_cor, stage_angle));
    //printf("Sinfit rmse 45: %f [deg]\n", rmse_45(sf_cor, stage_angle));
    //printf("Extended sinfit rmse 45: %f [deg]\n", rmse_45(ef_cor, stage_angle));
    //printf("Extended sinfit alt rmse 45: %f [deg]\n", rmse_45(ef_alt_cor, stage_angle));
    //printf("LUT rmse 45: %f [deg]\n", rmse_45(lut_cor, stage_angle));
    //printf("Spline rmse 45: %f [deg]\n", rmse_45(spline, stage_angle));
    //printf("BSpline rmse 45: %f [deg]\n", rmse_45(bspline, stage_angle));

    //std::vector<double> error;
    //for(int i = 0; i < stage_angle.size(); i++) {
    //    error.push_back(stage_angle.at(i) - X.at(i));
    //}


    //plt::named_plot("gt", stage_angle, stage_angle);
    //plt::named_plot("X", stage_angle, X);
    //plt::named_plot("Y", stage_angle, Y);
    //plt::named_plot("polynomial fit", stage_angle, pf_cor);
    //plt::named_plot("sin fit", stage_angle, sf_cor);
    //plt::named_plot("extended sin fit", stage_angle, ef_cor);
    ////plt::named_plot("error", stage_angle, error);
    //plt::named_plot("extended sin fit alt", stage_angle, ef_alt_cor);
    //plt::named_plot("lut", stage_angle, lut_cor);

    //plt::named_plot("bspline", stage_angle, bspline);

    //plt::named_plot("cspline", stage_angle, spline);
    //plt::legend();
    //plt::xlabel("INCIDENT LIGHT ANGLE (RAD)");
    //plt::ylabel("ANGULAR RESPONSE (RAD)");
    //plt::show();


}
