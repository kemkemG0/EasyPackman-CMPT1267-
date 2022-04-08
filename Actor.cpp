#include"Actor.h"
#include<assert.h>

Actor::Actor(Game* game,int x, int y):mGame(game){}


void Actor::SetTexture(SDL_Texture* tex, int x, int y){
	mTexture = tex;
	posi_x= 32*x;
	posi_y= 32*y;
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

bool Actor::canChangeDirection(){
	return posi_x%32==0 && posi_y%32==0;
}

bool Actor::canMove(){
	//when left-top corner is in x,y
	int x,y;
	auto stage  = mGame->stage;
	
	
	if(direction==UP){
		return stage->STAGE[posi_x/32][(posi_y-1)/32] != 1;
	}
	else if(direction==DOWN){
		return stage->STAGE[(posi_x)/32][(posi_y+32+1)/32] != 1;
	}
	else if(direction==LEFT){
		return stage->STAGE[(posi_x-1)/32][posi_y/32] != 1;
	}
	else if(direction==RIGHT){
		return stage->STAGE[(posi_x+32+1)/32][posi_y/32] != 1;
	}
	
	return true;
}

