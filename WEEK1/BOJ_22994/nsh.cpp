#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, minContinueRow = 1005, minContinueCol = 1005, count;
    string tmpString;
    char **arr, **ret;
    
    cin >> n >> m;
    arr = new char*[n];
    for(int i = 0; i < n; i++)
        arr[i] = new char[m];
    for(int i = 0; i < n; i++)
    {
        cin >> tmpString;
        for(int j = 0; j < m; j++)
            arr[i][j] = tmpString[j];
    }
    
    for(int j = 0; j < n; j++)
    {
        count = 1;
        for(int i = 1; i < m; i++)
        {
            if(arr[j][i - 1] == arr[j][i]) count++;
            else
            {
                if(count < minContinueCol)
                {
                    if(i == m - 1) count = 1;
                    minContinueCol = count;
                }
                count = 1;
            }
        }
        if(minContinueCol == 1005)  minContinueCol = count;
    }

    for(int j = 0; j < m; j++)
    {
        count = 1;
        for(int i = 1; i < n; i++)
        {
            if(arr[i - 1][j] == arr[i][j]) count++;
            else
            {
                if(count < minContinueRow)
                {
                    if(i == n - 1) count = 1;
                    minContinueRow = count;
                }
                count = 1;
            }
        }
        if(minContinueRow == 1005)  minContinueRow = count;
    }

    ret = new char*[n / minContinueRow];
    for(int i = 0; i < n / minContinueRow; i++)
        ret[i] = new char[m / minContinueCol];
    int tmpRow = 0;
    for(int i = 0; i < n / minContinueRow; i++)
    {
        int tmpCol = 0;
        for(int j = 0; j < m / minContinueCol; j++)
        {
            ret[i][j] = arr[tmpRow][tmpCol];
            tmpCol += minContinueCol;
        }
        tmpRow += minContinueRow;
    }
    cout << n / minContinueRow << " " << m / minContinueCol << "\n";
    for(int i = 0; i < n / minContinueRow; i++)
    {
        for(int j = 0; j < m / minContinueCol; j++)
            cout << ret[i][j];
        cout << "\n";
    }
    
    return 0;
}
