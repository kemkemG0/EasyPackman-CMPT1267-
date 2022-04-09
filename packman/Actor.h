#pragma once

#include"Game.h"
#include"Stage.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include<utility>

class Actor {
public:
    class Game* mGame;
	Actor(class Game* game,int x,int y);
	// ~Actor();
	int posi_x,posi_y;
	SDL_Texture* mTexture;
	void SetTexture(SDL_Texture*,int x, int y);
    virtual void Draw(SDL_Renderer* renderer);
	virtual void Update()=0;
	bool canChangeDirection();
	bool canMove();
	int direction_reserve;
	int direction;
	int speed=4;
	int previousDirection;

	enum{UP,DOWN,LEFT,RIGHT};
};