#include"Stage.h"
#include"MyMacros.h"
#include<iostream>
#include<assert.h>
using namespace std;

void Stage::DrawStage(SDL_Renderer* render) {
	int tile;
	REP(i, 24)REP(j, 24) {
		tile = STAGE[i][j];
		SDL_Rect pixel = { j * 32,i * 32, 32, 32 };
		if (tile==1) {
			SDL_SetRenderDrawColor(render, 72, 61, 139, 0);
			SDL_RenderFillRect(render, &pixel);
		}
		else {
			SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
			SDL_RenderFillRect(render, &pixel);
			
			SDL_Rect middle = { j * 32 + 14,i * 32 + 14, 2, 2 };
			SDL_SetRenderDrawColor(render, 255, 228, 225, 0xFF);
			SDL_RenderFillRect(render, &middle);

		}

		

	};
}