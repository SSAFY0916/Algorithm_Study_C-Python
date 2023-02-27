#include<stdio.h>
#include<vector>
#include<queue>
#include<string>
#include<iostream>
#include<set>
using namespace std;
string ms[5];
bool chk[5][9];
int btidx[5][9];
int bt[6];
bool used[13];
bool solve=false;
vector<pair<int,int>> vec;
void dfs(int now){
    int nowx = vec[now].first;
    int nowy = vec[now].second;
    if(now==12){
        for(int x=0;x<6;x++){
            if(bt[x]!=26) return;
        }
        solve=true;
        return;
    }
    if(chk[nowx][nowy]){
        dfs(now+1);
        return;
    }
    for(int x=1;x<=12;x++){
        if(used[x]) continue;
        bool isbt=false;
        for(int y=0;y<6;y++){
            if(((1<<y) & btidx[nowx][nowy])){
                if(bt[y]+x >26 ) {
                    isbt=true;
                    break;
                }
            }
        }
        if(isbt) continue;
        for(int y=0;y<6;y++){
            if(((1<<y) & btidx[nowx][nowy])){
                bt[y]+=x;
            }
        }
        used[x]=true;
        ms[nowx][nowy]=(char)((x-1)+'A');
        dfs(now+1);
        if(solve) return;
        used[x]=false;
        for(int y=0;y<6;y++){
            if(((1<<y) & btidx[nowx][nowy])){
                bt[y]-=x;
            }
        }
    }
}
int main(){
    for(int x=0;x<4;x++){
        btidx[x][4+x] = btidx[x][4+x] | (1<<0);
        btidx[x][4-x] = btidx[x][4-x] | (1<<1);
        btidx[1+x][1+x] = btidx[1+x][1+x] | (1<<2);
        btidx[1][1+2*x] = btidx[1][1+2*x] | (1<<3);
        btidx[3][1+2*x] = btidx[3][1+2*x] | (1<<4);
        btidx[4-x][4+x] = btidx[4-x][4+x] | (1<<5);
    }
    for(int x=0;x<5;x++){
        cin>>ms[x];
        for(int y=0;y<9;y++){
            if(ms[x][y]!='x' && ms[x][y]!='.') {
                chk[x][y]=true;
                used[ms[x][y]-'A'+1]=true;
                for(int z=0;z<6;z++){
                    if((1<<z) & btidx[x][y]){
                        bt[z]+=ms[x][y]-'A'+1;
                    }
                }
            }
            if(ms[x][y]!='.'){
                vec.push_back({x,y});
            }
        }
    }
    dfs(0);
    for(int x=0;x<5;x++){
        cout<<ms[x]<<'\n';
    }
}