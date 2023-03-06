#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[100001];
int N,M;
bool chk(long long n){
    long long ret=0;
    for(int x=0;x<N;x++){
        ret+=n/arr[x];
        if(ret>=M) return true;
    }
    return false;
}
int main(){
    scanf("%i%i",&N,&M);
    long long l = 2e15;
    long long r = 2e18;
    for(int x=0;x<N;x++) {
        scanf("%i",&arr[x]);
        l=min(l,(long long)arr[x]);
    }
    while(l<=r){
        long long mid = (l+r)/2;
        if(chk(mid)) r=mid-1;
        else l=mid+1;
    }
    printf("%lli",l);
}