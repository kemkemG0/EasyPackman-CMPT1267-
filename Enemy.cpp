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
    
    assert(!path.empty());
    
    int next_direction=path.top();

    //consume same directions
    while(1){
        if(path.empty())break;
        int t = path.top();path.pop();
        if(next_direction!=t){
            path.push(t);
            break;
        }
    }

    if(posi_x%32==0 && posi_y%32==0){
        //didn't use this time
        direction = next_direction;
        count++;
    }else path.push(next_direction);
    
	if(direction==UP && canMove()){posi_y-=speed;}
	else if(direction==DOWN&& canMove()){posi_y+=speed;}
	else if(direction==LEFT&& canMove()){posi_x-=speed;}
	else if(direction==RIGHT&& canMove()){posi_x+=speed;}


    //セル単位でまずダイクストラして、UDLR形式でパスをゲット(予約する感じ)
    //曲がれるところまで来たら(32の倍数)popしていく

}