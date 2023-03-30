//점화식을 세워야함
//짝수번째에서만 어떤 형태가 만들어지는걸 알 수 있음
//너비2짜리 2x1 2x1 2x1 /2x1 1x2 1x2 /1x2 1x2 2x1 
//너비4짜리 너비 2짜리가 아닌 경우의수는 2*1 2*1 1*2 2*1 2*1 1*2
//너비4이상인 형태는 첫열과 마지막열이 1*2가 아닌이상 너비2의 조합이랑 같음
//너비 4이상인 형태는 해당너비에서 고유함 
//너비2 는 3 너비4는 3*3 + 2
//너비 N에서의 dp[N]은 dp[N] = (3*dp[N-2] + (너비 4짜리)2* dp[N-4]+ 2*dp[N-6]...
#include<stdio.h>
long long dp[31];
int main(){
    int N;
    scanf("%i",&N);
    dp[2]=3;
    for(int x=4;x<=30;x+=2){
        dp[x]= 3*dp[x-2];
        for(int y=4;y<x;y+=2){
            dp[x]+=dp[x-y]*2;
        }
        dp[x]+=2LL;
    }
    printf("%lli",dp[N]);
}
