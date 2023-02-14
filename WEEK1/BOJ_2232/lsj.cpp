#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
int arr[50001];
bool visited[50001];
int main(){
    int N;
    scanf("%i",&N);
    priority_queue<pair<int,int>> pq;
    int temp=0;
    for(int x=1;x<=N;x++){
        scanf("%i",&arr[x]);
        pq.push({arr[x],x});
    }
    vector<int> solve;
    while(temp<N){
        auto now = pq.top();
        pq.pop();
        if(visited[now.second]) continue;
        int t = now.first;
        temp++;
        solve.push_back(now.second);
        visited[now.second]=true;
        for(int x = now.second-1;x>=1;x--){
            if(t>arr[x] && !visited[x]){
                visited[x]=true;
                temp++;
                t=arr[x];
            }
            else break;
        }
        t=now.first;
        for(int x = now.second+1;x<=N;x++){
            if(t>arr[x] && !visited[x]){
                visited[x]=true;
                temp++;
                t=arr[x];
            }
            else break;
        }
    }
    sort(solve.begin(),solve.end());
    for(auto i: solve){
        printf("%i ",i);
    }
}