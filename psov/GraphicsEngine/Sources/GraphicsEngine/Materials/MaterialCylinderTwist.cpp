#include <iostream>
#include <cmath>
#include "MaterialCylinderTwist.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/MathUtils.h"
#include "GraphicsEngine/SceneUtils.h"



// TODO: Реализовать переключение Graphics API при нажатии на кнопки (1 - DirectX 11, 2 - OpenGL 2.0, 9 - DirectX 9)
// и отладить на этом механизм использования функций Init() и Deinit()
void MaterialCylinderTwist::Init(Object * pObject)
{
    Material::Init(pObject);

    // TODO: Нужно при компиляции скопировать папку с шейдерами
    // Google it: "visual studio during build copy files into application folder"
}

void MaterialCylinderTwist::Deinit()
{
    Material::Deinit();
}

void MaterialCylinderTwist::SetMaterial()
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
        SetVertexShaderFloat("radius", m_radius);
        SetVertexShaderEnd();

        SetPixelShaderBegin();
        SetPixelShaderEnd();
    }
    SetMaterialEnd();
}

MaterialCylinderTwist::MaterialCylinderTwist(float radius) {
    m_stage = 0.f;
    m_radius = radius;
    m_vsFileName = "ShaderUnlitCylinderTwist";
    m_psFileName = "ShaderUnlitCylinderTwist";
}

void MaterialCylinderTwist::addStage(float stage) {
    if (stage > 2.f)
        stage = stage - std::floor(stage);
    m_stage += stage;
    m_stage -= m_stage <= 2.f ? 0.f : 2.f;
}

