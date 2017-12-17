﻿#include "MaterialEarthLight.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/MathUtils.h"
#include "GraphicsEngine/SceneUtils.h"
#include "GraphicsEngine/Light.h"

MaterialEarthLight::MaterialEarthLight(TextureFilterMode filterMode)
{
	m_vsFileName = "ShaderEarthLight";
	m_psFileName = "ShaderEarthLight";

	m_pTexture1 = NULL;
	m_filterMode = filterMode;
}

void MaterialEarthLight::Init(Object * pObject)
{
	Material::Init(pObject);

	m_pTexture1 = new Texture2D("Earth_Albedo.jpg");
	m_pTexture1->SetFilterMode(m_filterMode);
	m_pTexture2 = new Texture2D("Earth_NormalMap.jpg");
	m_pTexture2->SetFilterMode(m_filterMode);
}

void MaterialEarthLight::Deinit()
{
	delete m_pTexture1;
	m_pTexture1 = NULL;

	Material::Deinit();
}

void MaterialEarthLight::SetMaterial()
{
	const Matrix4x4 & matWorld	= SceneUtils::GetMatrixWorld(m_pObject);
	const Matrix4x4 & matView	= SceneUtils::GetMatrixView();
	const Matrix4x4 & matProj	= SceneUtils::GetMatrixProj();

	Camera& camera = Application::Instance().GetScene().GetCamera();
	const Matrix4x4 & matWorldCam = SceneUtils::GetMatrixWorld(camera.GetObjectPtr());

	const Matrix4x4 matWorldViewProjT	= MathUtils::GetMatrixWorldViewProjT(matWorld, matView, matProj);
	const Matrix4x4 matWorldT			= matWorld.Transpose();
	const Matrix4x4 matWorldNormal		= matWorld.Inverse();

	// Получили список всех источников света в сцене
	std::list<const Light *> lights = SceneUtils::GetLights();
	const size_t count = lights.size() < 3 ? lights.size() : 3;
	SetMaterialBegin();
	{
		SetVertexShaderBegin();
		SetVertexShaderMatrix4x4("matrixWorldViewProjT", matWorldViewProjT);
		SetVertexShaderEnd();

		SetPixelShaderBegin();
		SetPixelShaderMatrix4x4	("matWorldNormal",	matWorldNormal);
		SetPixelShaderMatrix4x4	("matWorldT",		matWorldT);
		SetPixelShaderVector4	("materialColor",	Vector4(1, 1, 1, 1));
		SetPixelShaderInt       ("lightsCount",     static_cast<int>(count));
		Vector4 cameraVec = Vector4(camera.GetObjectPtr()->m_pTransform->GetPosition(), 1.0);
		SetPixelShaderVector4("camera",	cameraVec);
		// Передаём параметры каждого источника света
        int i = 0;
		for (auto iter = lights.begin(); iter != lights.end(); ++iter, ++i)
		{
			const Light * pLight = *iter;
			const Vector4& lightTypeOptions	    = pLight->GetTypeOptions();
			const Vector4& lightAtten           = pLight->getAttenuationFactors();
			const Vector4& lightPosition        = Vector4( pLight->GetPosition(), 1 );
			const Vector4& lightDirection	    = Vector4( pLight->GetDirection(), 0 );
			const Vector4& lightColor           = pLight->GetColor();
			const Vector4& lightSpecularColor   = pLight->getSpecularColor();
			// "lights[i]"
			std::string lightStr = "lights[" + std::to_string(i) + "]";

			// "lights[i].type", "lights[i].position", "lights[i].direction", "lights[i].color"
			SetPixelShaderVector4( (lightStr + ".typeOptions").c_str(),	 lightTypeOptions);
			SetPixelShaderVector4( (lightStr + ".attenuation").c_str(),	 lightAtten);
			SetPixelShaderVector4( (lightStr + ".position").c_str(),	 lightPosition );
			SetPixelShaderVector4( (lightStr + ".direction").c_str(),	 lightDirection );
			SetPixelShaderVector4( (lightStr + ".color").c_str(),		 lightColor );
			SetPixelShaderVector4( (lightStr + ".specularColor").c_str(),lightSpecularColor );
		}
		SetPixelShaderTexture2d("texture1", m_pTexture1);
		SetPixelShaderTexture2d("texture2", m_pTexture2);
		SetPixelShaderEnd();
	}
	SetMaterialEnd();
}
