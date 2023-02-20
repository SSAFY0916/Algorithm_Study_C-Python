#include <iostream>
#include <queue>
using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int visit[1001][1001];
int ret[1001][1001];

void bfs(int n, int m, int startR, int startC)
{
    queue<pair<int, int>> co;
    int distance = 0;

    for(int i = 0; i < n; i++)
        fill(visit[i], visit[i] + m, 0);

    co.push(make_pair(startR, startC));
    ret[startR][startC] = distance;
    visit[startR][startC] = 1;
    while(!co.empty())
    {
        pair<int, int> tmpCo = co.front();
        co.pop();
        
        for(int i = 0; i < 4; i++)
        {
            distance = ret[tmpCo.first][tmpCo.second];
            if(tmpCo.first + dr[i] >= n || tmpCo.first + dr[i] < 0
                || tmpCo.second + dc[i] >= m || tmpCo.second + dc[i] < 0) continue;
            else if(visit[tmpCo.first + dr[i]][tmpCo.second + dc[i]] == 1) continue;
            else if(ret[tmpCo.first + dr[i]][tmpCo.second + dc[i]] == -1)
            {
                co.push(make_pair(tmpCo.first + dr[i], tmpCo.second + dc[i]));
                visit[tmpCo.first + dr[i]][tmpCo.second + dc[i]] = 1;
                ret[tmpCo.first + dr[i]][tmpCo.second + dc[i]] = ++distance;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, startR, startC;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int tmp;

            cin >> tmp;
            if(tmp == 2)
            {
                startR = i;
                startC = j;
            }
            else if(tmp == 1) ret[i][j] = -1;
            else if(tmp == 0) ret[i][j] = 0;
        }
    }

    bfs(n, m, startR, startC);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << ret[i][j] << " ";
        cout << "\n";
    }
    return 0;
}