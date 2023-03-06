#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N,M,b;
int board[51][51];
int temp[51][51];
int step[11];
int ans = 2e9;
vector<pair<int,int>> virus;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int go(){
    int t = 0;
    queue<pair<int,pair<int,int>>> q;
    for(int x=0;x<M;x++){
        int nx = virus[step[x]].first;
        int ny = virus[step[x]].second;
        q.push({0,{nx,ny}});
        temp[nx][ny]=-1;
    }
    while(!q.empty()){
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        if(board[cx][cy]==0) t++;
        int dist = q.front().first;
        if(t==b){
            return dist;
        }
        q.pop();
        for(int x=0;x<4;x++){
            int nx = dir[x][0]+cx;
            int ny = dir[x][1]+cy;
            if(nx<0 || ny<0 || nx>=N || ny>=N || temp[nx][ny]==-1 || temp[nx][ny]==1) continue;
            temp[nx][ny]=-1;
            q.push({dist+1,{nx,ny}});
        }
    }
    return 2e9;
}
void dfs(int idx,int prod){
    if(prod==M){
        for(int x=0;x<N;x++){
            for(int y=0;y<N;y++){
                temp[x][y]=board[x][y];
            }
        }
        ans= min(go(),ans);
        return;
        
    }
    for(int x=idx;x<virus.size();x++){
        step[prod]=x;
        dfs(x+1,prod+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            cin>>board[x][y];
            if(board[x][y]==2){
                virus.push_back({x,y});
            }
            if(board[x][y]==0) b++;
        }
    }
    dfs(0,0);
    if(ans==2e9) ans=-1;
    printf("%i",ans);
}