#include "Packman.h"

Packman::Packman(Game* game,int x,int y)
    :Actor(game,x,y){
    SetTexture(game->GetTexture("Assets/packman.png"),x,y);
    direction=999;
}

void Packman::Update(){
	// cout<<direction<<endl;
	// cout << posi_y / 32 << " " << posi_x / 32 << " "<<posi_y << " " << posi_x <<" "<<mGame->stage->STAGE[posi_y / 32][posi_x / 32]<< endl;
    //up
	if(direction==UP && canMove()){posi_y-=speed;}
	else if(direction==DOWN&& canMove()){posi_y+=speed;}
	else if(direction==LEFT&& canMove()){posi_x-=speed;}
	else if(direction==RIGHT&& canMove()){posi_x+=speed;}
}