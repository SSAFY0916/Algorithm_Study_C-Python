#include<string>
#include<iostream>
using namespace std;
int arr[52][52];
int main(){
    int N,M;
    cin>>N>>M;
    int ans = N*M;
    for(int x=1;x<=N;x++){
        string input;
        cin>>input;
        for(int y=1;y<=M;y++){
            if(input[y-1]=='-') arr[x][y] = 1;
            else arr[x][y] =2;
        }
    }
    for(int x=1;x<=N;x++){
        for(int y=1;y<=M;y++){
            if(arr[x][y]==arr[x-1][y] && arr[x][y]==2) ans--;
            if(arr[x][y-1]==arr[x][y] && arr[x][y]==1) ans--;
        }
    }
    cout<<ans;
}