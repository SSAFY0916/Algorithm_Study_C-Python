#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int solve[2];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int N,M;
bool visit[101][101];
int board[101][101];
int dfs(int sx,int sy){
    if(visit[sx][sy]) return 0;
    visit[sx][sy]=true;
    int ret=1;
    for(int x=0;x<4;x++){
        int nx = dir[x][0]+sx;
        int ny = dir[x][1]+sy;
        if(nx<0 || ny<0 || nx>=N || ny>=M || visit[nx][ny] || board[sx][sy] != board[nx][ny]) continue;
        ret+=dfs(nx,ny);
    }
    return ret;
}
int main(){
    cin>>M>>N;
    for(int x=0;x<N;x++){
        string input;
        cin>>input;
        for(int y=0;y<M;y++){
            if(input[y]=='B') board[x][y] = 1;
        }
    }
    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++){
            int now = dfs(x,y);
            solve[board[x][y]]+=now*now;
        }
    }
    for(int x=0;x<2;x++) cout<<solve[x]<<" ";
}