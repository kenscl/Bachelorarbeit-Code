#include "sun_sensor.h"
#include "math/matlib.h"
#include <cstdint>
#include <cstdio>
#include <fstream>
#include "sun_sensor.h"
#include "math/matlib.h"
#include "black_body.h"
#include "misc.h"

Sun_sensor::Sun_sensor(){}
Sun_sensor::Sun_sensor(Vector_3D position, Matrix_3D dcm_BN, std::vector<Plane> diodes, std::vector<Plane> slits_top, std::vector<Plane> slits_bottom){
    this->position = position;
    this->dcm_BN = dcm_BN;
    this->diodes = diodes;
    this->slits_top = slits_top;
    this->slits_bottom = slits_bottom;
}

double linear_interpolation_rvw(std::vector<rvw_data> data, double value, int len){
    if (data.at(0).wavelength > value) return data.at(0).responsivity;
    for (int i = 0; i < len - 1; i++) {
        if (data.at(i).wavelength == value) return data.at(i).responsivity;
        if (data.at(i).wavelength <= value && data.at(i+1).wavelength > value){
            return lerp(data.at(i).responsivity, data.at(i+1).responsivity, data.at(i).wavelength, data.at(i+1).wavelength, value);
        }
    }
    return data.at(len - 1).responsivity;
}


std::vector<double> Sun_sensor::simulate(light_source * source, uint64_t particle_count){

    /*
     * 1. Propagate the particles to the outside of the glass
     * 2. Propagate the particles to the inside part of the glass
     * 3. Calculate the current if a collision occurs 
     */

    std::vector<double> currents;
    std::vector<Particle> particles;
    std::vector<Particle> to_remove;
    std::vector<Particle>::iterator it;
    std::vector<Plane>::iterator it_diodes;
    double angle_x, angle_y;
    Vector_3D sun_to_sensor;
    sun_to_sensor =  source->position - this->slits_top.at(0).origin;
    this->slits_top.at(0).get_directional_angles(sun_to_sensor, &angle_x, &angle_y);


    particles = source->generate_particles(particle_count * cos(angle_x) * cos (angle_y));

    for (Plane slit : this->slits_top) {
        it = particles.begin();
        while(it != particles.end()) {
            int8_t ret;
            ret = slit.particle_colission(&*it);
            if (ret != 0) {
                particles.erase(it);
            } else ++it;
        }
    }

    for (Plane slit : this->slits_bottom) {
        it = particles.begin();
        while(it != particles.end()) {
            int8_t ret;
            ret = slit.particle_colission(&*it);
            if (ret != 0) {
                particles.erase(it);
            } else ++it;
        }
    }


    int count = 0;
    it_diodes = diodes.begin();
    for (uint64_t i = 0; i < this->diodes.size(); i++) {
        double diode_current = 0;
        it = particles.begin();
        while(it != particles.end()) {
            Vector_3D contact_point_G;
            contact_point_G = this->diodes.at(i).calculate_point_of_contact(*it);
            //printf("%f %f \n", contact_point_G.x, contact_point_G.y);
            int8_t ret;
            ret = this->diodes.at(i).particle_colission(&*it);
            if (ret == 0) {
                double particle_responsivity = linear_interpolation_rvw(this->rvw, it->wavelength, this->rvw_len);
                double current = particle_responsivity * it->power;
                diode_current += current;
                //printf("%f %f \n", it->position.x, it->position.y);
                particles.erase(it);
            } else { 
                ++it;
                count++;
            }
        }
        currents.push_back(diode_current);
    }
    //printf("nbr of particles that hit: %d \n", count);
    return currents;
}


void Sun_sensor::read_rvw(char * file){
    this->rvw_file = file;
    this->read_rvw();
}
void Sun_sensor::read_rvw(){
    std::ifstream in;
    std::string contents;
    int len;
    in.open(this->rvw_file);
    getline(in, contents);
    sscanf(contents.c_str(), "%d\n", &len);
    std::vector<rvw_data> data;

    int i = 0;
    while (getline(in, contents)){
        rvw_data new_data;
        sscanf(contents.c_str(), "%lf %lf \n", &new_data.wavelength, &new_data.responsivity);
        data.push_back(new_data);
        i++;
    };

    this->rvw = data;
    this->rvw_len = len;
}


ADPD2140::ADPD2140(Vector_3D position, Matrix_3D dcm_BN){
    this->position = position;
    this->dcm_BN = dcm_BN;
    double to_mm = 1. / 1000; // to mm

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
    double width = 1 * to_mm;
    double hight = .01 * to_mm;
    Vector_3D slit_B(0,0, 5 * to_mm);
    Vector_3D slit_G;
    slit_G = dcm_BN * slit_B + position;

    this->slits_top.push_back(Plane(slit_G, dcm_BN, 2 * width, 1 * width, 0.));

    this->read_rvw("../ADPD2140");
}

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

    double x = - 10;
    double d = 5;

    while (x <= 10){
        bb.position = Vector_3D(x,0,d);

        int64_t begin = NOW();
        std::vector<double> currents = adpd.simulate(&bb, 10);
        printf("%f %f \n",atan (x / d) * 57.2, currents.at(0)+ currents.at(1) + currents.at(2) + currents.at(3));
        int64_t end = NOW();
        //printf("dt %f [ms] \n", (double) (end - begin) / MILLISECONDS);
        x += 0.05;
    }
}

