//
// Created by dzs on 10.12.17.
//

#ifndef GRAPHICSENGINE_LIGHTDIRECT_H
#define GRAPHICSENGINE_LIGHTDIRECT_H


#include "Light.h"

class LightDirect : public Light {
public:
    LightDirect() : Light(LightType::LIGHT_DIRECTIONAL) {}
};


#endif //GRAPHICSENGINE_LIGHTDIRECT_H
