#include<stdio.h>
#include<vector>
#include<queue>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
bool visit[8][8][65];
int board[8][8];
int temp[8][8];
int dir[9][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
vector<vector<vector<int>>> vec;
int vs;
int N = 8;
bool chk(){
    bool ret = false;
    vs++;
    for(int x=7;x>=0;x--){
        for(int y=0;y<8;y++){
            if(temp[x][y]){
                ret=true;
                if(x==7) temp[x][y]=0;
                else{
                    temp[x+1][y]=1;
                    temp[x][y]=0;
                }
            }
        }
    }
    vector<vector<int>> now(8,vector<int>());
    for(int x=0;x<8;x++){
        for(int y=0;y<8;y++){
            now[x].push_back(temp[x][y]);
        }
    }
    vec.push_back(now);
    return ret;
}
int main(){
    vector<vector<int>> now(8,vector<int>());
    for(int x=0;x<N;x++){
        string input;
        cin>>input;
        for(int y=0;y<N;y++){
            if(input[y]=='#') board[x][y]=1;
            else board[x][y]=0;
            now[x].push_back(board[x][y]);
            temp[x][y]=board[x][y];
        }
    }
    vec.push_back(now);
    while(chk());
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{7,0}});
    while(!q.empty()){
        int t = q.front().first;
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        q.pop();
        if(cx==0 && cy==7){
            printf("1");
            return 0;
        }
        if(vec[min(t,vs)][cx][cy]==1) continue;
        for(int x=0;x<9;x++){
            int nx = dir[x][0]+cx;
            int ny = dir[x][1]+cy;
            if(nx<0 || ny<0 || nx>=N || ny>=N || visit[nx][ny][t] || vec[min(t,vs)][nx][ny]==1) continue;
            visit[nx][ny][t]=true;
            q.push({t+1,{nx,ny}});
        }
    }
    printf("0");
}