//최대 1000초 & 이동횟수 30회 & 현재 위치 0 or 1-> 1000*30*2의 공간으로 현재 상태를 정의할 수있음
//1초전의 최대값이 현재값의 최대값을 구하는데 활용될수있음 -> 점화식 성립
#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[1002][34][2];
int main(){
    int T,W;
    scanf("%i%i",&T,&W);
    //시간
    for(int x=1;x<=T;x++){
        int input;
        scanf("%i",&input);
        //초기에 자두는 1번에 위치해있음
        if(x==1){
            dp[x][0][0] = (input==1);
            dp[x][1][1] = (input==2);
            continue;
        }
        //이동횟수에 대한 상태 0~W까지
        for(int y=0;y<=W;y++){
            //이전 상태의 위치
            for(int z=0;z<2;z++){
                //현재 상태의 위치
                for(int w=0;w<2;w++){
                    //점화식 y+(z!=w) 현재상태와 이전상태가 다르면 이동횟수 +1   (w==input-1) 현재상태와 지금 자두가 내리는 위치가 같을경우 +1
                    dp[x][y+(z!=w)][w] = max(dp[x-1][y][z]+(w==(input-1)),dp[x][y+(z!=w)][w]);
                }
            }
        }
    }
    int ans  =0;
    for(int x=0;x<=W;x++){
        ans = max(ans,max(dp[T][x][0],dp[T][x][1]));
    }
    printf("%i",ans);
}