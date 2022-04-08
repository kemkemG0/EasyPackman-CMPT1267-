// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Game.h"
#include "SDL/SDL_image.h"
#include <algorithm>
 #include "SDL/SDL_mixer.h"
 #include "Stage.h"
 #include "Actor.h"
 #include "Packman.h"
 #include "Enemy.h"
#include<iostream>

Game::Game()	
:mWindow(nullptr)
,mRenderer(nullptr)
,mIsRunning(true)
,mUpdatingActors(false)
{
	
}


bool Game::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}
	
	mWindow = SDL_CreateWindow("Easy Packman(final project)", 100, 100, 768, 768, 0);
	if (!mWindow)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}
	
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!mRenderer)
	{
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return false;
	}
	
	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		SDL_Log("Unable to initialize SDL_image: %s", SDL_GetError());
		return false;
	}

	LoadData();

	mTicksCount = SDL_GetTicks();

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	stage = new Stage;

	mActors.push_back(new Packman(this,3,22));
	mActors.push_back(new Enemy(this,10,22,"Assets/blue.png"));
	mActors.push_back(new Enemy(this,15,22,"Assets/red.png"));
	mActors.push_back(new Enemy(this, 8, 22, "Assets/purple.png"));

	srand(time(NULL));

	return true;
}

void Game::RunLoop()
{
	while (mIsRunning)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}

void Game::ProcessInput()
{
	SDL_Event event;
	auto packman = mActors[0];
	packman->previousDirection = packman->direction;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT) mIsRunning = false;
		else if (event.type == SDL_KEYDOWN){
			switch (event.key.keysym.sym){
				case SDLK_UP:
				if(packman->previousDirection==packman->DOWN || packman->canChangeDirection())
					packman->direction=0;
					break;
				case SDLK_DOWN:
				if(packman->previousDirection==packman->UP || packman->canChangeDirection())
					packman->direction=1;
					break;
				case SDLK_LEFT:
				if(packman->previousDirection==packman->RIGHT || packman->canChangeDirection())
					packman->direction=2;
					break;
				case SDLK_RIGHT:
				if(packman->previousDirection==packman->LEFT || packman->canChangeDirection())
					packman->direction=3;
					break;
			}
		}
	}
}

bool Game::isGameOver(){
	int px = mActors[0]->posi_x;
	int py = mActors[0]->posi_y;
	for(int i=1;i<mActors.size();++i){

		int ex = mActors[i]->posi_x;
		int ey = mActors[i]->posi_y;
		if(abs(px-ex)<32 && abs(py-ey)<32)return true;
	}
	return false;
}


void Game::UpdateGame()
{
	// Compute delta time
	// Wait until 16ms has elapsed since last frame
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 64));

	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
	if (deltaTime > 0.05f)deltaTime = 0.05f;
	mTicksCount = SDL_GetTicks();

	for (auto actor : mActors){
		actor->Update();
	}

	mIsRunning = !isGameOver();
	
}

void Game::GenerateOutput()
{
	//bg?
	SDL_SetRenderDrawColor(mRenderer, 220, 220, 220, 255);
	SDL_RenderClear(mRenderer);

	stage->DrawStage(mRenderer);

	for(auto actor:mActors){
		actor->Draw(mRenderer);
	}

	SDL_RenderPresent(mRenderer);
}

void Game::Shutdown()
{
	IMG_Quit();
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}


void Game::LoadData(){}

SDL_Texture* Game::GetTexture(const std::string& fileName)
{
	SDL_Texture* tex = nullptr;
	// Is the texture already in the map?
	auto iter = mTextures.find(fileName);
	if (iter != mTextures.end())
	{
		tex = iter->second;
	}
	else
	{
		// Load from file
		SDL_Surface* surf = IMG_Load(fileName.c_str());
		if (!surf)
		{
			// SDL_Log("Failed to load texture file %s", fileName.c_str());
			std::cout<<fileName<<" not found\n";
			return nullptr;
		}

		// Create texture from surface
		tex = SDL_CreateTextureFromSurface(mRenderer, surf);
		SDL_FreeSurface(surf);
		if (!tex)
		{
			SDL_Log("Failed to convert surface to texture for %s", fileName.c_str());
			return nullptr;
		}

		mTextures.emplace(fileName.c_str(), tex);
	}
	return tex;
}