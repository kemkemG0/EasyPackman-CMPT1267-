#include "Packman.h"

Packman::Packman(Game* game)
    :Actor(game){
        SetTexture(game->GetTexture("Assets/packman.png"));
        
}