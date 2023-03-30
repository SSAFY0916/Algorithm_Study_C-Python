#include<stdio.h>
#include<iostream>
using namespace std;
int snake[101];
int ladder[101];
int visit[101];
void dfs(int now,int dist){
    if(now>100) return;
    if(visit[now]<=dist) return;
    visit[now]=dist;
    if(ladder[now]){
        dfs(ladder[now],dist);
        return;
    }
    if(snake[now]){
        dfs(snake[now],dist);
        return;
    }
    for(int x=1;x<=6;x++){
        dfs(now+x,dist+1);
    }
}
int main(){
    int N,M;
    cin>>N>>M;
    for(int x=0;x<N;x++){
        int a,b;
        cin>>a>>b;
        ladder[a]=b;
    }
    for(int x=0;x<M;x++){
        int a,b;
        cin>>a>>b;
        snake[a]=b;
    }
    for(int x=0;x<=100;x++) visit[x] = 2e9;
    dfs(1,0);
    cout<<visit[100];
}