#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string input;
    vector<vector<int>> vec;
    while(true){
        cin>>input;
        if(input[0]=='-') break;
        vector<int> temp(26,0);
        for(auto i : input){
            temp[i-'A']++;
        }
        vec.push_back(temp);
    }
    while(true){
        cin>>input;
        if(input[0]=='#') break;
        vector<int> solve(26,-1);
        int mn = 1e9;
        int mx = 0;
        vector<int> now(26,0);
        for(auto i : input){
            now[i-'A']++;
        }
        for(auto i : input){
            if(solve[i-'A']!=-1) continue;
            int temp=0;
            for(auto j : vec){
                if(j[i-'A']==0) continue;
                bool isc=true;
                for(int x=0;x<26;x++){
                    if(now[x]<j[x]) isc=false;
                }
                if(isc) temp++;
            }
            mx = max(temp,mx);
            mn = min(temp,mn);
            solve[i-'A']=temp;
        }
        for(int x=0;x<26;x++){
            if(mn==solve[x]) {
                cout<<(char)(x+'A');
            }
        }
        cout<<' '<<mn<<' ';
        for(int x=0;x<26;x++){
            if(mx==solve[x]) {
                cout<<(char)(x+'A');
            }
        }
        cout<<' '<<mx<<'\n';
    }
}