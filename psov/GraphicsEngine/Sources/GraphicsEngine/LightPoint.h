//
// Created by dzs on 10.12.17.
//

#ifndef GRAPHICSENGINE_POINTLIGHT_H
#define GRAPHICSENGINE_POINTLIGHT_H


#include "Light.h"

class LightPoint : public Light {
private:
    Vector3 m_attenuationFactors;
public:
    void setAttenuationFactors(const Vector3 &attenuationFactors) {
        LightPoint::m_attenuationFactors = attenuationFactors;
    }

public:
    explicit LightPoint(Vector3 attenuationFactors=Vector3(1.0,0.0,0.0))
            : Light(LightType::LIGHT_POINT),
              m_attenuationFactors(attenuationFactors) {}
    explicit LightPoint(float atten0, float atten1=0.0f, float atten2=0.0f)
            : Light(LightType::LIGHT_POINT),
              m_attenuationFactors(atten0, atten1, atten2) {}

    Vector4 GetTypeOptions() const override {
        Vector4 options = Light::GetTypeOptions();
        options.y =m_attenuationFactors.x;
        options.z =m_attenuationFactors.y;
        options.w =m_attenuationFactors.z;
        return options;
    }
};


#endif //GRAPHICSENGINE_POINTLIGHT_H
