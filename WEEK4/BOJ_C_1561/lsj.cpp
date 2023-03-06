#include<stdio.h>
#include<iostream>
using namespace std;
long long arr[10001];
long long N,M;
long long chk(long long a){
    long long ret=0;
    for(int x=0;x<M;x++){
        ret+=a/arr[x];
    }
    return ret;
}
int main(){
    cin>>N>>M;
    for(int x=0;x<M;x++){
        cin>>arr[x];
    }
    if(N<=M){
        cout<<N;
    }
    else{
        long long l =0 ;
        long long r = N*M*31L;
        while(l<=r){
            long long mid = (l+r)/2L;
            if(chk(mid)<(N-M)){
                l=mid+1;
            }
            else r=mid-1;
        }
        long long remain = chk(l)-(N-M);
        for(int x=M;x>=1;x--){
            if(l%arr[x-1]==0){
                if(remain==0){
                    cout<<x;
                    break;
                }
                remain--;
            }
        }
    }
}