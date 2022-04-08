#include "Packman.h"

Packman::Packman(Game* game)
    :Actor(game){
        mTexture  = GetTexture("Assets/pacman.png");
}