#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[3001];
int visit[3001] = {0};
int bfsVisit[3001] = {0};
int pre[3001] = {0};
int d[3001] = {0};
bool CFinish = false;
queue<int> q;

void bfs()
{   
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < (int)adj[cur].size(); i++)
        {
            int next = adj[cur][i];
            if(bfsVisit[next] != 1)
            {
                d[next] = d[cur] + 1;
                bfsVisit[next] = 1;
                q.push(next);
            }
        }
    }
}

void dfsCycleDetect(int cur)
{
    visit[cur] = 1;
    for(int i = 0; i < (int)adj[cur].size(); i++)
    {
        if(CFinish) break;
        int next = adj[cur][i];
        if(visit[next] == 1)
        {
            if(next != pre[cur])
            {
                CFinish = true;
                q.push(cur);
                bfsVisit[cur] = 1;
                while(cur != next)
                {
                    cur = pre[cur];
                    q.push(cur);
                    bfsVisit[cur] = 1;
                }
                break;
            }
        }
        else
        {
            pre[next] = cur;
            dfsCycleDetect(next);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfsCycleDetect(1);
    bfs();
    for(int i = 1; i <= n; i++)
        cout << d[i] << " ";
    return 0;
}