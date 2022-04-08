#include"Actor.h"


Actor::Actor(Game* game):mGame(game){
	

}


void Actor::SetTexture(SDL_Texture* tex){
	mTexture = tex;
	//SDL_QueryTexture(tex,nullptr,nullptr,32,32);
}