#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
#include<vector>
#include<set>
#include<stack>
#include<algorithm>
using namespace std;
map<string,vector<string>> dm;
map<string,set<string>> fm;
map<string,int> fm2;
void dfs(string now){
    for(auto i : dm[now]){
        dfs(i);
        for(auto j : fm[i]){
            fm[now].insert(j);
        }
        fm2[now]+=fm2[i];
    }
}
int main(){
    int N,M;
    cin>>N>>M;
    for(int x=0;x<N+M;x++){
        string a,b;
        int c;
        cin>>a>>b>>c;
        if(c==1){
            dm[a].push_back(b);
        }
        else{
            fm[a].insert(b);
            fm2[a]++;
        }
    }  
    dfs("main");
    int Q;
    cin>>Q;
    while(Q--){
        string input;
        cin>>input;
        string temp="";
        reverse(input.begin(),input.end());
        for(auto i : input){
            if(i=='/') break;
            temp.push_back(i);
        }
        reverse(temp.begin(),temp.end());
        cout<<fm[temp].size()<<" "<<fm2[temp]<<'\n';
    }
}