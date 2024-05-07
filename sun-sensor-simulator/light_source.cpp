#include "light_source.h"
light_source::light_source(){
    this->position = Vector_3D(0,0,0);
}

light_source::light_source(Vector_3D position){
    this->position = position;
}
