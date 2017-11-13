#pragma once
#include "GraphicsEngine/Materials/Material.h"
#include "Stageable.h"


// Unlit значит "неосвещаемый",
// т.е. этот материал не освещается источниками света
class MaterialCylinderTwist : public Stageable
{
public:
    MaterialCylinderTwist(float radius=.5f);
    virtual void Init(Object * pObject);
    virtual void addStage(float stage);
    virtual void Deinit();

    virtual void SetMaterial();
private:
    float m_stage;
    float m_radius;
};