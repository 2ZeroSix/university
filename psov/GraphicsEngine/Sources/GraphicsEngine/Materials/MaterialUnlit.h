#pragma once
#include "GraphicsEngine/Materials/Material.h"


// Unlit значит "неосвещаемый",
// т.е. этот материал не освещается источниками света
class MaterialUnlit : public Material
{
public:
	enum transform {
		SPHERE_TRANSFORM=0,
		TWIST_TRANSFORM=1
	};
	MaterialUnlit(MaterialUnlit::transform=SPHERE_TRANSFORM, float radius=.5f);
	virtual void Init(Object * pObject);
    virtual void addStage(float stage);
	virtual void Deinit();
	
	virtual void SetMaterial();
private:
    MaterialUnlit::transform m_transform;
    float m_stage;
    float m_radius;
};
