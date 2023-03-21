#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][32];
vector<int> tree;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, w, ret = 0;
    cin >> t >> w;
    for(int i = 0; i < t; i++)
    {
        int tmp;
        cin >> tmp;
        tree.push_back(tmp);
    }

    for(int i = 1; i <= w + 1; i++)
    {
        for(int j = 1; j <= t; j++)
        {
            dp[j][i] = max(dp[j - 1][i], dp[j - 1][i - 1]);
            if(i % 2 == 1 && tree[j - 1] == 1 ) dp[j][i]++;
            else if(i % 2 == 0 && tree[j - 1] == 2) dp[j][i]++;
            if(ret < dp[j][i]) ret = dp[j][i];
        }
    }
    cout << ret;
    return 0;
}