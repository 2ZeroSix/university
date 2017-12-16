#ifndef GRAPHICSENGINE_SPOTLIGHT_H
#define GRAPHICSENGINE_SPOTLIGHT_H


#include "Light.h"

class LightSpot : public Light {
private:
    float m_cosPhi2{};
    float m_cosTheta2{};
    float m_falloff{};
    float toRad(float degree) {
        return static_cast<float>(cos(degree * DEG2RAD));
    }
public:
    void setPhi(float phi) {
        m_cosPhi2 = toRad(phi/2);
    }

    void setTheta(float theta) {
        m_cosTheta2 = toRad(theta/2);
    }

    void setFalloff(float falloff) {
        m_falloff = falloff;
    }

    explicit LightSpot(float theta=90, float phi=90, float falloff=1.0f, Vector3 atten=Vector3(1.0,0.0,0.0))
            : Light(LightType::LIGHT_SPOT) {
        setAttenuationFactors(atten);
        setPhi(phi);
        setTheta(theta);
        setFalloff(falloff);
    }

    Vector4 GetTypeOptions() const override {
        Vector4 vec = Light::GetTypeOptions();
        vec.y = m_cosTheta2;
        vec.z = m_cosPhi2;
        vec.w = m_falloff;
        return vec;
    }
};


#endif //GRAPHICSENGINE_SPOTLIGHT_H
