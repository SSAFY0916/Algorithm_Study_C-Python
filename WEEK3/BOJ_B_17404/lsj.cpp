#include<stdio.h>
#include<iostream>
using namespace std;
int arr[1001][3];
int dp[1001][3];
int N;
int main(){
    cin>>N;
    int ans = 2e9;
    for(int x=0;x<N;x++){
        for(int y=0;y<3;y++) cin>>arr[x][y];
    }
    for(int x=0;x<3;x++){
        for(int y=0;y<N;y++){
            for(int z=0;z<3;z++) dp[y][z] = 2e9;
        }
        dp[0][x]=arr[0][x];
        for(int y=1;y<N;y++){
            for(int z=0;z<3;z++){
                for(int w=0;w<3;w++){
                    if(z==w) continue;
                    if(y==N-1){
                        if(z==x) continue;
                    }
                    dp[y][z] = min(dp[y][z],arr[y][z]+dp[y-1][w]);
                }
            }
        }
        for(int x=0;x<3;x++) ans = min(ans,dp[N-1][x]);
    }
    cout<<ans;
}