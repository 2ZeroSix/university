﻿#include "GraphicsEngine/Materials/Material.h"


// Рассчитывает только компоненту diffuse от всех источников света
class MaterialDiffuse : public Material
{
public:
	MaterialDiffuse();

	void Init(Object * pObject) override;

	void Deinit() override;

	void SetMaterial() override;
};
