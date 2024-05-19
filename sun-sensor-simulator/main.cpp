#include "sun_sensor/sun_sensor.h"
#include "sun_sensor/ADPD2140.h"
#include "math/matlib.h"
#include "black_body.h"
#include "misc.h"
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;
int main(){
    Vector_3D position(0,0,0);
    Matrix_3D dcm_BN;
    dcm_BN = dcm_BN.I();

    ADPD2140 adpd(position, dcm_BN);
        
    black_body bb;
    bb.particle_enegery = 1;
    bb.glass_planes = adpd.slits_top;
    bb.wavelength_max = 850;
    bb.wavelength_min = 850;
    std::vector<double> x_v, y_v, st;
    double x = - 60;
    double d = 5;

    while (x <= 60){
        bb.position = Vector_3D (0,0,5);
        adpd.slits_top.at(0).set_light_source_relative_postion_at_angle(&bb, x / 57.2, 0);

        std::vector<double> currents = adpd.simulate(&bb, 5000);
        x_v.push_back(atan (bb.position.x / bb.position.z) * 57.2);
        double y_l = currents.at(0) + currents.at(2);
        double y_r = currents.at(1) + currents.at(3);
        y_v.push_back(((y_l - y_r) / (y_l + y_r)) );
        st.push_back((currents.at(0)+ currents.at(1) + currents.at(2) +currents.at(3)) / 400);
        x += 0.5;
    }
    plt::scatter(x_v, y_v);
    plt::scatter(x_v, st);
    plt::xlabel("INCIDENT LIGHT ANGLE (Degrees)");
    plt::ylabel("ANGULAR RESPONSE (Ratio)");
    plt::show();
}

