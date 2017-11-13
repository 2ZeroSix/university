#pragma once
#include "GraphicsEngine/Materials/Material.h"
#include "Stageable.h"


class MaterialCubeSphere : public Stageable
{
public:
    MaterialCubeSphere(float radius=.5f);
    virtual void Init(Object * pObject);
    virtual void addStage(float stage);
    virtual void Deinit();

    virtual void SetMaterial();
private:
    float m_stage;
    float m_radius;
};