#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, *mine;

    cin >> n;
    mine = new int[n];
    for(int i = 0; i < n; i++)
        cin >> mine[i];
    
    for(int i = 0; i < n - 1; i++)
    {
        if(mine[i] < mine[i + 1]) continue;
        cout << i + 1 << "\n";
        for(int j = i; j < n - 1; j++)
        {
            if(mine[j] <= mine[j + 1])
            {
                i = j;
                break;
            }
            if(j == n - 2) i = j;
        }
    }
    if(mine[n - 2] <= mine[n - 1])
        cout << n << "\n";
    return 0;
}
