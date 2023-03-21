#include<stdio.h>
#include<algorithm>
using namespace std;
int house[200001];
int N,C;
bool chk(int x){
    int temp=0;
    long long now = house[0];
    for(int i=0;i<N;i++){
        if(now<=house[i]){
            temp++;
            now=max((long long)house[i]+x,now+(long long)x);
        }
    }
    return temp>=C;
}
int main(){
    scanf("%i%i",&N,&C);
    for(int x=0;x<N;x++) scanf("%i",&house[x]);
    sort(house,house+N);
    int l = 1;
    int r = 1e9+1;
    int ans = -1;
    while(l<=r){
        int mid = (l+r)/2;
        if(chk(mid)) {
            l=mid+1;
            ans = max(ans,mid);
        }
        else r=mid-1;
    }
    printf("%i",ans);
}