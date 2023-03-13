#include <iostream>
#include <vector>
using namespace std;

typedef pair<pair<int, int>, char> robotInfor;
vector<robotInfor> ri;
int field[101][101] = {0};
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bool stopFlag = false;
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    ri.push_back({{0, 0}, '0'});
    for(int i = 0; i < n; i++)
    {
        int x, y;
        char dir;
        cin >> x >> y >> dir;
        ri.push_back({{y, x}, dir});
        field[y][x] = i + 1;
    }

    for(int i = 0; i < m; i++)
    {
        int rIndex, recur;
        char cmd;
        cin >> rIndex >> cmd >> recur;
        if(stopFlag) continue;
        robotInfor cur = ri[rIndex];
        int curDir = -1;
        switch(cur.second)
        {
            case 'N' : curDir = 1; break;
            case 'E' : curDir = 0; break;
            case 'S' : curDir = 3; break;
            case 'W' : curDir = 2; break;
        }
        if(cmd == 'R')
        {
            curDir += 4;
            recur %= 4;
            while(recur--)
                curDir--;
        }
        else if(cmd == 'L')
        {
            recur %= 4;
            while(recur--)
                curDir++;
        }
        else
        {
            int curX = cur.first.second;
            int curY = cur.first.first;
            while(recur--)
            {
                curX += dx[curDir];
                curY += dy[curDir];
                if(curX < 1 || curX > a || curY < 1 || curY > b)
                {
                    cout << "Robot " << rIndex << " crashes into the wall";
                    stopFlag = true;
                    break;
                }
                else if(field[curY][curX] > 0)
                {
                    cout << "Robot " << rIndex << " crashes into robot " << field[curY][curX];
                    stopFlag = true;
                    break;
                }
            }
            field[cur.first.first][cur.first.second] = 0;
            field[curY][curX] = rIndex;
            ri[rIndex].first.second = curX;
            ri[rIndex].first.first = curY;
        }
        curDir %= 4;
        switch(curDir)
        {
            case 1 : ri[rIndex].second = 'N'; break;
            case 0 : ri[rIndex].second = 'E'; break;
            case 3 : ri[rIndex].second = 'S'; break;
            case 2 : ri[rIndex].second = 'W'; break;
        }
    }
    if(!stopFlag)
        cout << "OK";
    return 0;
}