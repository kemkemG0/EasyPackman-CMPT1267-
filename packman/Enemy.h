#pragma once
#include "Actor.h"
#include<stack>
#include<queue>
#include"MyMacros.h"
#include<assert.h>


class Enemy :
    public Actor
{
    public:
    Enemy(Game* game,int x,int y,string filename);
    void Update() override;

    vector<vector<int>> dis;
    int dy[4]={0,1,0,-1};
    int dx[4]={1,0,-1,0};
    std::stack<int> path;

    int count;

    void bfs(){
        const auto stage = mGame->stage->STAGE;
        const int gy = mGame->mActors[0]->posi_y/32;
        const int gx = mGame->mActors[0]->posi_x/32;
        const int sy = this ->posi_y/32;
        const int sx = this->posi_x/32;

        dis = vector<vector<int>>(24,vector<int>(24,1000));
        assert(sx<24 && sy<24 && gy<24 && gx<24);
        dis[sy][sx]=0;

        std::queue<pair<int,int>> q;
        q.push({sy,sx});
        while(!q.empty()){
            pair<int,int> now = q.front();q.pop();
            REP(i,4){
                int ny = now.first+dy[i];
                int nx = now.second+dx[i];
                if(nx<0 ||ny<0 || nx>=24 ||ny>=24 || stage[ny][nx]==1)continue;
                if(dis[ny][nx]!=1000)continue;
                dis[ny][nx] = dis[now.first][now.second]+1;
                q.push({ny,nx});
            }
        }

        pair<int,int> now={gy,gx};
        // assert(dis[gy][gx]!=1000);
        // get path from g->s
        int min=100000;

        while(1){
            REP(i,4){
                const int ny = now.first+dy[i];
                const int nx = now.second+dx[i];
                if(nx<0 ||ny<0 || nx>=24 ||ny>=24 || dis[ny][nx]==1000)continue;
                if(nx==sx && ny==sy){
                    return;
                }
                if(dis[ny][nx]<min){
                    min=dis[ny][nx];


                    //!!!! MUST BE OPPOSIT!!!!
                    //right
                    if(dx[i]==1){
                        path.push(LEFT);
                    }
                    //left
                    else if(dx[i]==-1){
                        path.push(RIGHT);
                    }
                    //up
                    else if(dy[i]==-1){
                        path.push(DOWN);
                    }
                    //down
                    else if(dy[i]==1){
                        path.push(UP);
                    }
                    now={ny,nx};
                    break;
                
                }
            }
        }
    }

    void getPath(){
        bfs();
    }
};

