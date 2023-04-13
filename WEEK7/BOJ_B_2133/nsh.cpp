#include <iostream>
using namespace std;

int dp[31];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    if(n % 2 == 1) cout << 0;
    else
    {
        dp[2] = 3;
        for(int i = 4; i <= n; i += 2)
        {
           int tmp = dp[i - 2] * 3;
           for(int j = 2; j < i - 2; j += 2)
               tmp += dp[j] * 2;
           tmp += 2;
           dp[i] = tmp;
        }
        cout << dp[n];
    }
    return 0;
}