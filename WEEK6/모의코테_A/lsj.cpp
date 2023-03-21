#include<stdio.h>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
priority_queue<pair<int,pair<int,int>>> pq[2];
int t[1001][2];
int main(){
    int N,M,T;
    scanf("%i%i%i",&N,&M,&T);
    for(int x=0;x<N;x++){
        int d,m,r;
        scanf("%i%i%i",&d,&m,&r);
        pq[d].push({-r,{-x,m}});
        t[x][0]=2100000000;
    }
    int now=0;
    int nowt = 0;
    while(!pq[0].empty() || !pq[1].empty()){
        //현재 트럭위치 pq가 안비었으면
        if(!pq[now].empty()){
            int temp=0;
            //현재 위치에서 부품을 받을수없을때
            if(-pq[now].top().first>nowt){
                //반대편에 남은 부품이 없을때
                if(pq[1-now].empty()){
                    nowt = -pq[now].top().first;
                    continue;
                }
                else{
                    //반대편은 지금 받을수 있을때
                    if(-pq[1-now].top().first<=nowt){
                        now = 1-now;
                        nowt+=T;
                        continue;
                    }
                    else{
                        //둘다 못받을때 빠른쪽이 받아야함
                        if(-pq[1-now].top().first<-pq[now].top().first){
                            nowt=-pq[1-now].top().first+T;
                            now = 1-now;
                            continue;
                        }
                        else{
                            nowt = -pq[now].top().first;
                            continue;
                        }
                    }
                }
            }
            else{
                //현재위치에서 받을 수 있을때
                int temp = 0;
                while(-pq[now].top().first<=nowt){
                    int nr = -pq[now].top().first;
                    int nm = pq[now].top().second.second;
                    int nx = -pq[now].top().second.first;
                    pq[now].pop();
                    t[nx][0] = min(t[nx][0],nowt);
                    if(temp+nm<=M){
                        t[nx][1]=nowt+T;
                        temp+=nm;
                        if(temp==M) break;
                    }
                    else{
                        pq[now].push({-nr,{-nx,nm-(M-temp)}});
                        temp=M;
                        break;
                    }
                    if(pq[now].empty()) break;
                }
                nowt+=T;
                now = 1-now;
            }
        }
        else{
            //현재 위치가 비면 반대편으로 가야함
            nowt+=T;
            now = 1-now;
            continue;
        }
    }
    for(int x=0;x<N;x++){
        printf("%i %i\n",t[x][0],t[x][1]);
    }
}