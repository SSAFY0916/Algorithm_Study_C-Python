#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int arr[1001];
int main(){
    int n,m;
    cin>>n>>m;
    for(int x=0;x<n;x++) cin>>arr[x];
    sort(arr,arr+n);
    int ans = 0;
    for(int x=0;x<n;x++){
        if(arr[x]%10==0){
            if(m>=arr[x]/10-1){
                m-=arr[x]/10-1;
                ans+=(arr[x]/10);
            }
            else{
                ans+=m;
                m=0;
            }
        }
    }
    for(int x=0;x<n;x++){
        if(arr[x]%10!=0){
            if(m>=arr[x]/10){
                m-=arr[x]/10;
                ans+=arr[x]/10;
            }
            else{
                ans+=m;
                m=0;
            }
        }
    }
    cout<<ans;
}