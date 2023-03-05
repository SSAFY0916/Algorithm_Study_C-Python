#include <iostream>
using namespace std;

long long int *time;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long int n, m, tmpMax = 0;

    cin >> n >> m;
    time = new long long int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> time[i];
        if(time[i] > tmpMax) tmpMax = time[i];
    }

    long long int start = 1;
    long long int end = tmpMax * m;
    while(start <= end)
    {
        long long int mid = (start + end) / 2;
        long long int tmpS = 0;
        
        for(long long int i = 0; i < n; i++)
        {
            tmpS += mid / time[i];
            if(tmpS > m) break;
        }
        if(tmpS < m) start = mid + 1;
        else end = mid - 1;
    }
    cout << end + 1;
    return 0;
}