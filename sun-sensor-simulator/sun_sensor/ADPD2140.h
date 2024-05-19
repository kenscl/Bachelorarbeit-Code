#include "sun_sensor.h"
#ifndef __ADPD
#define __ADPD
class ADPD2140 : public Sun_sensor {

    public: 
        ADPD2140(Vector_3D position, Matrix_3D dcm_BN);
};
#endif
