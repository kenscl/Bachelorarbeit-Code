#include "sun_sensor.h"
#include "../math/matlib.h"
#include <cstdint>
#include <cstdio>
#include <fstream>
#include "sun_sensor.h"
#include "../math/matlib.h"
#include "../black_body.h"
#include "../misc.h"
#include "ADPD2140.h"

ADPD2140::ADPD2140(Vector_3D position, Matrix_3D dcm_BN){
    this->position = position;
    this->dcm_BN = dcm_BN;
    double to_mm = 1. / 1000; // to mm

    Vector_3D ls_origen_B(0,0,0);
    Vector_3D ls_origen_G;
    ls_origen_G = dcm_BN * ls_origen_B + position;

    std::vector<Plane> light_source_vector;
    Plane ls_plane(ls_origen_G, dcm_BN, 1 * to_mm, 1.5 * to_mm);
    light_source_vector.push_back(ls_plane);
    this->light_source_vector = light_source_vector;

    // Diodes
    // Define position in sensor frame and then shift to global frame
    Vector_3D diode1_pos_G;
    Vector_3D diode1_pos_B(- 0.5, 0.75, 0);
    diode1_pos_B = diode1_pos_B * to_mm;
    diode1_pos_G = position + dcm_BN * diode1_pos_B;

    Vector_3D diode2_pos_G;
    Vector_3D diode2_pos_B(0.5, 0.75, 0);
    diode2_pos_B = diode2_pos_B * to_mm;
    diode2_pos_G = position + dcm_BN * diode2_pos_B;

    Vector_3D diode3_pos_G;
    Vector_3D diode3_pos_B(-0.5, -0.75, 0);
    diode3_pos_B = diode3_pos_B * to_mm;
    diode3_pos_G = position + dcm_BN * diode3_pos_B;

    Vector_3D diode4_pos_G;
    Vector_3D diode4_pos_B(0.5, -0.75, 0);
    diode4_pos_B = diode4_pos_B * to_mm;
    diode4_pos_G = position + dcm_BN * diode4_pos_B;

    Plane diode1(diode1_pos_G, dcm_BN, 0.5 * to_mm, 0.75 * to_mm); 
    Plane diode2(diode2_pos_G, dcm_BN, 0.5 * to_mm, 0.75 * to_mm); 
    Plane diode3(diode3_pos_G, dcm_BN, 0.5 * to_mm, 0.75 * to_mm); 
    Plane diode4(diode4_pos_G, dcm_BN, 0.5 * to_mm, 0.75 * to_mm); 
    this->diodes.push_back(diode1);
    this->diodes.push_back(diode2);
    this->diodes.push_back(diode3);
    this->diodes.push_back(diode4);

    //slit
    double width = 0.5 * to_mm;
    double hight = 0.5 * to_mm;
    Vector_3D slit_B(0,0, hight);
    Vector_3D slit_G;
    slit_G = dcm_BN * slit_B + position;

    this->slits_top.push_back(Plane(slit_G, dcm_BN, width, 1 * width, 1.52));

    slit_B = Vector_3D(0,0, hight - 0.000000000001);
    slit_G = dcm_BN * slit_B + position;

    this->slits_bottom.push_back(Plane(slit_G, dcm_BN, width, 1 * width, 0.66));



    this->read_rvw("../sun_sensor/ADPD2140_responsivity");
    this->read_radiant_sensitivity("../sun_sensor/ADPD2140_radiant_sensitivity");
}

