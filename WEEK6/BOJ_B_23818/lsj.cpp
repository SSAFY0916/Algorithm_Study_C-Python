#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N,M,K;
//N이 100000이므로 N^2의 탐색을 하면 안된다. ex)그래프탐색중 방문 여부와 상관없이 모든 인접노드를 탐색하는 방법
//그래프 탐색을 친구간선을 통해 탐색하며 친구관계를 구할수있다.
//이외의 친구관계 성립은 A<->B 원수 B<->C 원수 A<->C 친구
//A<->B 원수 B<->C친구 A<->C원수 C의 원수들은 A의 친구가됨
//첫시작 원소 BFS를 통해 구해보자 현재상태 친구, 원수 
//친구상태 간선-친구 친구상태   친구상태 간선-원수 원수상태
//원수상태 간선-친구 원수상태   원수상태 간선-원수 친구상태
//BFS방문배열을 visit[노드번호][친구/원수상태] = 시작원소
int visit[100001][2];
vector<vector<pair<int,int>>> E(100001,vector<pair<int,int>>());
int main(){
    scanf("%i%i%i",&N,&M,&K);
    //간선추가
    for(int x=0;x<M;x++){
        int t,a,b;
        scanf("%i%i%i",&t,&a,&b);
        E[a].push_back({t,b});
        E[b].push_back({t,a});
    }
    for(int x=1;x<=N;x++){
        //만약 현재배열이 방문했을경우(한 연결요소를 탐색했으면 스킵해야함 -> 시간복잡도)
        if(visit[x][0] || visit[x][1]){
           continue; 
        }
        queue<pair<int,pair<int,int>>> q;
        //초기 푸쉬 {현재노드,{현재상태,시작노드}}
        q.push({x,{0,x}});
        visit[x][0]=x;
        while(!q.empty()){
            auto now = q.front();
            q.pop();
            for(auto i : E[now.first]){
                //현재상태와 간선에따라 다음상태를 정의
                int nxstate = (now.second.first+i.first)%2;
                if(!visit[i.second][nxstate]) {
                    q.push({i.second,{nxstate,now.second.second}});
                    visit[i.second][nxstate] = now.second.second;
                }
            }
        }
    }
    for(int x=0;x<K;x++){
        int a,b;
        scanf("%i%i",&a,&b);
        int fa = visit[a][0];
        int ea = visit[a][1];
        int fb = visit[b][0];
        int eb = visit[b][1];
        //시작노드가 다를때 -> 연결관계가없음
        if(max(fa,ea)!=max(fb,eb)){
            printf("Unknown\n");
            continue;
        }
        bool f = false;
        //서로의 친구가 같을때 -> 친구관계
        if(fa&&fb){
            if(fa==fb) f=true;
        }
        //서로의 원수가 같을때 -> 친구관계
        if(ea&&eb){
            if(ea==eb) f=true;
        }
        bool e = false;
        //서로의 친구와 원수가 같을때 -> 원수
        if(fa && eb){
            if(fa==eb) e=true;
        }
        if(fb && ea){
            if(fb==ea) e=true;
        }
        if(f && !e) printf("Friend\n");
        else if(!f && e) printf("Enemy\n");
        else printf("Error\n");
        
    }
}