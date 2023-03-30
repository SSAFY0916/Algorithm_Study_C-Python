//임의의 두 노드 사이에는 항상 갈수있어야함
//간선들의 합이 최소가 되어야함
//-> MST
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int N,M;
int parent[200001];
int urank[200001];
int ufind(int a){
    if(a==parent[a]) return parent[a];
    return parent[a] = ufind(parent[a]);
}
bool uunion(int a,int b){
    int pa = ufind(a);
    int pb = ufind(b);
    if(pa==pb) return false;
    if(urank[pa]>=urank[pb]){
        urank[pa]+=urank[pb];
        parent[pb]=parent[pa];
    }
    else{
        urank[pb]+=urank[pa];
        parent[pa]=parent[pb];
    }
    return true;
}
int main(){
    while(true){
        scanf("%i%i",&N,&M);
        if(N==0 && M==0) break;
	    for(int x=0;x<=N;x++){
	        parent[x]=x;
	        urank[x]=1;
	    }
	    priority_queue<pair<int,pair<int,int>>> pq;
	    int ans =0;
	    for(int x=0;x<M;x++){
	        int a,b,c;
	        scanf("%i%i%i",&a,&b,&c);
	        pq.push({-c,{a,b}});
	        ans+=c;
	    }
	    while(!pq.empty()){
	        int c = -pq.top().first;
	        int a = pq.top().second.first;
	        int b = pq.top().second.second;
	        pq.pop();
	        if(uunion(a,b)) ans-=c;
	    }
	    printf("%i\n",ans);
    }
}