#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n, r, **board, laserX, laserY, laserDirection;
        int dr[4] = {0, -1, 0, 1};
        int dc[4] = {1, 0, -1, 0};

        cin >> n >> r;
        board = new int*[n + 2];
        for(int j = 0; j < n + 2; j++)
        {
            board[j] = new int[n + 2];
            fill(board[j], board[j] + n + 2, 0);
        }
        for(int j = 0; j < r; j++)
        {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }
        cin >> laserX >> laserY;
        if(laserX == 0) laserDirection = 0;
        else if(laserY == 0) laserDirection = 3;
        else if(laserY == n + 1) laserDirection = 1;
        else if(laserX == n + 1) laserDirection = 2;
        laserY += dr[laserDirection];
        laserX += dc[laserDirection];

        while(true)
        {
            if(laserX == 0 || laserX == n + 1) break;
            else if(laserY == 0 || laserY == n + 1) break;

            if(board[laserY][laserX] == 1)
                laserDirection = (laserDirection + 1) % 4;
            laserY += dr[laserDirection];
            laserX += dc[laserDirection];
        }

        cout << laserX << " " << laserY << "\n";
    }
    return 0;
}
