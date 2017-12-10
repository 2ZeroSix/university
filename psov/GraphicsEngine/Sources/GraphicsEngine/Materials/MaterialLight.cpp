#include "MaterialLight.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/Light.h"
#include "GraphicsEngine/MathUtils.h"
#include "GraphicsEngine/SceneUtils.h"


MaterialLight::MaterialLight()
{
	m_vsFileName = "ShaderLight";
	m_psFileName = "ShaderLight";
}

// TODO: Реализовать переключение Graphics API при нажатии на кнопки (1 - DirectX 11, 2 - OpenGL 2.0, 9 - DirectX 9)
// и отладить на этом механизм использования функций Init() и Deinit()
void MaterialLight::Init(Object * pObject)
{
	Material::Init(pObject);
	
	// TODO: Нужно при компиляции скопировать папку с шейдерами
	// Google it: "visual studio during build copy files into application folder"
}

void MaterialLight::Deinit()
{
	Material::Deinit();
}

void MaterialLight::SetMaterial()
{

	// Заполняем матрицы World, View, Proj
	const Matrix4x4 & matWorld	= SceneUtils::GetMatrixWorld(m_pObject);
	const Matrix4x4 & matView	= SceneUtils::GetMatrixView();
	const Matrix4x4 & matProj	= SceneUtils::GetMatrixProj();

	Camera& camera = Application::Instance().GetScene().GetCamera();
	const Matrix4x4 & matWorldCam = SceneUtils::GetMatrixWorld(camera.GetObjectPtr());
//	const Vector4 cameraPosition = MathUtils::GetMatrixWorldViewProjT(matWorldCam, matView, matProj);


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
		SetPixelShaderInt	("lightsCount",	static_cast<int>(count));
		SetPixelShaderMatrix4x4	("camera",	MathUtils::GetMatrixWorldViewProjT(matWorldCam, matView, matProj));
		// Передаём параметры каждого источника света
		int i = 0;
		std::list<const Light *>::iterator iter;
		for (iter = lights.begin(); iter != lights.end(); ++iter, ++i)
		{
			const Light * pLight = *iter;
			const Vector4 lightTypeOptions	= pLight->GetTypeOptions();
			const Vector4 lightPosition		= Vector4( pLight->GetPosition(), 1 );
			const Vector4 lightDirection	= Vector4( pLight->GetDirection(), 0 );
			const Vector4 lightColor		= pLight->GetColor();
			// "lights[i]"
			std::string lightStr = "lights[" + std::to_string(i) + "]";
			
			// "lights[i].type", "lights[i].position", "lights[i].direction", "lights[i].color"
			SetPixelShaderVector4( (lightStr + ".typeOptions").c_str(),	 lightTypeOptions);
			SetPixelShaderVector4( (lightStr + ".position").c_str(),	 lightPosition );
			SetPixelShaderVector4( (lightStr + ".direction").c_str(),	 lightDirection );
			SetPixelShaderVector4( (lightStr + ".color").c_str(),		 lightColor );
			SetPixelShaderVector4( (lightStr + ".specularColor").c_str(),lightColor );
		}

		SetPixelShaderEnd();
	}
	SetMaterialEnd();
}
