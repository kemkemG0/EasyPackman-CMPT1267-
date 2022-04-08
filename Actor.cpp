#include"Actor.h"


Actor::Actor(Game* game):mGame(game){}


void Actor::SetTexture(SDL_Texture* tex){
	mTexture = tex;
	//SDL_QueryTexture(tex,nullptr,nullptr,32,32);
}

SDL_Texture* Actor::GetTexture(const std::string& fileName)
{
	SDL_Texture* tex = nullptr;
	
	// Load from file
	SDL_Surface* surf = IMG_Load(fileName.c_str());
	if (!surf)
	{
		SDL_Log("Failed to load texture file %s", fileName.c_str());
		return nullptr;
	}

	// Create texture from surface
	tex = SDL_CreateTextureFromSurface(mGame->mRenderer, surf);
	SDL_FreeSurface(surf);
	if (!tex)
	{
		SDL_Log("Failed to convert surface to texture for %s", fileName.c_str());
		return nullptr;
	}

	return tex;
}