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
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    std::stack<int> path;

    int count;


    void bfs(){
        const auto stage = mGame->stage->STAGE;
        const int gx = mGame->mActors[0]->posi_x/32;
        const int gy = mGame->mActors[0]->posi_x/32;
        const int sx = posi_x/32,sy = posi_y/32;

        dis = vector<vector<int>>(24,vector<int>(24,1000));
        assert(sx<24 && sy<24 && gy<24 && gx<24);
        dis[sx][sy]=0;

        std::queue<pair<int,int>> q;
        q.push({sx,sy});
        while(!q.empty()){
            pair<int,int> now = q.front();q.pop();
            REP(i,4){
                int nx = now.first+dx[i];
                int ny = now.second+dy[i];
                if(nx<0 ||ny<0 || nx>=24 ||ny>=24 || stage[nx][ny]==1)continue;
                if(dis[nx][ny]!=1000)continue;
                dis[nx][ny] = dis[now.first][now.second]+1;
                q.push({nx,ny});
            }
        }
        // REP(i,24){
        //     REP(j,24){
        //         cout<<dis[i][j]<<"  ";
        //     }
        //     cout<<endl;
        // };
        // exit(1);
        
        pair<int,int> now={gx,gy};
        assert(dis[gx][gy]!=1000);
        // get path from g->s
        int min=100000;
        while(1){
            REP(i,4){
                const int nx = now.first+dx[i];
                const int ny = now.second+dy[i];
                if(nx<0 ||ny<0 || nx>=24 ||ny>=24)continue;
                if(dis[nx][ny]<min){
                    min=dis[nx][ny];

                    //right
                    if(dx[i]==1){
                        path.push(RIGHT);
                    }

                    //left
                    else if(dx[i]==-1){
                        path.push(LEFT);
                    }

                    //up
                    else if(dy[i]==-1){
                        path.push(UP);
                    }

                    //down
                    else if(dy[i]==1){
                        path.push(DOWN);
                    }
                    now={nx,ny};
                cout<<nx<<" "<<ny<<" "<<dis[nx][ny]<<endl;
                }
                if(nx==sx && ny==sy)return;
            }
        }
    }

    void getPath(){
        bfs();
        // using dijkstra, get first some step of the shortest path to packman
        // and compress it
        // RRUPDDDDDDLL  -> RUPDL

    }
};

