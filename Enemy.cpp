#include "Enemy.h"


Enemy::Enemy(Game* game,int x,int y,string filename):Actor(game,x,y){
    SetTexture(game->GetTexture(filename),x,y);
    direction=999;
}

void Enemy::Update(){

};