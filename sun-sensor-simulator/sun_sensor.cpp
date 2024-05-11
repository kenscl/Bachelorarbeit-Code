#include "sun_sensor.h"
#include "math/matlib.h"
#include <cstdio>
#include <fstream>
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
            printf("i %f %f, i+1 %f %f\n", data.at(i).wavelength, data.at(i).responsivity, data.at(i+1).wavelength, data.at(i+1).responsivity);
            return lerp(data.at(i).responsivity, data.at(i+1).responsivity, data.at(i).wavelength, data.at(i+1).wavelength, value);
        }
    }
    return data.at(len - 1).responsivity;
}
std::vector<double> Sun_sensor::simulate(light_source source){
    std::vector<double> currents;
    std::vector<Particle> particles; //= source.generate_particles();
    particles.push_back(Particle(Vector_3D(0,0,1), Vector_3D(0,0,-1), 600, 100));
    std::vector<Particle>::iterator it;
    for (Plane slit : this->slits_top) {
        for(it = particles.begin(); it != particles.end(); it++) {
            int8_t ret;
            ret = slit.particle_colission(&*it);
            if (ret != 0) {
                particles.erase(it);
            }
        }
    }
    for (Plane slit : this->slits_bottom) {
        for(it = particles.begin(); it != particles.end(); it++) {
            int8_t ret;
            ret = slit.particle_colission(&*it);
            if (ret != 0) {
                particles.erase(it);
            }
        }
    }
    
    for (Plane diode: this->diodes) {
        double diode_current = 0;
        for(it = particles.begin(); it != particles.end(); it++) {
            int8_t ret;
            ret = diode.particle_colission(&*it);
            if (ret == 0) {
                double particle_responsivity = linear_interpolation_rvw(this->rvw, it->wavelength, this->rvw_len);
                printf("res %f\n", particle_responsivity);
                double current = particle_responsivity * it->power;
                diode_current += current;
            }
        }
        currents.push_back(diode_current);
    }
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

    i = 0;
    for (i; i < len; i++){
        printf("rvw: %f %f\n", this->rvw[i].wavelength, this->rvw[i].responsivity);
    }
}

int main(){
    Sun_sensor ss;
    ss.read_rvw("../ADPD2140");
    ss.diodes.push_back(Plane(Vector_3D(0,0,0), Vector_3D(0,0,1), 10, 10));
    std::vector<double> currents = ss.simulate(light_source());
    printf("current: %f \n", currents.front());
}


ADPD2140::ADPD2140(Vector_3D position, Matrix_3D dcm_BN){
    this->position = position;
    this->dcm_BN = dcm_BN;
    // todo
}
