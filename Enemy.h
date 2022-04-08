#pragma once
#include "Actor.h"
class Enemy :
    public Actor
{
    public:
    Enemy(Game* game,int x,int y,string filename);
    void Update() override;
};

