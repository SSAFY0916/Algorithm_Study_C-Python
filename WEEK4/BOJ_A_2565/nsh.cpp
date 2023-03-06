#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int dp[100] = {0};
    vector<pair<int, int>> wire;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp1, tmp2;

        cin >> tmp1 >> tmp2;
        wire.push_back({tmp1, tmp2});
    }

    sort(wire.begin(), wire.end());
    dp[0] = 1;
    for(int i = 1; i < n; i++)
    {
        int max = 0;

        for(int j = 0; j < i; j++)
        {
            if(wire[i].second > wire[j].second && dp[j] > max) max = dp[j]; 
            dp[i] = max + 1;
        }
    }

    int ret = n - *max_element(dp, dp + n);
    cout << ret;
    return 0;
}