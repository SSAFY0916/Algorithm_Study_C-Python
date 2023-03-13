#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
string input,p;
int il,pl;
bool solve;
void dfs(int idx,int depth,int idx2){
    if(idx==il && idx2==pl){
        solve=true;
        return;
    }
    if(input[idx]=='('){
        dfs(idx+1,depth+1,idx2);
        int temp=0;
        for(int x = idx+1;x<il;x++){
            if(input[x]=='(') temp++;
            if(input[x]==')') temp--;
            if(temp==-1) break;
            if(temp!=0) continue;
            if(input[x]=='|'){
                dfs(x+1,depth+1,idx2);
            }
        }
        return;
    }
    if(depth){
        if(input[idx]==')') dfs(idx+1,depth-1,idx2);
        else{
            if(input[idx]=='|'){
                int temp=0;
                for(int x=idx+1;x<il;x++){
                    if(input[x]=='(') temp++;
                    if(input[x]==')') temp--;
                    if(temp==-1){
                        dfs(x+1,depth-1,idx2);
                        break;
                    }
                }
            }
            else{
                if(p[idx2]!=input[idx]) return;
                dfs(idx+1,depth,idx2+1);
            }
        }
    }
    else{
        if(p[idx2]!=input[idx]) return;
        dfs(idx+1,depth,idx2+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        char ans ='_';
        cin>>input>>p;
        il = input.size();
        pl=p.size();
        int hidx=0;
        for(int x=0;x<il;x++){
            if(input[x]=='_') hidx=x;
        }
        int now = 0;
        for(char k ='A';k<='Z';k++){
            solve=false;
            input[hidx]=k;
            dfs(0,0,0);
            if(solve){
                now++;
                ans = k;
            } 
        }
        if(now>=2){
            cout<<'_'<<'\n';
        }
        else if(now==1){
            cout<<ans<<'\n';
        }
        else{
            cout<<'!'<<'\n';
        }
    }
}