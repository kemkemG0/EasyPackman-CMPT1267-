#include "Enemy.h"
#include <assert.h>

Enemy::Enemy(Game* game,int x,int y,string filename):Actor(game,x,y){
    SetTexture(game->GetTexture(filename),x,y);
    count=0;
}

void Enemy::Update(){

    // assert(posi_x%32==0 || posi_y%32==0);
    if(path.empty() || count==30){
        count=0;
        getPath();
    };

    count++;
    
    assert(!path.empty());
    


    if(posi_x%32==0 && posi_y%32==0){
        cout<<"!!POP!!"<<endl;
        direction = path.top();
        //didn't use this time
        path.pop();
    }
    if(!canMove())return;

    if(direction==UP ){posi_y-=speed;}
	else if(direction==DOWN){posi_y+=speed;}
	else if(direction==LEFT){posi_x-=speed;}
	else if(direction==RIGHT){posi_x+=speed;}



}