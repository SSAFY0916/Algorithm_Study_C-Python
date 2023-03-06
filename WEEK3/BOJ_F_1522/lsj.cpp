#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string a;
    cin>>a;
    int N = a.size();
    int ans = N;
    int b=0;
    for(auto i : a){
        if(i=='b') b++;
    }
    for(int x=0;x<N;x++){
        int temp=0;
        for(int y=x;y<x+b;y++){
            if(a[y%N]=='b') temp++;
        }
        ans= min(ans,b-temp);
    }
    cout<<ans;
}