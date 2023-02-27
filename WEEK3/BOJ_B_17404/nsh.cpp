#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, sol = 100000001;
    int cost[1000][3];
    int ret[1000][3];

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            cin >> cost[i][j];
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(i == j) ret[0][i] = cost[0][i];
            else ret[0][j] = 3001;
        }
        for(int j = 1; j < n; j++)
        {
            ret[j][0] = min(ret[j - 1][1] + cost[j][0], ret[j - 1][2] + cost[j][0]);
            ret[j][1] = min(ret[j - 1][0] + cost[j][1], ret[j - 1][2] + cost[j][1]);
            ret[j][2] = min(ret[j - 1][0] + cost[j][2], ret[j - 1][1] + cost[j][2]);
        }
        for(int j = 0; j < 3; j++)
        {
            if(j == i) continue;
            else
                sol = min({sol, ret[n - 1][j]});
        }
    }
    cout << sol;
    return 0;
}