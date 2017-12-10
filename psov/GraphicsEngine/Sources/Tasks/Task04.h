#pragma once

#include <GraphicsEngine/LightPoint.h>
#include <GraphicsEngine/LightDirect.h>
#include <GraphicsEngine/LightSpot.h>
#include <GraphicsEngine/Materials/MaterialLight.h>
#include "GraphicsEngine/Application.h"
#include "GraphicsEngine/GraphicsEngine.h"
#include "GraphicsEngine/Light.h"
#include "GraphicsEngine/Materials/MaterialTask01.h"
#include "GraphicsEngine/Materials/MaterialUnlit.h"
#include "GraphicsEngine/Meshes/MeshTriangle.h"
#include "GraphicsEngine/Meshes/MeshQuad.h"
#include "GraphicsEngine/Meshes/MeshSphere.h"
#include "GraphicsEngine/Object.h"
#include "GraphicsEngine/Scene.h"
#include "GraphicsEngine/Transform.h"
#include "Tasks/Task.h"
#include "Tasks/ObjectRotator.h"


class Task04: public Task
{
    Object* pObject1;
public:
    ~Task04() override = default;

    void Init() override {
		Scene & scene = Application::Instance().GetScene();
		
		// Камера

		{
            Object * pCameraObj = new Object();
            pCameraObj->m_pTransform = new Transform( Vector3(0.0f, 0.0f,-7.0f), Vector3(0.0f, 0.0f, 0.0f));
			Camera * pCamera = new Camera();
			pCameraObj->AddComponent( pCamera );

			scene.SetCamera( pCamera );
		}

		// объект #1 - Сфера
		{
            pObject1 = new Object();

			pObject1->m_pTransform	= new Transform(0,0,0, 0,0,0, 3,3,3);
			pObject1->m_pMesh		= new MeshSphere(20);
            pObject1->m_pMaterial	= new MaterialLight();
			pObject1->AddComponent( new ObjectRotator(0,10,0) );

			scene.AddObject( pObject1 );
		}

		// Источник света #1
		{
			auto * pLight = new LightDirect();
			pLight->SetColor(1,1,0);
			pLight->SetIntensity(1);

            auto pLightObject = new Object();
			pLightObject->m_pTransform	= new Transform(1,0,0, 0,90,0, 1,1,1);
			pLightObject->AddComponent(pLight);
            pLightObject->m_pTransform->SetParent(pObject1->m_pTransform);
			scene.AddLight(pLight);
		}

		// Источник света #2
		{
			auto * pLight = new LightPoint(1.0f);
			pLight->SetColor(1,1,1);
			pLight->SetIntensity(1);

            auto * pLightObject = new Object();
			pLightObject->m_pTransform	= new Transform(3,0,0, 0,0,0, 1,1,1);
			pLightObject->AddComponent(pLight);
            pLightObject->m_pTransform->SetParent(pObject1->m_pTransform);

			scene.AddLight(pLight);
		}
        // Источник света #3
        {
            auto * pLight = new LightSpot(15, 45, 1.f);
            pLight->SetColor(1,0,0);
            pLight->SetIntensity(1);

            auto * pLightObject = new Object();
            pLightObject->m_pTransform	= new Transform(0,0,-3.f, 0,0,0, 1,1,1);
            pLightObject->AddComponent(pLight);
            pLightObject->m_pTransform->SetParent(pObject1->m_pTransform);

            scene.AddLight(pLight);
        }
	}

    void Update() override {
	}
};
