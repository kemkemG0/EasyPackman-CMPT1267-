#include "Packman.h"

Packman::Packman(Game* game)
    :Actor(game){
    SetTexture(game->GetTexture("Assets/packman.png"));
    direction=999;
}

void Packman::Update(){
    //up
	if(direction==UP){posi_y--;}
	else if(direction==DOWN){posi_y++;}
	else if(direction==LEFT){posi_x--;}
	else if(direction==RIGHT){posi_x++;}
}