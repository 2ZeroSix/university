#pragma once
#include "Mesh.h"


class MeshCubeSphere : public Mesh
{
public:
    MeshCubeSphere(int levelCount = 1);

    virtual void Init();
    virtual void Deinit();

private:
    void InitCubeSimple();
    void InitCubeDetailedStrip();
    void InitCubeDetailedList();

    int m_levelCount;
};