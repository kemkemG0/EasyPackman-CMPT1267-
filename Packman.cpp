#include "Packman.h"
#include<assert.h>

Packman::Packman(Game* game,int x,int y)
    :Actor(game,x,y){
    SetTexture(game->GetTexture("Assets/packman.png"),x,y);
    direction=999;
	direction_reserve = 999;
}

void Packman::Update(){
    //up
	canChangeDirection();
	assert(posi_x%32==0 || posi_y%32==0);

	if(posi_x%32==0 && posi_y%32==0) direction = direction_reserve;

	if(direction==UP && canMove()){ posi_y-=speed;}
	else if(direction==DOWN&& canMove()){posi_y+=speed;}
	else if(direction==LEFT&& canMove()){posi_x-=speed;}
	else if(direction==RIGHT&& canMove()){posi_x+=speed;}
}