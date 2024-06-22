#ifndef __TEST 
#define __TEST

#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

#include "../polynomial_fit/polynomial_fit.h"
#include "../sin_fit/sin_fit.h"
#include "../sin_fit/extended_sin_fit.h"
#include "../sin_fit/extended_sin_fit_alt.h"
#include "../lut/lut.h"
#include "../lut/c-spline.h"
#include "../lut/b-spline.h"



#include <chrono>
namespace timer = std::chrono;
#include <vector>

void polyfit_test(std::vector<double> gt_calib, std::vector<double> measurement_calib, std::vector<double> gt_valid, std::vector<double> measurement_valid);
void sin_fit_test(std::vector<double> gt_calib, std::vector<double> measurement_calib, std::vector<double> gt_valid, std::vector<double> measurement_valid);
void e_sin_fit_test(std::vector<double> gt_calib, std::vector<double> measurement_calib, std::vector<double> gt_valid, std::vector<double> measurement_valid);
void alt_sin_fit_test(std::vector<double> gt_calib, std::vector<double> measurement_calib, std::vector<double> gt_valid, std::vector<double> measurement_valid);
void lut_test(std::vector<double> gt_calib, std::vector<double> measurement_calib, std::vector<double> gt_valid, std::vector<double> measurement_valid);
void cspline_test(std::vector<double> gt_calib, std::vector<double> measurement_calib, std::vector<double> gt_valid, std::vector<double> measurement_valid);
void bspline_test(std::vector<double> gt_calib, std::vector<double> measurement_calib, std::vector<double> gt_valid, std::vector<double> measurement_valid);

#endif
