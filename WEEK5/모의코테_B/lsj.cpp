#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int cost[10001];
bool visit[10001];
int dp[10001][2];
vector<vector<int>> E(10001,vector<int>());
int ans =0;
void dfs(int now){
    if(visit[now]) return;
    visit[now]=true;
    dp[now][1]=cost[now];
    for(auto i: E[now]){
        if(visit[i]) continue;
        dfs(i);
        dp[now][0]+=max(dp[i][1],dp[i][0]);
        dp[now][1]+=dp[i][0];
    }
}
int main(){
    int N;
    scanf("%i",&N);
    for(int x=1;x<=N;x++) scanf("%i",&cost[x]);
    for(int x=0;x<N;x++){
        int src,dst;
        scanf("%i%i",&src,&dst);
        E[src].push_back(dst);
        E[dst].push_back(src);
    }
    dfs(1);
    printf("%i",max(dp[1][0],dp[1][1]));
}