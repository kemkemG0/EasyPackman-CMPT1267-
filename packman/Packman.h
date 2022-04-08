#pragma once
#include "Actor.h"
class Packman :
    public Actor
{
    public:
        Packman(Game* game, int x, int y);
        void Update() override;
    // ~Packman();
};

