#pragma once

#include <GraphicsEngine/Materials/MaterialEarth.h>
#include "Tasks/Task.h"
#include "GraphicsEngine/Application.h"
#include "GraphicsEngine/Meshes/MeshSphere.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/Object.h"
#include "GraphicsEngine/Scene.h"
#include "GraphicsEngine/GraphicsEngine.h"
#include "GraphicsEngine/Materials/MaterialSand.h"
#include "GraphicsEngine/Light.h"


class Task05_03: public Task
{
public:
	virtual ~Task05_03() { }

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
            pObject4->m_pMesh		= new MeshSphere(20);
            pObject4->m_pMaterial	= new MaterialEarth(TEXTURE_FILTER_MODE_ANISOTROPIC);
            pObject4->AddComponent(new ObjectRotator(.0f, 90.f, .0f));

            scene.AddObject( pObject4 );
        }
	}

	virtual void Update()
	{
		
	}
};
