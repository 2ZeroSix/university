#pragma once
#include "GraphicsEngine/Materials/Material.h"


// Рассчитывает только компоненту diffuse от всех источников света
class MaterialLight : public Material
{
public:
	MaterialLight();

	void Init(Object * pObject) override;

	void Deinit() override;

	void SetMaterial() override;
};
#pragma once
