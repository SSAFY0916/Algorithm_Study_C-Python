//DFS를 통해 접근할 생각이 떠올랐음 작은 범위들때문 낼수있는 가짓수 최대 10
//승리횟수 최대범위 6 경기수 20 또한 매번 경기를 하지 않음 1
//또한 중복될수 있는 상태가 존재할수있다고 생각했음 -> 방문배열로 현재상태 모두기록
//손동작의 중복체크는 비트마스킹을 사용함
//18*18*7*7*7*1024 = 대략 1억1000만
//현재 누구턴인지는 세사람의 승리수 지우가 여태까지 낸 손동작으로 결정된다고 생각함
//자기가 낼 손동작을 순열로 만드는 방법도 괜찮을듯 
#include<stdio.h>
#include<algorithm>
using namespace std;
int fight[10][10];
int pred[21][2];
int N,K;
bool victory;
bool visit[21][7][7][7][1024][4];
//턴 0 -> 지우 1-> 경희 2-> 민호
void dfs(int a,int b,int c,int turn,int bt,int sb,int sc){
    if(visit[sb][sc][a][b][c][bt] || victory) return;
    visit[sb][sc][a][b][c][bt]=true;
    if(a==K || b==K || c==K){
        if(a==K) victory=true;
        return;
    }
    if(turn!=3){
        for(int x=0;x<N;x++){
            if(bt & (1<<x)) continue;
            if(turn == 1){
                if(fight[pred[sb][0]][x]){
                    dfs(a,b+1,c,3,bt|(1<<x),sb+1,sc);
                }
                else dfs(a+1,b,c,3-turn,bt | (1<<x),sb+1,sc);
            }
            else{
                if(fight[pred[sc][1]][x]){
                    dfs(a,b,c+1,3,bt|(1<<x),sb,sc+1);
                }
                else dfs(a+1,b,c,3-turn,bt|(1<<x),sb,sc+1);
            }
        }
    }
    else{
        if(fight[pred[sc][1]][pred[sb][0]]){
            dfs(a,b,c+1,2,bt,sb+1,sc+1);
        }
        else dfs(a,b+1,c,1,bt,sb+1,sc+1);
    }
}
int main(){
    scanf("%i%i",&N,&K);
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            scanf("%i",&fight[x][y]);
        }
    }
    for(int x=0;x<2;x++){
        for(int y=0;y<20;y++) {
            scanf("%i",&pred[y][x]);
            pred[y][x]--;
        }
    }
    dfs(0,0,0,1,0,0,0);
    printf("%i",victory);
}