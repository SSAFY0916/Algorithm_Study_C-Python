#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> input(1500001);
vector<int> ret(1500001);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, maxV = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> input[i].first >> input[i].second;
    
    for(int i = 0; i <= n; i++)
    {
        maxV = max(ret[i], maxV);
        if(i + input[i].first > n)
            continue;
        ret[i + input[i].first] = max(maxV + input[i].second, ret[i + input[i].first]);
    }
    cout << maxV;

    return 0;
}