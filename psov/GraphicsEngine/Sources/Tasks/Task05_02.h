#pragma once
#include "Tasks/Task.h"
#include "GraphicsEngine/Application.h"
#include "GraphicsEngine/Meshes/MeshQuad.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/Object.h"
#include "GraphicsEngine/Scene.h"
#include "GraphicsEngine/GraphicsEngine.h"
#include "GraphicsEngine/Materials/MaterialSand.h"
#include "GraphicsEngine/Light.h"


class Task05_02: public Task
{
public:
	virtual ~Task05_02() { }

	virtual void Init()
	{
		Scene & scene = Application::Instance().GetScene();
	
		// Camera
		{
			Object * pCameraObj = new Object();
			Camera * pCamera = new Camera();
			pCameraObj->m_pTransform = new Transform( Vector3(0.0f, 1.0f,-7.0f), Vector3(25.0f, 0.0f, 0.0f) );			
			pCameraObj->AddComponent( pCamera );

			scene.SetCamera( pCamera );
		}

		// Object #1 - Plane with sand texture (Point filter)
		{
			Object * pObject1 = new Object();

			pObject1->m_pTransform	= new Transform( -0.675,0,0, 90,0,0, 0.2,15,1 );
			pObject1->m_pMesh		= new MeshQuad();			
			pObject1->m_pMaterial	= new MaterialSand(TEXTURE_FILTER_MODE_POINT);
						
			scene.AddObject( pObject1 );
		}

		{
			Object * pObject2 = new Object();

			pObject2->m_pTransform	= new Transform( -0.225,0,0, 90,0,0, 0.2,15,1 );
			pObject2->m_pMesh		= new MeshQuad();
			pObject2->m_pMaterial	= new MaterialSand(TEXTURE_FILTER_MODE_BILINEAR);

			scene.AddObject( pObject2 );
		}

        {
            Object * pObject3 = new Object();

            pObject3->m_pTransform	= new Transform( 0.225,0,0, 90,0,0, 0.2,15,1 );
            pObject3->m_pMesh		= new MeshQuad();
            pObject3->m_pMaterial	= new MaterialSand(TEXTURE_FILTER_MODE_TRILINEAR);

            scene.AddObject( pObject3 );
        }

        {
            Object * pObject4 = new Object();

            pObject4->m_pTransform	= new Transform( 0.675,0,0, 90,0,0, 0.2,15,1 );
            pObject4->m_pMesh		= new MeshQuad();
            pObject4->m_pMaterial	= new MaterialSand(TEXTURE_FILTER_MODE_ANISOTROPIC);

            scene.AddObject( pObject4 );
        }
	}

	virtual void Update()
	{
		
	}
};
