#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int solve[100001];
int main(){
    int N,Q;
    scanf("%i%i",&N,&Q);
    vector<pair<pair<int,int>,int>> vec;
    for(int x=0;x<N;x++){
        int a,b,c;
        scanf("%i%i%i",&a,&b,&c);
        vec.push_back({{a,b},x+1});
    }
    sort(vec.begin(),vec.end());
    int nk = 1;
    int now = vec[0].first.second;
    for(int x=0;x<N;x++){
        if(vec[x].first.first<=now){
            solve[vec[x].second]=nk;
            now = max(now,vec[x].first.second);
        }
        else{
            now = vec[x].first.second;
            solve[vec[x].second]=++nk;
        }
    }
    for(int x=0;x<Q;x++){
        int a,b;
        scanf("%i%i",&a,&b);
        printf("%i\n",(solve[a]==solve[b]));
    }
}