#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int visit[3000002];
int arr[3000001];
int main(){
    int N,d,k,c;
    cin>>N>>d>>k>>c;
    int solve=0;
    for(int x=0;x<N;x++){
        cin>>arr[x];
        if(x<k){
            if(!visit[arr[x]]){
                solve++;
            }
            visit[arr[x]]++;
        }
    }
    int temp=solve;
    solve+=(visit[c]==0);
    for(int x=1;x<N;x++){
        visit[arr[x-1]]--;
        if(!visit[arr[x-1]]){
            temp--;
        }
        int nx=x+k-1 >= N ? x+k-1-N : x+k-1;
        if(!visit[arr[nx]]){
            temp++;
        }
        visit[arr[nx]]++;
        solve=max(temp+(visit[c]==0),solve);
    }
    cout<<solve;
}