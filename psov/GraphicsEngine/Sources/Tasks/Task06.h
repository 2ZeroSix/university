#pragma once

#include <GraphicsEngine/Materials/MaterialEarth.h>
#include <GraphicsEngine/Materials/MaterialEarthLight.h>
#include <GraphicsEngine/LightSpot.h>
#include <GraphicsEngine/LightPoint.h>
#include <GraphicsEngine/LightDirect.h>
#include <GraphicsEngine/Materials/MaterialLight.h>
#include <GraphicsEngine/Meshes/MeshObjFile.h>
#include "Tasks/Task.h"
#include "GraphicsEngine/Application.h"
#include "GraphicsEngine/Meshes/MeshSphere.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/Object.h"
#include "GraphicsEngine/Scene.h"
#include "GraphicsEngine/GraphicsEngine.h"
#include "GraphicsEngine/Materials/MaterialSand.h"
#include "GraphicsEngine/Light.h"
#include "GraphicsEngine/Camera.h"
#include "ObjectRotator.h"


class Task06: public Task
{
public:
	virtual ~Task06() { }

	virtual void Init()
	{
		Scene & scene = Application::Instance().GetScene();
	
		// Camera
		{
			Object * pCameraObj = new Object();
			Camera * pCamera = new Camera();
			pCameraObj->m_pTransform = new Transform( Vector3(0.0f, 3.0,-5.0f), Vector3(30.f, 0.0f, 0.0f) );
			pCameraObj->AddComponent( pCamera );

			scene.SetCamera( pCamera );
		}

        {
            Object * pObject4 = new Object();

            pObject4->m_pTransform	= new Transform( 0,0,0, 0,0,0, 3,3,3 );
//            pObject4->m_pMesh		= new MeshSphere(50);
            pObject4->m_pMesh		= new MeshObjFile("../Data/MeshSphere.obj");
            pObject4->m_pMaterial	= new MaterialEarthLight(TEXTURE_FILTER_MODE_ANISOTROPIC);
            pObject4->AddComponent(new ObjectRotator(.0f, 90.f, .0f));

            scene.AddObject( pObject4 );
        }
// Источник света #1
        {
            auto * pLight = new LightDirect();
            pLight->SetColor(1,1,0);
            pLight->SetIntensity(1);
            pLight->setSpecularColor(1,1,0, 500.f);
            auto pLightObject = new Object();
            pLightObject->m_pTransform	= new Transform(1,0,0, 0, 90,0, 1,1,1);
            pLightObject->AddComponent(pLight);
//            pLightObject->m_pTransform->SetParent(pObject1->m_pTransform);
            scene.AddLight(pLight);
        }

        // Источник света #2
        {
            auto * pLight = new LightPoint(.5, 0.0, .0f);
            pLight->SetColor(1,1,1);
            pLight->SetIntensity(1);
            pLight->setSpecularColor(1,1,1, 500.f);

            auto * pLightObject = new Object();
            pLightObject->m_pTransform	= new Transform(4.f,0,-4.f, 0,0,0, 1,1,1);
            pLightObject->AddComponent(pLight);

            scene.AddLight(pLight);
        }
        // Источник света #3
        {
            auto * pLight = new LightSpot(15, 30, 1.f);
            pLight->setAttenuationFactors(Vector3(1.0, 0.0, .0f));
            pLight->SetColor(1,0,0);
            pLight->SetIntensity(1);
            pLight->setSpecularColor(1,0,0, 500.f);

            auto * pLightObject = new Object();
            pLightObject->m_pTransform	= new Transform(0,3.f,-3.f, 45,0,0, 1,1,1);
            pLightObject->AddComponent(pLight);
//            pLightObject->m_pTransform->SetParent(pObject1->m_pTransform);

            scene.AddLight(pLight);
        }
    }

	virtual void Update()
	{
		
	}
};
