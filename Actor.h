#include"Game.h"
#include"Stage.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class Actor {
public:
    class Game* mGame;
	Actor(class Game* game);
	// ~Actor();
	double x,y;
	SDL_Texture* mTexture;
	void SetTexture(SDL_Texture*);
    SDL_Texture* GetTexture(const std::string& fileName);
};