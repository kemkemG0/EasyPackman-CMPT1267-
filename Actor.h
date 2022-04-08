#include"Game.h"
#include"Stage.h"
#include "SDL/SDL.h"

class Actor {
    public:
    class Game* mGame;
	Actor(class Game* game);
	~Actor();

    public:
	double x,y;
	SDL_Texture* mTexture;


	void SetTexture(SDL_Texture*);


};