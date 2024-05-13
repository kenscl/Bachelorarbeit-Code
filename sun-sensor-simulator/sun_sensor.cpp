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
    particles = source->generate_particles(particle_count);

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
            int8_t ret;
            ret = this->diodes.at(i).particle_colission(&*it);
            if (ret == 0) {
                count++;
                double particle_responsivity = linear_interpolation_rvw(this->rvw, it->wavelength, this->rvw_len);
                double current = particle_responsivity * it->power;
                diode_current += current;
                particles.erase(it);
            } else ++it;
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

int main(){
    Sun_sensor ss;
    ss.read_rvw("../ADPD2140");
    ss.diodes.push_back(Plane(Vector_3D(5,0,0), Vector_3D(0,0,1), 5, 10));
    ss.diodes.push_back(Plane(Vector_3D(-5,0,0), Vector_3D(0,0,1), 5, 10));
    ss.slits_top.push_back(Plane(Vector_3D(0,0,0.5), Vector_3D(0,0,1), 10, 10));
    ss.slits_top.at(0).n = 0.66;
        
    black_body bb;
    bb.particle_enegery = 1;
    bb.glass_planes = ss.slits_top;
    bb.wavelength_max = 850;
    bb.wavelength_min = 850;

    double x = - 50;
    double d = 5;

    while (x <= 50){
        bb.position = Vector_3D(x,0,d);

        int64_t begin = NOW();
        std::vector<double> currents = ss.simulate(&bb, 1000);
        printf("%f %f \n",atan (x / d) * 57.2, currents.front() + currents.back());
        int64_t end = NOW();
        //printf("dt %f [ms] \n", (double) (end - begin) / MILLISECONDS);
        x += 0.1;
    }
}


ADPD2140::ADPD2140(Vector_3D position, Matrix_3D dcm_BN){
    this->position = position;
    this->dcm_BN = dcm_BN;
    // todo
}
