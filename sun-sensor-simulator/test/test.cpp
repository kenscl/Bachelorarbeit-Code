#include "test.h"
#include "matplotlibcpp.h"
#include <cmath>
#include <vector>


void polyfit_test(std::vector<double> gt_calib, std::vector<double> measurement_calib, std::vector<double> gt_valid, std::vector<double> measurement_valid) {
    std::vector<double> index, error, time, size, meas, meas_err;
    int err_min_index = -1;
    double err_min = MAXFLOAT;

    convert_to_deg(gt_valid);

    for (uint i = 0; i < 17; ++i) {
        Polynomial_Fit polyfit(i, gt_calib, measurement_calib);
        meas = polyfit.calc(measurement_valid);
        convert_to_deg(meas);
        double err = rmse(gt_valid, meas);
        // error
        index.push_back(i);
        error.push_back(err);

        if (err < err_min) {
            err_min = err;
            err_min_index = i;
        }

        // size 
        size.push_back(sizeof(std::vector<double>) + sizeof(double) * polyfit.weights.size());

        // time
        auto start = timer::high_resolution_clock::now();
        for (int j = 0; j < 1000; ++j) {
            polyfit.calc(measurement_valid);
        }

        auto end = timer::high_resolution_clock::now();
        time.push_back(timer::duration_cast<timer::microseconds>(end - start).count() / 1000.0);

        printf("Degree %d, error %f, size %f, time %f\n", i, err, size.back(), time.back());

    }
    printf("Minimum error at degree %d with error %f\n", err_min_index, err_min);

    //error plot
    //plt::figure_size(800, 600);
    plt::title("POLYNOMIAL FIT ERROR BASED ON DEGREE");
    plt::xlabel("DEGREE OF POLYNOMIAL FIT");
    plt::ylabel("RMSE (DEG)");
    plt::grid(true);
    plt::plot(index, error);
    std::string filename = "../plots/Polyfit_Count.png";
    plt::save(filename);

    plt::cla();
    plt::clf();
    plt::title("POLYNOMIAL FIT TIME BASED ON DEGREE");
    plt::xlabel("DEGREE OF POLYNOMIAL FIT");
    plt::ylabel("TIME [µs]");
    plt::grid(true);
    plt::plot(index, time);
    filename = "../plots/Polyfit_time.png";
    plt::save(filename);


    plt::cla();
    plt::clf();
    plt::title("POLYNOMIAL FIT SIZE BASED ON DEGREE");
    plt::xlabel("DEGREE OF POLYNOMIAL FIT");
    plt::ylabel("SIZE IN BYTES");
    plt::grid(true);
    plt::plot(index, size);
    filename = "../plots/Polyfit_size.png";
    plt::save(filename);


    plt::cla();
    plt::clf();


    Polynomial_Fit polyfit(7, gt_calib, measurement_calib);
    meas = polyfit.calc(measurement_valid);
    convert_to_deg(meas);
    for (uint i = 0; i < meas.size(); ++i) {
        meas_err.push_back(gt_valid.at(i) - meas.at(i));
    }

    plt::title("POLYNOMIAL FIT");
    plt::grid(true);
    plt::named_plot("polynomial fit", gt_valid, meas);
    plt::named_plot("error ", gt_valid, meas_err);
    plt::legend();
    plt::xlabel("INCIDENT LIGHT ANGLE [deg]");
    plt::ylabel("ANGULAR RESPONSE [deg]");
    filename = "../plots/Polyfit.png";
    plt::save(filename);


    plt::cla();
    plt::clf();
}



