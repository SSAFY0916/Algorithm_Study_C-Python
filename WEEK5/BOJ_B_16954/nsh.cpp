#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> co;
char map[8][8];
int dr[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
int dc[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

void bfs()
{
    queue<co> q;
    int visit[8][8] = {0};
    q.push({7, 0});

    for(int i = 0; i < 8; i++)
    {
        if(!q.empty())
        {
            int qSize = (int)q.size();
            for(int i = 0; i < 8; i++)
                for(int j = 0; j < 8; j++)
                    visit[i][j] = 0;
            for(int j = 0; j < qSize; j++)
            {
                co cur = q.front();
                q.pop();
                if(map[cur.first][cur.second] == '#') continue;

                for(int k = 0; k < 9; k++)
                {
                    int nr = cur.first + dr[k];
                    int nc = cur.second + dc[k];
                    if(nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && visit[nr][nc] == 0)
                    {
                        if(map[nr][nc] == '.')
                        {
                            q.push({nr, nc});
                            visit[nr][nc] = 1;
                        }
                    }
                }
            }

            for(int j = 7; j >= 1; j--)
                for(int k = 0; k < 8; k++)
                    map[j][k] = map[j - 1][k];
            for(int j = 0; j < 8; j++)
                map[0][j] = '.';
        }
    }
    
    if(q.empty()) cout << 0;
    else cout << 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 8; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < 8; j++)
            map[i][j] = tmp[j];
    }

    bfs();
    return 0;
}