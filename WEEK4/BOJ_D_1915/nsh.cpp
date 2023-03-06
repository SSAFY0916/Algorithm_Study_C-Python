#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> square[1001];
vector<int> input[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, ret = 0;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < m; j++)
        {
            int k = tmp[j] - '0';
            input[i].push_back(k);
        }
    }

    square[0].push_back(input[0][0]);
    for(int i = 1; i < m; i++)
       square[0].push_back(input[0][i]);
    for(int i = 1; i < n; i++)
        square[i].push_back(input[i][0]);

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(input[i][j] == 1)
            {
                if(square[i - 1][j - 1] >= 1 && square[i - 1][j] >= square[i - 1][j - 1]
                    && square[i][j - 1] >= square[i - 1][j - 1])
                    square[i].push_back(square[i - 1][j - 1] + 1);
                else if(square[i - 1][j - 1] >= 1 && (square[i - 1][j] < square[i - 1][j - 1]
                        || square[i][j - 1] < square[i - 1][j - 1]))
                    square[i].push_back(min(square[i - 1][j], square[i][j - 1]) + 1);
                else
                    square[i].push_back(input[i][j]);
            }
            else square[i].push_back(0);
        }
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(square[i][j] * square[i][j] > ret) ret = square[i][j] * square[i][j];
    cout << ret;
    return 0;
}