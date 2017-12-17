#pragma once

#include <cmath>
#include <GraphicsEngine/Materials/Stageable.h>
#include <GraphicsEngine/Materials/MaterialCubeSphere.h>
#include <GraphicsEngine/Materials/MaterialCylinderTwist.h>
#include <GraphicsEngine/GraphicsApi/OpenGL20/GL20GUI.h>
#include <GraphicsEngine/GUI.h>

#include "GraphicsEngine/Application.h"
#include "GraphicsEngine/Camera.h"
#include "GraphicsEngine/GraphicsEngine.h"
#include "GraphicsEngine/Light.h"
#include "GraphicsEngine/Materials/MaterialUnlit.h"
#include "GraphicsEngine/Meshes/MeshCube.h"
#include "GraphicsEngine/Meshes/MeshCylinder.h"
#include "GraphicsEngine/Meshes/MeshTriangle.h"
#include "GraphicsEngine/Meshes/MeshQuad.h"
#include "GraphicsEngine/Meshes/MeshSphere.h"
#include "GraphicsEngine/Object.h"
#include "GraphicsEngine/Scene.h"
#include "GraphicsEngine/Transform.h"
#include "Tasks/Task.h"
#include "Tasks/ObjectRotator.h"
#include <chrono>
#include <string>
#include <GraphicsEngine/Screen.h>

using namespace std::chrono;
using namespace std;
class Task02: public Task
{
    Stageable* material1 = NULL;
    Stageable* material2 = NULL;
    Object* pObj1 = NULL;
    Object* pObj2 = NULL;
    GUI gui;
    double start;
    double prevFrameCount;
public:
    virtual ~Task02() {
        delete pObj1;
        delete pObj2;
    }

    virtual void Init()
    {
        Scene & scene = Application::Instance().GetScene();

        // Камера
        {
            Object * pCameraObj = new Object();
            pCameraObj->m_pTransform = new Transform( Vector3(0, 2, -5), Vector3(20.0f, 0.0f, 0.0f));
            Camera * pCamera = new Camera();
            pCamera->SetFovY(90);
            pCamera->SetNearPlane(0.01f);
            pCamera->SetFarPlane(100);
            pCameraObj->AddComponent( pCamera );

            scene.SetCamera( pCamera );
        }

        {
            Object * pObject = new Object();
            pObject->m_pMesh		= new MeshCube(20);
            pObject->m_pTransform	= new Transform(2, 0, 0);
            material1 = new MaterialCubeSphere(std::sqrt(.5f));
            pObject->m_pMaterial = material1;

            scene.AddObject( pObject );

            pObj1 = pObject;
        }

        {
            Object * pObject = new Object();
            pObject->m_pMesh		= new MeshCylinder(20);
            pObject->m_pTransform	= new Transform(-2, 0, 0);
            material2 = new MaterialCylinderTwist(1.f);
            pObject->m_pMaterial	= material2;

            scene.AddObject( pObject );

            pObj2 = pObject;
        }
//        for (int i = 2; i < 10; ++i) {
//            Object * pObject = new Object();
//            pObject->m_pMesh		= new MeshCylinder(20);
//            pObject->m_pTransform	= new Transform(-2, 0, -i);
//            material2 = new MaterialCylinderTwist(1.f);
//            pObject->m_pMaterial	= material2;
//
//            scene.AddObject( pObject );
//
//            pObj2 = pObject;
//        }

        start = Time::GetTime();
        prevFrameCount = Time::GetFrameCount();
    }

    virtual void Update() {
        material1->addStage(.001f);
        material2->addStage(.001f);
        static double fps = 0;
        double end = Time::GetTime();
        double delta = end - start;
        if (delta > .25f) {
            double frameCount = Time::GetFrameCount();
            double frameDelta = frameCount - prevFrameCount;
            fps = frameDelta / delta;
            prevFrameCount = frameCount;
            start = end;
        }
        gui.Label(0, Screen::GetHeight() - 18, 0, 0, string("FPS == ") + to_string(fps));
    }
};