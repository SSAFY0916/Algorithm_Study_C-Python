#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
int smell[6][6];
int dir[8][2] ={{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
vector<vector<vector<int>>> grid(4,vector<vector<int>>(4,vector<int>()));
int main(){
    int M,S;
    cin>>M>>S;
    int sx,sy;
    for(int x=0;x<M;x++){
        int r,c,d;
        cin>>r>>c>>d;
        grid[r-1][c-1].push_back(d-1);
    }
    cin>>sx>>sy;
    sx--;
    sy--;
    for(int t=1;t<=S;t++){
        //상어가 복제마법을 시전
        auto temp =grid;
        //움직일 벡터
        vector<vector<vector<int>>> mv(4,vector<vector<int>>(4,vector<int>()));
        for(int x=0;x<4;x++){
            for(int y=0;y<4;y++){
                for(auto fish : grid[x][y]){
                    bool ismove=false;
                    for(int z=fish;z>fish-8;z--){
                        int nowd = (z+16)%8;
                        int nx = x+dir[nowd][0];
                        int ny = y+dir[nowd][1];
                        if(nx<0 || ny<0 || nx>=4 || ny>=4 || smell[nx][ny] || (nx==sx && ny==sy)) continue;
                        mv[nx][ny].push_back(nowd);
                        //cout<<nx<<" "<<ny<<'\n';
                        ismove=true;
                        break;
                    }
                    if(!ismove) mv[x][y].push_back(fish);
                }
            }
        }
        //상어의 이동
        int mx = -1;
        vector<int> sarr;
        for(int x=2;x>-6;x-=2){
            for(int y=2;y>-6;y-=2){
                for(int z=2;z>-6;z-=2){
                    int nx1 = dir[(x+8)%8][0]+sx;
                    int ny1 = dir[(x+8)%8][1]+sy;
                    int nx2 = nx1+dir[(y+8)%8][0];
                    int ny2 = ny1+dir[(y+8)%8][1];
                    int nx3 = nx2+dir[(z+8)%8][0];
                    int ny3 = ny2+dir[(z+8)%8][1];
                    vector<int> now_shark_mv = {nx1,ny1,nx2,ny2,nx3,ny3};
                    bool cango=true;
                    for(auto i : now_shark_mv){
                        if(i<0 || i>=4) cango=false;
                    }
                    if(!cango) continue;
                    int cnt =0;
                    cnt+=mv[nx1][ny1].size();
                    if(nx1!= nx2 || ny2!=ny1) cnt+=mv[nx2][ny2].size();
                    if((nx3!= nx2 || ny3!=ny2) && (nx3!= nx1 || ny3!=ny1)) cnt+=mv[nx3][ny3].size();
                    if(cnt>mx){
                        mx=cnt;
                        sarr = now_shark_mv;
                    }
                }
            }
        }
        //사라지는 물고기 제외 벡터
        vector<vector<vector<int>>> result_shark(4,vector<vector<int>>(4,vector<int>()));
        //잡은애빼고 옮겨담기
        for(int x=0;x<4;x++){
            for(int y=0;y<4;y++){
                bool isshark=false;
                for(int z=0;z<6;z+=2){
                    if(x==sarr[z] && y==sarr[z+1]) isshark=true;
                }
                if(isshark){
                    if(mv[x][y].size()>0) {
                        smell[x][y]=t;
                    }
                    continue;
                }
                for(auto fish : mv[x][y]){
                    result_shark[x][y].push_back(fish);
                }
            }
        }
        //상어 옮기기
        sx = sarr[4];
        sy = sarr[5];
        //냄새사라지기
        for(int x=0;x<4;x++){
            for(int y=0;y<4;y++){
                if(smell[x][y]==t-2) smell[x][y]=0;
            }
        }
        //복제
        for(int x=0;x<4;x++){
            for(int y=0;y<4;y++){
                for(auto fish : temp[x][y]) result_shark[x][y].push_back(fish);
            }
        }
        //결과 옮겨담기
        grid = result_shark;
    }
    int ans = 0;
    for(int x=0;x<4;x++){
        for(int y=0;y<4;y++) ans+=grid[x][y].size();
    }
    cout<<ans;
    //상어가 복제마법을 시전
    //모든 물고기가 한 칸 이동한다. 상어가 있는 칸, 물고기의 냄새가 있는 칸
    //, 격자의 범위를 벗어나는 칸으로는 이동할 수 없다.
   // 각 물고기는 자신이 가지고 있는 이동 방향이 이동할 수 있는 칸을 향할 때까지 
    //방향을 45도 반시계 회전시킨다. 만약, 이동할 수 있는 칸이 없으면 이동을 하지 않는다.
    //그 외의 경우에는 그 칸으로 이동을 한다. 물고기의 냄새는 아래 3에서 설명한다.
}