void sin_fit_test(std::vector<double> gt_calib, std::vector<double> measurement_calib, std::vector<double> gt_valid, std::vector<double> measurement_valid) {
    std::vector<double> index, error, time, size, meas, meas_err;
    int err_min_index = -1;
    double err_min = MAXFLOAT;

    convert_to_deg(gt_valid);

    for (uint i = 0; i < 7; ++i) {
        Sin_Fit fit(i, 5000 ,1e-6, gt_calib, measurement_calib);
        meas = fit.calc(measurement_valid, 1e-3);
        convert_to_deg(meas);
        double err = rmse(gt_valid, meas);
        // error
        index.push_back(i);
        error.push_back(err);

        if (err < err_min) {
            err_min = err;
            err_min_index = i;
        }

        // size 
        size.push_back(sizeof(Vector<double>) + sizeof(double) * fit.parameters.size);

        // time
        auto start = timer::high_resolution_clock::now();
        for (int j = 0; j < 1000; ++j) {
            fit.calc(measurement_valid, 1e-3);
        }

        auto end = timer::high_resolution_clock::now();
        time.push_back(timer::duration_cast<timer::microseconds>(end - start).count() / 1000.0);

        printf("Degree %d, error %f, size %f, time %f\n", i, err, size.back(), time.back());

    }
    printf("Minimum error at degree %d with error %f\n", err_min_index, err_min);

    //error plot
    //plt::figure_size(800, 600);
    plt::title("SIN FIT ERROR BASED ON DEGREE");
    plt::xlabel("DEGREE OF SIN FIT");
    plt::ylabel("RMSE (DEG)");
    plt::grid(true);
    plt::plot(index, error);
    std::string filename = "../plots/Sin_fit_Count.png";
    plt::save(filename);

    plt::cla();
    plt::clf();
    plt::title("SIN FIT TIME BASED ON DEGREE");
    plt::xlabel("DEGREE OF SIN FIT");
    plt::ylabel("TIME [µs]");
    plt::grid(true);
    plt::plot(index, time);
    filename = "../plots/Sin_fit_time.png";
    plt::save(filename);


    plt::cla();
    plt::clf();
    plt::title("SIN FIT SIZE BASED ON DEGREE");
    plt::xlabel("DEGREE OF SIN FIT");
    plt::ylabel("SIZE IN BYTES");
    plt::grid(true);
    plt::plot(index, size);
    filename = "../plots/Sin_fit_size.png";
    plt::save(filename);


    plt::cla();
    plt::clf();


    Sin_Fit fit(3, 5000 ,1e-6, gt_calib, measurement_calib);
    meas = fit.calc(measurement_valid, 1e-3);
    convert_to_deg(meas);
    for (uint i = 0; i < meas.size(); ++i) {
        meas_err.push_back(gt_valid.at(i) - meas.at(i));
    }

    plt::title("SIN FIT");
    plt::grid(true);
    plt::named_plot("Sin fit", gt_valid, meas);
    plt::named_plot("error ", gt_valid, meas_err);
    plt::legend();
    plt::xlabel("INCIDENT LIGHT ANGLE [deg]");
    plt::ylabel("ANGULAR RESPONSE [deg]");
    filename = "../plots/Sin_fit.png";
    plt::save(filename);


    plt::cla();
    plt::clf();

}


