//과목수는 1000 최대 공부시간은 10000
//따라서 O(1000*10000)으로 해결할 수 있는 알고리즘을 떠올렸음
//중요도가 최대가 되도록 과목을 선택하면서 선택한 과목들의 시간은 일정합을 넘으면 안됨
//-> 냅색문제의 접근방법 따라서 knapsack dp
#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[10001];
int main(){
    int N,K;
    int ans =0;
    scanf("%i%i",&N,&K);
    for(int x=0;x<K;x++){
        int i,t;
        scanf("%i%i",&i,&t);
        for(int y=N;y>=0;y--){
            if(dp[y] && y+t<=N){
                dp[y+t] = max(dp[y]+i,dp[y+t]);
            }
        }
        dp[t] = max(dp[t],i);
    }
    for(int x=N;x>=0;x--) ans=  max(ans,dp[x]);
    printf("%i",ans);
}