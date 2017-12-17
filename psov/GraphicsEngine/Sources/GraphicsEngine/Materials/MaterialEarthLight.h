#pragma once
#include "GraphicsEngine/Materials/Material.h"
#include "GraphicsEngine/Texture2D.h"


class MaterialEarthLight : public Material
{
public:
	MaterialEarthLight(TextureFilterMode filterMode);

	virtual void Init(Object * pObject);
	virtual void Deinit();
	
	virtual void SetMaterial();

private:
	Texture2D *	m_pTexture1;
	Texture2D *	m_pTexture2;
	TextureFilterMode m_filterMode;
};
