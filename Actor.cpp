#include"Actor.h"
#include<assert.h>

Actor::Actor(Game* game):mGame(game){}


void Actor::SetTexture(SDL_Texture* tex){
	mTexture = tex;
	//SDL_QueryTexture(tex,nullptr,nullptr,32,32);
}


void Actor::Draw(SDL_Renderer* renderer){
	assert(mTexture);
	SDL_Rect r;
	// Scale the width/height by owner's scale
	r.w = 32;
	r.h = 32;
	// Center the rectangle around the position of the owner
	r.x = 10;
	r.y = 10;
	// Draw (have to convert angle from radians to degrees, and clockwise to counter)
	SDL_RenderCopy(renderer,mTexture,nullptr,&r);
}

