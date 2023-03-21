#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> home;

int routerCount(int n, int d)
{
    int count = 1;
    int prev = home[0];
    
    for(int i = 1; i < n; i++)
    {
        if(home[i] - prev >= d)
        {
            count++;
            prev = home[i];
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, c;
    cin >> n >> c;
    home.resize(n);
    for(int i = 0; i < n; i++)
        cin >> home[i];
    sort(home.begin(), home.end());

    int left = 0;
    int right = home[max_element(home.begin(), home.end()) - home.begin()] + 1;
    while(left + 1 < right)
    {
        int mid = (left + right) / 2;
        int routerSum = routerCount(n, mid);
        if(routerSum < c)
            right = mid;
        else
            left = mid;
    }
    cout << left;
    return 0;
}