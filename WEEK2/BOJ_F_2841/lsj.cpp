#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
bool visit[7][300001];
int main(){
    stack<int> stk[7];
    int N,M;
    scanf("%i%i",&N,&M);
    int ans =0;
    for(int x=0;x<N;x++){
        int s,f;
        scanf("%i%i",&s,&f);
        if(!stk[s].empty()){
            while(stk[s].top()>f){
                ans++;
                visit[s][stk[s].top()]=false;
                stk[s].pop();
                if(stk[s].empty()) break;
            }
        }
        if(!visit[s][f]){
            ans++;
            stk[s].push(f);
        }
        visit[s][f]=true;
    }
    printf("%i",ans);
}