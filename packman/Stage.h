#ifndef __STAGE__CPP
#define __STAGE__CPP
#include "SDL/SDL.h"
#include"MyMacros.h"
#include<iostream>
using namespace std;

class Stage{
public:
	void DrawStage(SDL_Renderer* render);
	enum{WALL,ROAD};
	int STAGE[24][24];
	Stage() {
		//768%32 = 24
		int stage[24][24]= {

		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,0,1,0,1},
		{1,0,1,0,1,1,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,1,0,1},
		{1,0,1,0,1,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1},
		{1,0,1,0,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1},
		{1,0,1,0,1,0,1,1,0,1,0,1,1,0,0,0,0,1,1,1,0,1,0,1},
		{1,0,0,0,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,1},
		{1,0,1,0,0,0,1,1,0,1,1,0,1,0,1,1,0,1,1,1,0,1,0,1},
		{1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,1,0,1,1,0,1,1,0,1,0,1,1,1,0,1,1,0,1,0,1},//
		{1,0,1,0,1,0,1,1,0,1,1,0,1,0,1,1,1,0,1,1,0,1,0,1},//
		{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,1,0,1,1,0,1,1,0,1,0,1,0,1,0,1,1,0,1,0,1},
		{1,0,0,0,1,0,1,1,0,1,1,0,0,0,1,0,1,0,1,1,0,1,0,1},
		{1,0,1,0,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,1},
		{1,0,1,0,1,0,1,1,0,1,1,0,1,1,1,0,1,0,0,1,0,0,0,1},
		{1,0,1,0,1,0,1,1,0,1,1,0,1,1,1,0,1,1,1,1,0,1,0,1},
		{1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,1,0,1,0,1,1,0,1,1,0,1,1,0,1,0,1,0,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		};
		REP(i, 24)REP(j, 24)STAGE[i][j] = stage[i][j];
	}
	
};

#endif