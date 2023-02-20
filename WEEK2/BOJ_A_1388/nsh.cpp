#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, retPlank = 0;
    char **roomFloor;
    cin >> n >> m;
    roomFloor = new char*[n];
    for(int i = 0; i < n; i++)
        roomFloor[i] = new char[m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> roomFloor[i][j];
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m - 1; j++)
        {
            if(roomFloor[i][j] == '-' && roomFloor[i][j] != roomFloor[i][j + 1])
                retPlank++;
        }
        if(roomFloor[i][m - 1] == '-') retPlank++;
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(roomFloor[j][i] == '|' && roomFloor[j][i] != roomFloor[j + 1][i])
                retPlank++;
        }
        if(roomFloor[n - 1][i] == '|') retPlank++;
    }
    cout << retPlank;
    return 0;
}