#include "Enemy.h"
#include <assert.h>

Enemy::Enemy(Game* game,int x,int y,string filename):Actor(game,x,y){
    SetTexture(game->GetTexture(filename),x,y);
    count=0;
}

void Enemy::Update(){
    
    if(path.empty() || count==10){
        count=0;
        getPath();
    };
    
    count++;
    
    assert(!path.empty());
    direction = path.top();


    if(posi_x%32==0 && posi_y%32==0){
        //didn't use this time
        path.pop();
    }

    if(direction==UP ){posi_y-=speed;}
	else if(direction==DOWN){posi_y+=speed;}
	else if(direction==LEFT){posi_x-=speed;}
	else if(direction==RIGHT){posi_x+=speed;}



}