void e_sin_fit_test(std::vector<double> gt_calib, std::vector<double> measurement_calib, std::vector<double> gt_valid, std::vector<double> measurement_valid) {
    std::vector<double> index, error, time, size, meas, meas_err;

    convert_to_deg(gt_valid);

    Extended_sin_fit fit(5000 ,1e-6, gt_calib, measurement_calib);
    meas = fit.calc(measurement_valid, 1e-3);
    convert_to_deg(meas);
    double err = rmse(gt_valid, meas);



    size.push_back(sizeof(Vector<double>) + sizeof(double) * fit.parameters.size);

    auto start = timer::high_resolution_clock::now();
    for (int j = 0; j < 1000; ++j) {
        fit.calc(measurement_valid, 1e-3);
    }

    auto end = timer::high_resolution_clock::now();
    time.push_back(timer::duration_cast<timer::microseconds>(end - start).count() / 1000.0);

    printf("error %f, size %f, time %f\n", err, size.back(), time.back());

    


    plt::cla();
    plt::clf();


    for (uint i = 0; i < meas.size(); ++i) {
        meas_err.push_back(gt_valid.at(i) - meas.at(i));
    }

    plt::title("MODEL 2");
    plt::grid(true);
    plt::named_plot("fit", gt_valid, meas);
    plt::named_plot("error ", gt_valid, meas_err);
    plt::legend();
    plt::xlabel("INCIDENT LIGHT ANGLE [deg]");
    plt::ylabel("ANGULAR RESPONSE [deg]");
    std::string filename = "../plots/e_Sin_fit.png";
    plt::save(filename);


    plt::cla();
    plt::clf();


}
void alt_sin_fit_test(std::vector<double> gt_calib, std::vector<double> measurement_calib, std::vector<double> gt_valid, std::vector<double> measurement_valid) {
    std::vector<double> index, error, time, size, meas, meas_err;

    convert_to_deg(gt_valid);

    Alt_sin_fit fit(5000 ,1e-6, gt_calib, measurement_calib);
    meas = fit.calc(measurement_valid, 1e-3);
    convert_to_deg(meas);
    double err = rmse(gt_valid, meas);



    size.push_back(sizeof(Vector<double>) + sizeof(double) * fit.parameters.size);

    auto start = timer::high_resolution_clock::now();
    for (int j = 0; j < 1000; ++j) {
        fit.calc(measurement_valid, 1e-3);
    }

    auto end = timer::high_resolution_clock::now();
    time.push_back(timer::duration_cast<timer::microseconds>(end - start).count() / 1000.0);

    printf("error %f, size %f, time %f\n", err, size.back(), time.back());

    


    plt::cla();
    plt::clf();


    for (uint i = 0; i < meas.size(); ++i) {
        meas_err.push_back(gt_valid.at(i) - meas.at(i));
    }

    plt::title("MODEL 3");
    plt::grid(true);
    plt::named_plot("fit", gt_valid, meas);
    plt::named_plot("error ", gt_valid, meas_err);
    plt::legend();
    plt::xlabel("INCIDENT LIGHT ANGLE [deg]");
    plt::ylabel("ANGULAR RESPONSE [deg]");
    std::string filename = "../plots/alt_Sin_fit.png";
    plt::save(filename);


    plt::cla();
    plt::clf();


}


void lut_test(std::vector<double> gt_calib, std::vector<double> measurement_calib, std::vector<double> gt_valid, std::vector<double> measurement_valid) {
    std::vector<double> index, error, time, size, meas, meas_err;
    int err_min_index = -1;
    double err_min = MAXFLOAT;

    convert_to_deg(gt_valid);

    for (uint i = 2; i < 500; i += 10) {
        LUT fit(gt_calib, measurement_calib, i);
        meas = fit.calc(measurement_valid);
        convert_to_deg(meas);
        double err = rmse(gt_valid, meas);
        // error
        index.push_back(i);
        error.push_back(err);

        if (err < err_min) {
            err_min = err;
            err_min_index = i;
        }

        // size 
        size.push_back((sizeof(std::vector<double>) + sizeof(double) * fit.parameters.size()) * 2) ;

        // time
        auto start = timer::high_resolution_clock::now();
        for (int j = 0; j < 1000; ++j) {
            fit.calc(measurement_valid);
        }

        auto end = timer::high_resolution_clock::now();
        time.push_back(timer::duration_cast<timer::microseconds>(end - start).count() / 1000.0);

        printf("Degree %d, error %f, size %f, time %f\n", i, err, size.back(), time.back());

    }
    printf("Minimum error at degree %d with error %f\n", err_min_index, err_min);

    //error plot
    //plt::figure_size(800, 600);
    plt::title("LINEAR INTERPOLATION ERROR BASED ON DEGREE");
    plt::xlabel("DEGREE OF LINEAR INTERPOLATION");
    plt::ylabel("RMSE (DEG)");
    plt::grid(true);
    plt::plot(index, error);
    std::string filename = "../plots/LERP_Count.png";
    plt::save(filename);

    plt::cla();
    plt::clf();
    plt::title("LINEAR INTERPOLATION TIME BASED ON DEGREE");
    plt::xlabel("DEGREE OF LINEAR INTERPOLATION");
    plt::ylabel("TIME [µs]");
    plt::grid(true);
    plt::plot(index, time);
    filename = "../plots/LERP_time.png";
    plt::save(filename);


    plt::cla();
    plt::clf();
    plt::title("LINEAR INTERPOLATION SIZE BASED ON DEGREE");
    plt::xlabel("DEGREE OF LINEAR INTERPOLATION");
    plt::ylabel("SIZE IN BYTES");
    plt::grid(true);
    plt::plot(index, size);
    filename = "../plots/LERP_size.png";
    plt::save(filename);


    plt::cla();
    plt::clf();



    LUT fit(gt_calib, measurement_calib, 50);
    meas = fit.calc(measurement_calib);

    convert_to_deg(meas);
    for (uint i = 0; i < meas.size(); ++i) {
        meas_err.push_back(gt_valid.at(i) - meas.at(i));
    }

    plt::title("LINEAR INTERPOLATION");
    plt::grid(true);
    plt::named_plot("Linear Interpolation", gt_valid, meas);
    plt::named_plot("error ", gt_valid, meas_err);
    plt::legend();
    plt::xlabel("INCIDENT LIGHT ANGLE [deg]");
    plt::ylabel("ANGULAR RESPONSE [deg]");
    filename = "../plots/LERP.png";
    plt::save(filename);


    plt::cla();
    plt::clf();
}


