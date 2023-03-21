//꼭짓점이 나오는 방향(?)이 항상같다 -> 0번인덱스는 항상 (0,0) 이후 1번인덱스부터 (n,n+1) n+=2 ->항상 수평성분
//구멍 또한 항상 위에서 구한 수평성분에 위치한다.
//물이빠지는 조건 : 현재 수평성분 기준 양옆으로 탐색 현재 위치 h  h = min(h,현재 탐색중인 위치의 높이);
//탐색중 구멍이 나오게 되면 높이 h가 수면의 높이가됨 -> 현재 탐색중인 수평성분 가로길이 * (현재수평성분높이 -h)만큼 물이 담긴다.
#include<stdio.h>
#include<vector>
#include<set>
using namespace std;
int main(){
    //구멍인지 체크하기 위한 set -> 검색이 빠름
    set<pair<int,int>> hole;
    //초기 입력 꼭짓점을 저장하기 위한 배열
    vector<pair<int,int>> point;
    //수평성분의 배열 {{왼쪽,오른쪽},{높이,구멍여부(0구멍없음 1 구멍있음)}}
    vector<pair<pair<int,int>,pair<int,int>>> hr;
    int N,K,ans;
    ans = 0;
    scanf("%i",&N);
    int mx = 0;
    for(int x=0;x<N;x++){
        int a,b;
        scanf("%i%i",&a,&b);
        point.push_back({a,b});
        mx = max(a,mx);
    }
    scanf("%i",&K);
    for(int x=0;x<K;x++){
        int a,b,c,d;
        scanf("%i%i%i%i",&a,&b,&c,&d);
        //수평성분에 구멍이 위치하는지 알기 위해서 좌우측 좌표만 알면됨
        hole.insert({a,c});
    }
    hr.push_back({{-2,0},{0,1}});
    for(int x=1;x<N;x+=2){
        int l,r,y;
        l = point[x].first;
        r = point[x+1].first;
        y = point[x].second;
        //현재 수평선분에 구멍체크
        bool ishole = (hole.find({l,r})!=hole.end());
        hr.push_back({{l,r},{y,ishole}});
    }
    hr.push_back({{mx,mx+2},{0,1}});
    for(int x=0;x<hr.size();x++){
        //구멍일때 스킵
        if(hr[x].second.second) continue;
        int lh = hr[x].second.first;
        //왼쪽으로 탐색
        for(int y=x-1;y>=0;y--){
            lh = min(lh,hr[y].second.first);
            if(hr[y].second.second) break;
        }
        int rh = hr[x].second.first;
        //오른쪽으로 탐색
        for(int y=x+1;y<hr.size();y++){
            rh = min(rh,hr[y].second.first);
            if(hr[y].second.second) break;
        }
        ans += (hr[x].first.second - hr[x].first.first)* (hr[x].second.first-max(lh,rh));
    }
    printf("%i",ans);
}