#include "sun_sensor.h"
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
    bb.glass_planes = adpd.diodes;
    bb.wavelength_max = 850;
    bb.wavelength_min = 850;
   std::vector<double> x_v, y_v;
    double x = - 50;
    double d = 5;

    while (x <= 50){
        bb.position = Vector_3D (0,0,5);
        adpd.slits_top.at(0).set_light_source_relative_postion_at_angle(&bb, x / 57.2, 0);

        std::vector<double> currents = adpd.simulate(&bb, 50);
        x_v.push_back(atan (bb.position.x / bb.position.z) * 57.2);
        y_v.push_back(currents.at(0)+ currents.at(1) + currents.at(2) + currents.at(3));
        x += 1;
    }
    plt::plot(x_v, y_v);
    plt::show();
}

