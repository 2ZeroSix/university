#include <iostream>
#include <cmath>
#include "MaterialUnlit.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/MathUtils.h"
#include "GraphicsEngine/SceneUtils.h"



// TODO: Реализовать переключение Graphics API при нажатии на кнопки (1 - DirectX 11, 2 - OpenGL 2.0, 9 - DirectX 9)
// и отладить на этом механизм использования функций Init() и Deinit()
void MaterialUnlit::Init(Object * pObject)
{
	Material::Init(pObject);
	
	// TODO: Нужно при компиляции скопировать папку с шейдерами
	// Google it: "visual studio during build copy files into application folder"
}

void MaterialUnlit::Deinit()
{
	Material::Deinit();
}

void MaterialUnlit::SetMaterial()
{
	// Заполняем матрицы World, View, Proj
	const Matrix4x4 & matWorld	= SceneUtils::GetMatrixWorld(m_pObject);
	const Matrix4x4 & matView	= SceneUtils::GetMatrixView();
	const Matrix4x4 & matProj	= SceneUtils::GetMatrixProj();
	
	const Matrix4x4 matWorldViewProjT = MathUtils::GetMatrixWorldViewProjT(matWorld, matView, matProj);

	SetMaterialBegin();
	{
		SetVertexShaderBegin();
        SetVertexShaderVector4("constColor", Vector4(1, 1, 1, 1));
		SetVertexShaderMatrix4x4("matrixWorldViewProjT", matWorldViewProjT);
        switch (m_transform) {
            case SPHERE_TRANSFORM:
                SetVertexShaderFloat("stage", (m_stage > 1.f ? 2.f - m_stage : m_stage));
                break;
            case TWIST_TRANSFORM:
                float stage;
                if (.5f >= m_stage) {
                    stage = m_stage*2.f;
                } else if (1.5f >= m_stage && m_stage > .5f){
                    stage = (1.f - m_stage)*2.f;
                } else if (2.f >= m_stage && m_stage > 1.5f){
                    stage = -(2.f - m_stage)*2.f;
                } else {
                    stage = 0.f;
                }
                SetVertexShaderFloat("stage", stage);
                break;
        }
        SetVertexShaderFloat("radius", m_radius);
        SetVertexShaderInt("transform", m_transform);
		SetVertexShaderEnd();

		SetPixelShaderBegin();
		SetPixelShaderEnd();
	}
	SetMaterialEnd();
}

MaterialUnlit::MaterialUnlit(MaterialUnlit::transform transform, float radius) {
    m_stage = 0.f;
    m_radius = radius;
    m_transform = transform;
    m_vsFileName = "ShaderUnlit";
    m_psFileName = "ShaderUnlit";
}

void MaterialUnlit::addStage(float stage) {
    if (stage > 2.f)
        stage = stage - std::floor(stage);
    m_stage += stage;
    m_stage -= m_stage <= 2.f ? 0.f : 2.f;
}

