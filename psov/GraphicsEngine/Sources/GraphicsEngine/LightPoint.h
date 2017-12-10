//
// Created by dzs on 10.12.17.
//

#ifndef GRAPHICSENGINE_POINTLIGHT_H
#define GRAPHICSENGINE_POINTLIGHT_H


#include "Light.h"

class LightPoint : public Light {
public:
    LightPoint() : Light(LightType::LIGHT_POINT) {}
};


#endif //GRAPHICSENGINE_POINTLIGHT_H
