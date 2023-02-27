#include <iostream>
#include <string>
using namespace std;

char warField[100][100];
int visit[100][100];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int depth = 0;

void dfs(int n, int m, int curR, int curC, char colour)
{
    visit[curR][curC] = 1;
    depth++;

    for(int i = 0; i < 4; i++)
    {
        int ncurR = curR + dr[i];
        int ncurC = curC + dc[i];
        if(ncurR >= 0 && ncurR < n && ncurC >= 0 && ncurC < m)
            if(visit[ncurR][ncurC] != 1 && colour == warField[ncurR][ncurC])
                dfs(n, m, ncurR, ncurC, colour);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, wSum = 0, bSum = 0;

    cin >> n >> m;
    int tmp = m;
    m = n;
    n = tmp;
    for(int i = 0; i < n; i++)
    {
        string tmp;

        cin >> tmp;
        for(int j = 0; j < m; j++)
            warField[i][j] = tmp.at(j);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(visit[i][j] != 1)
            {
                char colour = warField[i][j];
                depth = 0;
                dfs(n, m, i, j, colour);

                if(colour == 'W') wSum += depth * depth;
                else if(colour == 'B') bSum += depth * depth;
            }
        }
    }
    cout << wSum << " " << bSum;
    return 0;
}