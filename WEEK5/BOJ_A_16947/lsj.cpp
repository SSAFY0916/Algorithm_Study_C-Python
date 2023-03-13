#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int indegree[3001];
bool visit[3001];
bool chk[3001];
int dist[3001];
vector<vector<int>> E(3001,vector<int>());
bool iscycle;
void dfs(int now,int d,int start){
    if(visit[now]) return;
    visit[now]=true;
    for(int i  : E[now]){
        if(i==start && d>1){
            iscycle=true;
            break;
        }
        dfs(i,d+1,start);
    }
}
void dfs2(int now,int d){
    if(visit[now]) return;
    visit[now]=true;
    dist[now]=d;
    for(int i  : E[now]){
        if(!chk[i]){
            dfs2(i,d+1);
        }
    }
}
int main(){
    int N;
    scanf("%i",&N);
    for(int x=0;x<N;x++){
        int s,d;
        scanf("%i%i",&s,&d);
        E[s].push_back(d);
        E[d].push_back(s);
        indegree[s]++;
        indegree[d]++;
    }
    for(int x=1;x<=N;x++){
        for(int y=1;y<=N;y++){
            visit[y]=false;
        }
        iscycle=false;
        dfs(x,0,x);
        chk[x] = iscycle;
    }
    for(int x=1;x<=N;x++){
        for(int y=1;y<=N;y++){
            visit[y]=false;
        }
        if(chk[x] && indegree[x]>=3) dfs2(x,0);
    }
    for(int x=1;x<=N;x++){
        printf("%i ",dist[x]);
    }
}