void cspline_test(std::vector<double> gt_calib, std::vector<double> measurement_calib, std::vector<double> gt_valid, std::vector<double> measurement_valid) {
    std::vector<double> index, error, time, size, meas, meas_err;
    int err_min_index = -1;
    double err_min = MAXFLOAT;

    convert_to_deg(gt_valid);

    for (uint i = 4; i < 120; i += 10) {
        CSpline fit(gt_calib, measurement_calib, i);
        meas = fit.calc(measurement_valid);
        convert_to_deg(meas);
        double err = rmse(gt_valid, meas);
        // error
        index.push_back(i);
        error.push_back(err);

        if (err < err_min) {
            err_min = err;
            err_min_index = i;
        }

        // size 
        size.push_back(sizeof(std::vector<double>) + sizeof(double) * fit.y.size() + sizeof(std::vector<std::vector<double>>) * fit.coefficients.size() * 4);

        // time
        auto start = timer::high_resolution_clock::now();
        for (int j = 0; j < 1000; ++j) {
            fit.calc(measurement_valid);
        }

        auto end = timer::high_resolution_clock::now();
        time.push_back(timer::duration_cast<timer::microseconds>(end - start).count() / 1000.0);

        printf("Degree %d, error %f, size %f, time %f\n", i, err, size.back(), time.back());

    }
    printf("Minimum error at degree %d with error %f\n", err_min_index, err_min);

    //error plot
    //plt::figure_size(800, 600);
    plt::title("C-SPLINE ERROR BASED ON DEGREE");
    plt::xlabel("NUMBER OF KNOTS");
    plt::ylabel("RMSE (DEG)");
    plt::grid(true);
    plt::plot(index, error);
    std::string filename = "../plots/CSpline_Count.png";
    plt::save(filename);

    plt::cla();
    plt::clf();
    plt::title("C-SPLINE TIME BASED ON DEGREE");
    plt::xlabel("NUMBER OF KNOTS");
    plt::ylabel("TIME [µs]");
    plt::grid(true);
    plt::plot(index, time);
    filename = "../plots/CSpline_time.png";
    plt::save(filename);


    plt::cla();
    plt::clf();
    plt::title("C-SPLINE SIZE BASED ON DEGREE");
    plt::xlabel("NUMBER OF KNOTS");
    plt::ylabel("SIZE IN BYTES");
    plt::grid(true);
    plt::plot(index, size);
    filename = "../plots/CSpline_size.png";
    plt::save(filename);


    plt::cla();
    plt::clf();



    LUT fit(gt_calib, measurement_calib, 50);
    meas = fit.calc(measurement_calib);

    convert_to_deg(meas);
    for (uint i = 0; i < meas.size(); ++i) {
        meas_err.push_back(gt_valid.at(i) - meas.at(i));
    }

    plt::title("C-SPLINE");
    plt::grid(true);
    plt::named_plot("C-Spline", gt_valid, meas);
    plt::named_plot("error ", gt_valid, meas_err);
    plt::legend();
    plt::xlabel("INCIDENT LIGHT ANGLE [deg]");
    plt::ylabel("ANGULAR RESPONSE [deg]");
    filename = "../plots/CSpline.png";
    plt::save(filename);


    plt::cla();
    plt::clf();
}

