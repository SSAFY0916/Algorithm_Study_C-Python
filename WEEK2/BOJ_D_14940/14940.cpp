#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;
int arr[1001][1001];
int ans[1001][1001];
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int main(){
    int N,M;
    cin>>N>>M;
    int sx,sy;
    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++){
            cin>>arr[x][y];
            if(arr[x][y]==2){
                sx=x;
                sy=y;
            }
        }
    }
    queue<pair<pair<int,int>,int>> q;
    q.push({{sx,sy},0});
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        for(int x=0;x<4;x++){
            int nx = now.first.first+dir[x][0];
            int ny = now.first.second +dir[x][1];
            if(nx<0 || ny<0 || nx>=N || ny>=M || arr[nx][ny]!=1 || ans[nx][ny]!=0) continue;
            ans[nx][ny]=now.second+1;
            q.push({{nx,ny},ans[nx][ny]});
        }
    }
    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++){
            if(arr[x][y]==1 && ans[x][y]==0) ans[x][y]=-1;
            cout<<ans[x][y]<<" ";
        }
        cout<<'\n';
    }
}