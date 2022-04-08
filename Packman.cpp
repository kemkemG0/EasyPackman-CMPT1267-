#include "Packman.h"

Packman::Packman(Game* game)
    :Actor(game){
    SetTexture(game->GetTexture("Assets/packman.png"));
    direction=999;
}

void Packman::Update(){
	// cout << posi_x / 32 << " " << posi_y / 32 << " "<<posi_x << " " << posi_y <<" "<<mGame->stage->STAGE[posi_x / 32][posi_y / 32]<< endl;
    //up
	if(direction==UP && canMove()){posi_y-=speed;}
	else if(direction==DOWN&& canMove()){posi_y+=speed;}
	else if(direction==LEFT&& canMove()){posi_x-=speed;}
	else if(direction==RIGHT&& canMove()){posi_x+=speed;}
}