#include "sun_sensor.h"
#include "../math/matlib.h"
#include <cstdint>
#include <cstdio>
#include <fstream>
#include "sun_sensor.h"
#include "../math/matlib.h"
#include "../black_body.h"
#include "../misc.h"

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

double linear_interpolation_radiant_senitivity(std::vector<radiant_senitivity_data> data, double angle, int len){
    if (data.at(0).angle> angle) return data.at(0).sensitivity;
    for (int i = 0; i < len - 1; i++) {
        if (data.at(i).angle == angle) return data.at(i).sensitivity;
        if (data.at(i).angle <= angle && data.at(i+1).angle > angle){
            return lerp(data.at(i).sensitivity, data.at(i+1).sensitivity, data.at(i).angle, data.at(i+1).angle, angle);
        }
    }
    return data.at(len - 1).sensitivity;
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


    particles = source->generate_particles((int) particle_count * cos(angle_x) * cos (angle_y));

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
        double angular_senitivity_x = linear_interpolation_radiant_senitivity(this->radiant_senitivity_x, angle_x, this->radiant_senitivity_len_x);
        double angular_senitivity_y = linear_interpolation_radiant_senitivity(this->radiant_senitivity_y, angle_y, this->radiant_senitivity_len_y);
        currents.push_back(diode_current * angular_senitivity_x * angular_senitivity_y);
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

void Sun_sensor::read_radiant_sensitivity(char* file) {
    this->radiant_senitivity_file = file;
    this->read_radiant_sensitivity();
}
void Sun_sensor::read_radiant_sensitivity() {
    
    std::ifstream in;
    std::string contents;
    int len_x;
    int len_y;
    in.open(this->radiant_senitivity_file);
    std::vector<radiant_senitivity_data> data_x;
    std::vector<radiant_senitivity_data> data_y;

    getline(in, contents);
    sscanf(contents.c_str(), "%d\n", &len_x);

    for (int i = 0; i < len_x; i++){
        getline(in, contents);
        radiant_senitivity_data new_data;
        sscanf(contents.c_str(), "%lf %lf \n", &new_data.angle, &new_data.sensitivity);
        new_data.angle = new_data.angle * M_PI / 180;
        data_x.push_back(new_data);
    };

    getline(in, contents);
    sscanf(contents.c_str(), "%d\n", &len_y);
    printf("%s \n", contents.c_str());
    for (int i = 0; i < len_y; i++){
        getline(in, contents);
        radiant_senitivity_data new_data;
        sscanf(contents.c_str(), "%lf %lf \n", &new_data.angle, &new_data.sensitivity);
        new_data.angle = new_data.angle * M_PI / 180;
        data_y.push_back(new_data);
    };

    this->radiant_senitivity_x = data_x;
    this->radiant_senitivity_y = data_y;
    this->radiant_senitivity_len_x = len_x;
    this->radiant_senitivity_len_y = len_y;
}

