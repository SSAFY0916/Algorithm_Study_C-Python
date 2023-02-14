#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
char board[1001][1001];
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int x=0;x<n;x++){
        string input;
        cin>>input;
        for(int y=0;y<m;y++){
            board[x][y]=input[y];
        }
    }
    int cgcd = 1e9;
    for(int x=0;x<n;x++){
        int temp=1;
        for(int y=1;y<m;y++){
            if(board[x][y]!=board[x][y-1]){
                if(cgcd==1e9){
                    cgcd = temp;
                }
                else cgcd = gcd(cgcd,temp);
                temp=1;
            }
            else temp++;
        }
        if(cgcd==1e9) cgcd = temp;
        else cgcd = gcd(cgcd,temp);
    } 
    int rgcd = 1e9;
    for(int x=0;x<m;x++){
        int temp=1;
        for(int y=1;y<n;y++){
            if(board[y][x]!=board[y-1][x]){
                if(rgcd==1e9){
                    rgcd = temp;
                }
                else rgcd = gcd(rgcd,temp);
                temp=1;
            }
            else temp++;
        }
        if(rgcd==1e9) rgcd = temp;
        else rgcd = gcd(rgcd,temp);
    }
    cout<<n/rgcd<<" "<<m/cgcd<<'\n';
    for(int x=0;x<n;x+=rgcd){
        for(int y=0;y<m;y+=cgcd){
            cout<<board[x][y];
        }
        cout<<'\n';
    }
}