#include<stdio.h>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
char cube[6][9];
string mv[3] = {"FRBL","URDL","UBDF"};
int idx[200];
char ridx[6];
int effect[3][4][2]=
{{{2,-1},{2,-1},{2,-1},{2,-1}},
{{2,-1},{-1,0},{0,-1},{-1,2}},
{{-1,2},{-1,0},{-1,2},{-1,2}}};
int crot[9]={6,3,0,7,4,1,8,5,2};
int rot[9]={2,5,8,1,4,7,0,3,6};
void mvcube(string command){
    int side = idx[command[0]];
    int dir = idx[command[1]];
    if(side%2==1) dir=1-dir;
    string now_mv = mv[side/2];
    char temp[6][9];
    for(int x=0;x<6;x++){
        for(int y=0;y<9;y++){
            temp[x][y]=cube[x][y];
        }
    }
    for(int x=3*dir;x!=(4-5*dir); x+=(-2*dir+1)){
        int nx = (x+(-2*dir+1)+4)%4;
        int curside = idx[now_mv[x]];
        int nxside = idx[now_mv[nx]];
        //cout<<ridx[curside]<<"->"<<ridx[nxside]<<'\n';
        for(int y=0;y<3;y++){
            int cr = y/3;
            int cc = y%3;
            if(side/2==0){
                temp[nxside][y+(side%2==0)*6]=cube[curside][y+(side%2==0)*6];
            }
            if(side/2==1){
                int ny = y;
                if(nx+x==3) ny=2-ny;
                int ecr = side%2==0 ? effect[side/2][x][0] : 2-effect[side/2][x][0];
                int ecc = side%2==0 ? effect[side/2][x][1] : 2-effect[side/2][x][1];
                int enr = side%2==0 ? effect[side/2][nx][0] : 2-effect[side/2][nx][0];
                int enc = side%2==0 ? effect[side/2][nx][1] : 2-effect[side/2][nx][1];
                int cr = ecr==-1 || ecr==3 ? y : ecr;
                int cc = ecc== -1 || ecc==3? y: ecc;
                int nr = enr==-1 || enr==3 ? ny: enr;
                int nc = enc==-1 || enc==3 ? ny: enc;
                //cout<<cr<<" "<<cc<<" -> "<<nr<<" "<<nc<<'\n';
                temp[nxside][nr*3+nc] = cube[curside][cr*3+cc];
                
            }
            if(side/2==2){
                if(nxside==3 || curside==3){
                    if(nxside==3) temp[nxside][2*(side%2==1)+(2-y)*3]=cube[curside][(2-2*(side%2==1))+y*3];
                    else temp[nxside][2*(side%2==0)+(2-y)*3]=cube[curside][(2-2*(side%2==0))+y*3];
                }
                else{
                    temp[nxside][(2-2*(side%2==1))+3*y]=cube[curside][(2-2*(side%2==1))+3*y];
                }
            }
        }
        for(int y=0;y<9;y++){
            if(command[1]=='+'){
                temp[side][rot[y]]=cube[side][y];
            }
            else{
                temp[side][crot[y]]=cube[side][y];
            }
        }
    }
    for(int x=0;x<6;x++){
        for(int y=0;y<9;y++){
            cube[x][y]=temp[x][y];
        }
    }
}
int main(){
    string k = "DUFBRL";
    string colour = "ywrobg";
    for(int x=0;x<k.size();x++){
        idx[k[x]]=x;
        ridx[x]=k[x];
    } 

    idx['-']=1; //3 -1
    idx['+']=0; //0 4
    int T;
    cin>>T;
    while(T--){   
        for(int x=0;x<6;x++){
            for(int y=0;y<9;y++){
                cube[x][y]=colour[x];
                }
        }
        int n;
        cin>>n;
        for(int x=0;x<n;x++){
            string command;
            cin>>command;
            mvcube(command);
        }
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                cout<<cube[idx['U']][x*3+y];
            }
            cout<<'\n';
        }
    }
}