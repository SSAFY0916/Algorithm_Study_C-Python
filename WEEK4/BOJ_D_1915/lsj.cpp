#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
int N,M,ans;
char board[1001][1001];
int prefix[1001][1001];
int main(){
    scanf("%i%i",&N,&M);
    for(int x=0;x<N;x++){
        scanf("%s",board[x]);
        for(int y=0;y<M;y++){
            if(board[x][y]=='1') prefix[x][y]=1;
            ans = max(ans,prefix[x][y]);
        }
    }
    for(int x=1;x<N;x++){
        for(int y=1;y<M;y++){
            if(board[x][y]=='1') {
                int t= min(prefix[x-1][y],prefix[x][y-1]);
                if(board[x-t][y-t]=='1') prefix[x][y]=t+1;
                else prefix[x][y]=max(1,t);
            }
            ans = max(ans,prefix[x][y]*prefix[x][y]);
        }
    }
    printf("%i",ans);
}