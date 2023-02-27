#include<stdio.h>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
int arr[2000000];
int main(){
    int N;
    scanf("%i",&N);
    int ans =0;
    for(int x=1;x<=N;x++){
        int t,p;
        scanf("%i%i",&t,&p);
        arr[x] = max(arr[x],arr[x-1]);
        if(x+t<=N+1) {
            arr[x+t] = max(arr[x+t],arr[x]+p);
            ans = max(ans,arr[x+t]);
        }
    }
    printf("%i",ans);
}