#pragma once

#include "Material.h"

class Stageable : public Material{
public:
    virtual void addStage(float stage) = 0;
};