#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int A,B,N,M;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int idx[200];
int robot[101][3];
int visit[101][101];
int main(){
    cin>>A>>B>>N>>M;
    idx['N']=0;
    idx['E']=1;
    idx['S']=2;
    idx['W']=3;
    for(int x=1;x<=N;x++){
        int cx,cy;
        char cd;
        cin>>cx>>cy>>cd;
        robot[x][0]=cx;
        robot[x][1]=cy;
        robot[x][2]=idx[cd];
        visit[cx][cy]=x;
    }
    for(int x=0;x<M;x++){
        int r,d;
        char com;
        cin>>r>>com>>d;
        int nowd = robot[r][2];
        if(com=='F'){
            for(int y=0;y<d;y++){
                int nx = robot[r][0]+dir[nowd][0];
                int ny = robot[r][1]+dir[nowd][1];
                if(nx<1 || nx>A || ny<1 || ny>B){
                    printf("Robot %i crashes into the wall",r);
                    return 0;
                }
                if(visit[nx][ny]){
                    printf("Robot %i crashes into robot %i",r,visit[nx][ny]);
                    return 0;
                }
                visit[nx][ny]=r;
                visit[robot[r][0]][robot[r][1]]=0;
                robot[r][0]=nx;
                robot[r][1]=ny;
            }
        }
        if(com=='R'){
            robot[r][2]+=d;
            robot[r][2]%=4;
        }
        if(com=='L'){
            robot[r][2]-=d-800;
            robot[r][2]%=4;
        }
    }
    printf("OK");
}