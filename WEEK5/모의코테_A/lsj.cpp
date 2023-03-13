#include<stdio.h>
using namespace std;
int board[8][8];
int temp[8][8];
bool explode(){
    bool chk[7][7];
    bool ret=false;
    for(int x=0;x<7;x++){
        for(int y=0;y<7;y++) chk[x][y]=false;
    }
    for(int x=0;x<7;x++){
        int cnt =0;
        int cnt2 =0;
        for(int y=0;y<7;y++){
            if(temp[x][y]){
                cnt++;
            }
            else{
                if(cnt==0) continue;
                for(int z=y-1;z>=0;z--){
                    if(!temp[x][z]) break;
                    if(temp[x][z]==cnt) chk[x][z]=true;
                }
                cnt=0;
            }
        }
        for(int y=6;y>=0;y--){
            if(temp[y][x]){
                cnt2++;
            }
            else{
                if(cnt2==0) continue;
                for(int z=y+1;z<7;z++){
                    if(!temp[z][x]) break;
                    if(temp[z][x]==cnt2) chk[z][x]=true;
                }
                cnt2=0;
            }
        }
        if(cnt){
            for(int y=6;y>=0;y--){
                if(!temp[x][y]) break;
                if(temp[x][y]==cnt) chk[x][y]=true;
            }
        }
        if(cnt2){
            for(int y=0;y<7;y++){
                if(temp[y][x]==cnt2) chk[y][x]=true;
            }
        }
    }
    for(int x=0;x<7;x++){
        for(int y=0;y<7;y++){
            if(chk[x][y]){
                ret=true;
                temp[x][y]=0;
            }
        }
    }
    for(int x=5;x>=0;x--){
        for(int y=0;y<7;y++){
            if(temp[x][y]){
                for(int z=x+1;z<=6;z++){
                    if(!temp[z][y]){
                        temp[z][y]=temp[z-1][y];
                        temp[z-1][y]=0;
                    }
                    else break;
                }
            }
        }
    }
    return ret;
}
int main(){
    int drop;
    for(int x=0;x<7;x++){
        for(int y=0;y<7;y++) scanf("%i",&board[x][y]);
    }
    scanf("%i",&drop);
    int ans =  2e9;
    for(int x=0;x<7;x++){
        for(int y=0;y<7;y++){
            for(int z=0;z<7;z++) temp[y][z]=board[y][z];
        }
        for(int y=6;y>=0;y--){
            if(temp[y][x]==0){
                temp[y][x]=drop;
                break;
            }
        }
        while(explode()){}
        int now = 0;
        for(int x=0;x<7;x++){
            for(int y=0;y<7;y++){
                if(temp[x][y]) now++;
            }
        }
        // for(int x=0;x<7;x++){
        //     for(int y=0;y<7;y++){
        //         printf("%i ",temp[x][y]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
        if(ans>now) ans = now;
    }
    printf("%i",ans);
}