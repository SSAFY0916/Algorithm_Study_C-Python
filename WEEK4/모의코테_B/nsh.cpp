#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> co;
int lab[51][51];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};
vector<co> pvloc;
int *virusCombination;
int ret = 2000000000;

void virusBFS(int n, int m)
{
    int tmplab[51][51];
    int visit[51][51];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            tmplab[i][j] = lab[i][j];
            visit[i][j] = 0;
        }
    }

    queue<co> q;
    for(int i = 0; i < m; i++)
    {
        q.push(pvloc[virusCombination[i]]);
        visit[pvloc[virusCombination[i]].first][pvloc[virusCombination[i]].second] = 1;
    }
    
    while(!q.empty())
    {
        co tmp = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nr = tmp.first + dr[i];
            int nc = tmp.second + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < n && visit[nr][nc] == 0)
            {
                if(tmplab[nr][nc] == 0 || tmplab[nr][nc] == 2)
                {
                    tmplab[nr][nc] = tmplab[tmp.first][tmp.second] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    int tmpM = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(tmpM != -1 && tmpM + 2 < tmplab[i][j] && tmplab[i][j] >= 3 && lab[i][j] != 2)
                tmpM = tmplab[i][j] - 2;
            if(tmplab[i][j] == 0) tmpM = -1;
        }
    }
    if(tmpM == -1) return;
    if(tmpM < ret) ret = tmpM;
}

void virusC(int n, int m, int start, int count)
{
    if(m == count)
        virusBFS(n, m);
    else
    {
        for(int i = start; i < pvloc.size(); i++)
        {
            virusCombination[count] = i;
            virusC(n, m, i + 1, count + 1);
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
    virusCombination = new int[m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> lab[i][j];
            if(lab[i][j] == 2)
                pvloc.push_back({i, j});
        }
    }

    virusC(n, m, 0, 0);
    cout << (ret == 2000000000 ? -1 : ret);
    return 0;
}