#include <iostream>
#include <vector>
using namespace std;

vector<int> sushi;
int countSushi[3001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d, k, c;
    cin >> n >> d >> k >> c;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sushi.push_back(x);
    }
    for(int i = 0; i < n; i++)
        sushi.push_back(sushi[i]);
    
    int tmp = 0, ret = 0;
    for(int i = 0; i < k; i++)
    {
        if(countSushi[sushi[i]] == 0) ret++;
        countSushi[sushi[i]]++;
    }
    if(countSushi[c] == 0) ret++;
    countSushi[c]++;
    tmp = ret;
    for(int i = k; i < n + k; i++)
    {
        countSushi[sushi[i - k]]--;
        if(countSushi[sushi[i - k]] == 0) tmp--;
        if(countSushi[sushi[i]] == 0) tmp++;
        countSushi[sushi[i]]++;

        if(tmp > ret) ret = tmp;
    }
    cout << ret;
    return 0;
}