﻿#pragma once
#include "GraphicsEngine/Component.h"
#include "GraphicsEngine/Object.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/Math.h"


enum LightType
{
	LIGHT_DIRECTIONAL = 1,
	LIGHT_POINT,
	LIGHT_SPOT,
};

class Light : public Component
{
protected:
    explicit Light(LightType type, float intensity=1.0f)
			: m_type(type), m_intensity(intensity) {}
public:
	Light() = delete;
	~Light() override = default;

	virtual Vector4 GetTypeOptions() const
	{
		return Vector4(m_type,0,0,0);
	}

	virtual Vector4 GetColor() const
	{
		return Vector4(m_color, m_intensity);
	}
	
	virtual Vector3 GetPosition() const
	{
		Vector3 position = m_pObject->m_pTransform->GetPosition();
		return position;
	}

	virtual Vector3 GetDirection() const
	{
		Vector3 direction = m_pObject->m_pTransform->GetForward();
		return direction;
	}

	virtual void SetColor(const Vector3& color)
	{
		// Clamp color by interval [0,1]
		m_color = Vector3::Clamp01(color);
	}

	virtual void SetColor(float r, float g, float b)
	{
		// Clamp r, g, b by interval [0,1]
		m_color = Vector3::Clamp01( Vector3(r, g, b) );
	}

	virtual void SetIntensity(float intensity)
	{
		// Clamp intensity by interval [0, +infinity]
		m_intensity = (intensity >= 0.f) ? intensity : 0.f;
	}
protected:
	LightType m_type;
	Vector3	m_color;
	float	m_intensity;

};
