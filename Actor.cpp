#include"Actor.h"
#include<assert.h>

Actor::Actor(Game* game):mGame(game){}


void Actor::SetTexture(SDL_Texture* tex){
	mTexture = tex;
	posi_x=100;
	posi_y=100;
	//SDL_QueryTexture(tex,nullptr,nullptr,32,32);
}


void Actor::Draw(SDL_Renderer* renderer){
	assert(mTexture);
	SDL_Rect r;
	// Scale the width/height by owner's scale
	r.w = r.h = 32;
	// Center the rectangle around the position of the owner
	r.x = posi_x;
	r.y = posi_y;
	// Draw (have to convert angle from radians to degrees, and clockwise to counter)
	SDL_RenderCopy(renderer,mTexture,nullptr,&r);
}

void Actor::Update(){
	//up
	if(direction==0){posi_y--;}
	else if(direction==1){posi_y++;}
	else if(direction==2){posi_x--;}
	else if(direction==3){posi_x++;}
}

