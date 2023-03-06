#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>> vec;
int dp[101];
int main(){
    int N;
    scanf("%i",&N);
    for(int x=0;x<N;x++){
        int a,b;
        scanf("%i%i",&a,&b);
        vec.push_back({a,b});
    }
    sort(vec.begin(),vec.end());
    int ans =N;
    for(int x=0;x<N;x++){
        for(int y=x-1;y>=0;y--){
            if(vec[y].second<vec[x].second){
                dp[x] = max(dp[y]+1,dp[x]);
            }
        }
        dp[x] = max(dp[x],1);
        ans = min(ans,N-dp[x]);
    }
    printf("%i",ans);
}