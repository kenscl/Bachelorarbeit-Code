#include "light_source.h"

class black_body : light_source {
    public:
        double Uv(double frequency, double Temperature_K);
};
