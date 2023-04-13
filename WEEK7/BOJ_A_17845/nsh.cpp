#include <iostream>
#include <algorithm>
using namespace std;

int studyImportant[1001][10001];
int importance[1001];
int studyTime[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= k; i++)
        cin >> importance[i] >> studyTime[i];
    
    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(j >= studyTime[i])
            {
                studyImportant[i][j] = max(studyImportant[i - 1][j - studyTime[i]] + importance[i]
                                    , studyImportant[i - 1][j]);
            }
            else studyImportant[i][j] =
                max(studyImportant[i - 1][j], studyImportant[i][j - 1]);
        }
    }
    cout << studyImportant[k][n];
    return 0;
}