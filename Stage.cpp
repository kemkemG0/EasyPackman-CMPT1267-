#include"Stage.h"
#include"MyMacros.h"
#include<iostream>
#include<assert.h>
using namespace std;

void Stage::DrawStage(SDL_Renderer* render) {
	int tile;
	REP(i, 24)REP(j, 24) {
		tile = STAGE[i][j];
		SDL_Rect pixel = { i * 32,j * 32, 32, 32 };
		if (tile==1) {
			SDL_SetRenderDrawColor(render, 0, 0, 128, 0);
		}
		else SDL_SetRenderDrawColor(render, 255, 255, 255, 0xFF);
		SDL_RenderFillRect(render, &pixel);
	};
}