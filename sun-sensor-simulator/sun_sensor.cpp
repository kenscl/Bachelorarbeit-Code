#include "sun_sensor.h"
Sun_sensor::Sun_sensor(){}
        Sun_sensor::Sun_sensor(Vector_3D position, Matrix_3D dcm_BN, std::vector<Plane> diodes, std::vector<Plane> slits_top, std::vector<Plane> slits_bottom){
    this->position = position;
    this->dcm_BN = dcm_BN;
    this->diodes = diodes;
    this->slits_top = slits_top;
    this->slits_bottom = slits_bottom;
}

std::vector<double> Sun_sensor::simulate(light_source source){
    std::vector<double> currents;
    std::vector<Particle> particles = source.generate_particles();
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
        for(it = particles.begin(); it != particles.end(); it++) {
            int8_t ret;
            ret = diode.particle_colission(&*it);
            if (ret == 0) {
                                
            }
        }
    }
}





ADPD2140::ADPD2140(Vector_3D position, Matrix_3D dcm_BN){
    this->position = position;
    this->dcm_BN = dcm_BN;
    // todo
}
