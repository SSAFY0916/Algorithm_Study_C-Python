#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<pair<int, int>, int> ele;

int map[1001][1001];
int dr[4] = {1, 0, 0, -1};
int dc[4] = {0, 1, -1, 0};
int visit[1001][1001][2];
int d[1001][1001];

void bfs(int n, int m)
{
    queue<ele> q;
    q.push({{0, 0}, 0});
    d[0][0] = 1;

    while(!q.empty())
    {
        ele cur = q.front();
        int cr = cur.first.first;
        int cc = cur.first.second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(visit[nr][nc][cur.second] == 0 && cur.second == 0)
            {
                if(map[nr][nc] == 0)
                {
                    visit[nr][nc][cur.second] = 1;
                    d[nr][nc] = d[cr][cc] + 1;
                    q.push({{nr, nc}, 0});
                }
                else
                {
                    visit[nr][nc][1] = 1;
                    d[nr][nc] = d[cr][cc] + 1;
                    q.push({{nr, nc}, 1});
                }
            }
            else if(map[nr][nc] == 0 && visit[nr][nc][cur.second] == 0 && cur.second == 1)
            {
                visit[nr][nc][cur.second] = 1;
                d[nr][nc] = d[cr][cc] + 1;
                q.push({{nr, nc}, 1});
            }
            if(nr == n - 1 && nc == m - 1) return;
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
        string tmp;
        cin >> tmp;
        for(int j = 0; j < m; j++)
            map[i][j] = tmp[j] - '0';
    }

    bfs(n, m);
    if(d[n - 1][m - 1] == 0) cout << -1;
    else cout << d[n - 1][m - 1];
    return 0;
}