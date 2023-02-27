#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int N;
string input;
long long dp[21][2];
int main(){
    cin>>N>>input;
    dp[0][0]=input[0]-'0';
    dp[0][1]=input[0]-'0';
    for(int x=2;x<N;x+=2){
        int nx = input[x]-'0';
        int nxx = input[x-2]-'0';
        if(input[x-1]=='+'){
            dp[x][0] = dp[x-2][0]+nx;
            dp[x][1] = dp[x-2][1]+nx;
            nxx+=nx;
        }
        if(input[x-1]=='-'){
            dp[x][0] = dp[x-2][0]-nx;
            dp[x][1] = dp[x-2][1]-nx;
            nxx-=nx;
        }
        if(input[x-1]=='*'){
            dp[x][0] = max(dp[x-2][0]*nx,dp[x-2][1]*nx);
            dp[x][1] = min(dp[x-2][0]*nx,dp[x-2][1]*nx);
            nxx*=nx;
        }
        if(x>2){
            if(input[x-3]=='+'){
                dp[x][0] = max(dp[x][0],dp[x-4][0]+nxx);
                dp[x][1] = min(dp[x][1],dp[x-4][1]+nxx);
            }
            if(input[x-3]=='-'){
                dp[x][0] = max(dp[x][0],dp[x-4][0]-nxx);
                dp[x][1] = min(dp[x][1],dp[x-4][1]-nxx);
            }
            if(input[x-3]=='*'){
                dp[x][0] = max(dp[x][0],max(dp[x-4][0]*nxx,dp[x-4][1]*nxx));
                dp[x][1] = min(dp[x][1],min(dp[x-4][0]*nxx,dp[x-4][1]*nxx));
            }
        }
    }
    cout<<dp[N-1][0];
}