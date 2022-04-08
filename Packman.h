#pragma once
#include "Actor.h"
class Packman :
    public Actor
{
    public:
        Packman(Game* game);
        void Update() override;
    // ~Packman();
};

