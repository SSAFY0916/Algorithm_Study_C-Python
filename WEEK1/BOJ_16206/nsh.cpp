#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, *cake, ret = 0;

    cin >> n >> m;
    cake = new int[n];
    for(int i = 0; i < n; i++)
        cin >> cake[i];
    sort(cake, cake + n);
    
    for(int i = 0; i < n; i++)
    {
        if(cake[i] == 10) ret++;
        else if(cake[i] % 10 == 0)
        {
            int tmp = cake[i] / 10 - 1;
            if(tmp > m)
            {
                ret += m;
                m = 0;
                break;
            }
            else
                ret += cake[i] / 10;
            m -= tmp;
        }
    }

    if(m > 0)
    {
        for(int i = 0; i < n; i++)
        {
            if(cake[i] % 10 != 0)
            {
                int tmp = cake[i] / 10;
                if(tmp > m)
                {
                    ret += m;
                    break;
                }
                else
                    ret += tmp;
                m -= tmp;
            }
        }
    }
    cout << ret;
    return 0;
}
