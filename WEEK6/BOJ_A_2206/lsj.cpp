#include<stdio.h>
#include<queue>
using namespace std;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool visit[1001][1001][2];
int N,M;
char board[1001][1001];
int main(){
    scanf("%i%i",&N,&M);
    for(int x=0;x<N;x++) scanf("%s",board[x]);
    queue<pair<pair<int,int>,pair<int,bool>>> q;
    q.push({{0,0},{1,false}});
    int ans = 2e9;
    while(!q.empty()){
        auto now = q.front();
        int cx = now.first.first;
        int cy = now.first.second;
        int dist = now.second.first;
        bool w = now.second.second;
        q.pop();
        if(cx== N-1 && cy==M-1) {
            if(ans>dist) ans = dist;
        }
        for(int x=0;x<4;x++){
            int nx = cx+dir[x][0];
            int ny = cy+dir[x][1];
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(board[nx][ny]=='1' && !w && !visit[nx][ny][1]){
                q.push({{nx,ny},{dist+1,true}});
                visit[nx][ny][1]=true;
            }
            if(board[nx][ny]=='0' && !visit[nx][ny][w]){
                q.push({{nx,ny},{dist+1,w}});
                visit[nx][ny][w]=true;
            }
        }
    }
    if(ans==2e9) ans=-1;
    printf("%i",ans);
}