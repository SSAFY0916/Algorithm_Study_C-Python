#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
string s="CIRTRISQUYELREDBLUGRAWHIBLA";
int p[10];
bool chk[1025];
bool ishap(int a,int b,int c){
    int bt = p[a-1] | p[b-1] | p[c-1];
    for(int x=0;x<3;x++){
        int cnt =0;
        for(int y=0;y<3;y++){
            if(bt&(1<<(3*x+y))) cnt++;
        }
        if(cnt==0 || cnt==2) return false;
    }
    return true;
}
int main(){
    for(int x=0;x<9;x++){
        for(int y=0;y<3;y++){
            string input;
            cin>>input;
            for(int z=0;z<27;z+=3){
                if(s.substr(z,3)==input.substr(0,3)){
                    p[x]+=(1<<(z/3));
                }
            }
        }
    }
    for(int x=1;x<10;x++){
        for(int y=x+1;y<10;y++){
            for(int z=y+1;z<10;z++){
                int bt = 1<<(x-1) | 1<<(y-1) | 1<<(z-1);
                if(ishap(x,y,z)){
                    chk[bt]=true;
                }
            }
        }
    }
    int n;
    cin>>n;
    int score=0;
    bool g=true;
    for(int x=0;x<n;x++){
        string i;
        int a,b,c;
        cin>>i;
        if(i[0]=='H'){
            cin>>a>>b>>c;
            int bt = 1<<(a-1) | 1<<(b-1) | 1<<(c-1);
            if(chk[bt]) score++;
            else score--;
            chk[bt]=false;
        }
        else{
            if(g){
                bool isg=true;
                for(int x=1;x<1025;x++){
                    if(chk[x]) isg=false;
                }
                if(isg){
                    score+=3;
                    g=false;
                    continue;
                }
            }
            score--;
        }
    }
    cout<<score;
}