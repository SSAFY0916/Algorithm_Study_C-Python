#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int arr[21][21];
bool bound[21][21];
int N;
int sum;
int mkbound(int sx,int sy,int d1,int d2){
    int ret=0;
    for(int x=0;x<=d1;x++){
        int nx = sx+x;
        int ny = sy-x;
        if(nx<0 || ny<0 || nx>=N || ny>=N){
            if(x==0) return -1;
            break;
        }
        ret+=arr[nx][ny];
        bound[nx][ny]=true;
    }
    for(int x=0;x<=d2;x++){
        int nx = sx+x;
        int ny = sy+x;
        if(nx<0 || ny<0 || nx>=N || ny>=N){
            if(x==0) return -1;
            break;
        }
        ret+=arr[nx][ny];
        bound[nx][ny]=true;
    }
    for(int x=0;x<=d2;x++){
        int nx = sx+d1+x;
        int ny = sy-d1+x;
        if(nx<0 || ny<0 || nx>=N || ny>=N){
            if(x==0) return -1;
            break;
        }
        ret+=arr[nx][ny];
        bound[nx][ny]=true;
    }
    for(int x=0;x<=d1;x++){
        int nx = sx+d2+x;
        int ny = sy+d2-x;
        if(nx<0 || ny<0 || nx>=N || ny>=N){
            if(x==0) return -1;
            break;
        }
        ret+=arr[nx][ny];
        bound[nx][ny]=true;
    }
    return ret;
}
int cal(int lx,int rx,int ly,int ry,bool isleft){
    int ret=0;
    if(isleft){
        for(int x=lx;x<rx;x++){
            for(int y=ly;y<ry;y++){
                if(bound[x][y]) break;
                ret+=arr[x][y];
            }
        }
    }
    else{
        for(int x=lx;x<rx;x++){
            for(int y=ry-1;y>=ly;y--){
                if(bound[x][y]) break;\
                ret+=arr[x][y];
            }
        }
    }
    return ret;
}
void init_bound(){
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++) bound[x][y]=false;
    }
}
int main(){
    cin>>N;
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            cin>>arr[x][y];
            sum+=arr[x][y];
        }
    }
    int ans=2e9;
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            for(int z=1;z<N;z++){
                for(int w=1;w<N;w++){
                    init_bound();
                    int bounds = mkbound(x,y,z,w);
                    if(bounds==-1){
                        break;
                    }
                    int mn = 2e9;
                    int mx = -2e9;
                    int a1 = cal(0,x+z,0,y+1,true);
                    int a2 = cal(0,x+w+1,y+1,N,false);
                    int a3 = cal(x+z,N,0,y-z+w,true);
                    int a4 = cal(x+w+1,N,y-z+w,N,false);
                    int a5 = sum-a1-a2-a3-a4;
                    mn = min(min(min(a1,a2),min(a3,a4)),min(a5,mn));
                    mx = max(max(max(a1,a2),max(a3,a4)),max(a5,mx));
                    ans=min(ans,mx-mn);
                }
            }
        }
    }
    cout<<ans;
}