void bspline_test(std::vector<double> gt_calib, std::vector<double> measurement_calib, std::vector<double> gt_valid, std::vector<double> measurement_valid) {
    std::vector<double> index, error, time, size, meas, meas_err;
    int err_min_index = -1;
    double err_min = MAXFLOAT;

    convert_to_deg(gt_valid);

    for (uint i = 4; i < 120; i += 10) {
        BSpline fit(gt_calib, measurement_calib, i);
        meas = fit.calc(measurement_valid);
        convert_to_deg(meas);
        double err = rmse(gt_valid, meas);
        // error
        index.push_back(i);
        error.push_back(err);

        if (err < err_min) {
            err_min = err;
            err_min_index = i;
        }

        // size 
        size.push_back(sizeof(std::vector<double>) + sizeof(double) * fit.y.size() * 2);

        // time
        auto start = timer::high_resolution_clock::now();
        for (int j = 0; j < 1000; ++j) {
            fit.calc(measurement_valid);
        }

        auto end = timer::high_resolution_clock::now();
        time.push_back(timer::duration_cast<timer::microseconds>(end - start).count() / 1000.0);

        printf("Degree %d, error %f, size %f, time %f\n", i, err, size.back(), time.back());

    }
    printf("Minimum error at degree %d with error %f\n", err_min_index, err_min);

    //error plot
    //plt::figure_size(800, 600);
    plt::title("B-SPLINE ERROR BASED ON DEGREE");
    plt::xlabel("NUMBER OF KNOTS");
    plt::ylabel("RMSE (DEG)");
    plt::grid(true);
    plt::plot(index, error);
    std::string filename = "../plots/BSpline_Count.png";
    plt::save(filename);

    plt::cla();
    plt::clf();
    plt::title("B-SPLINE TIME BASED ON DEGREE");
    plt::xlabel("NUMBER OF KNOTS");
    plt::ylabel("TIME [µs]");
    plt::grid(true);
    plt::plot(index, time);
    filename = "../plots/BSpline_time.png";
    plt::save(filename);


    plt::cla();
    plt::clf();
    plt::title("B-SPLINE SIZE BASED ON DEGREE");
    plt::xlabel("NUMBER OF KNOTS");
    plt::ylabel("SIZE IN BYTES");
    plt::grid(true);
    plt::plot(index, size);
    filename = "../plots/BSpline_size.png";
    plt::save(filename);


    plt::cla();
    plt::clf();



    LUT fit(gt_calib, measurement_calib, 50);
    meas = fit.calc(measurement_calib);

    convert_to_deg(meas);
    for (uint i = 0; i < meas.size(); ++i) {
        meas_err.push_back(gt_valid.at(i) - meas.at(i));
    }

    plt::title("B-SPLINE");
    plt::grid(true);
    plt::named_plot("C-Spline", gt_valid, meas);
    plt::named_plot("error ", gt_valid, meas_err);
    plt::legend();
    plt::xlabel("INCIDENT LIGHT ANGLE [deg]");
    plt::ylabel("ANGULAR RESPONSE [deg]");
    filename = "../plots/BSpline.png";
    plt::save(filename);


    plt::cla();
    plt::clf();
}
