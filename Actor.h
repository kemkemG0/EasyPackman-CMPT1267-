#pragma once

#include"Game.h"
#include"Stage.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include<utility>

class Actor {
public:
    class Game* mGame;
	Actor(class Game* game);
	// ~Actor();
	int posi_x,posi_y;
	SDL_Texture* mTexture;
	void SetTexture(SDL_Texture*);
    virtual void Draw(SDL_Renderer* renderer);
	virtual void Update()=0;
	bool canChangeDirection();
	bool canMove();
	int direction;
	int speed=8;
	int previousDirection;

	enum{UP,DOWN,LEFT,RIGHT};
};