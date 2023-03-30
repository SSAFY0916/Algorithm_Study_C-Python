#include <iostream>
#include <queue>
using namespace std;

int p[101];
int d[101];

void bfs()
{
    for(int i = 1; i <= 100; i++)
        d[i] = 100000000;
    queue<int> q;
    d[1] = 0;
    q.push(1);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int i = 1; i <= 6; i++)
        {
            int ncur = cur + i;
            if(ncur <= 100 && p[ncur] == 0)
            {
                if(d[ncur] > d[cur] + 1)
                {
                    q.push(ncur);
                    d[ncur] = d[cur] + 1;
                }
            }
            else if(ncur <= 100 && p[ncur] != 0)
            {
                if(d[p[ncur]] > d[cur] + 1)
                {
                    q.push(p[ncur]);
                    d[p[ncur]] = d[cur] + 1;
                }
                d[ncur] = d[cur] + 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        p[x] = y;
    }
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        p[u] = v;
    }

    bfs();
    cout << d[100];
    return 0;
}