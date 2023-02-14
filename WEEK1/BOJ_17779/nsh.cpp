#include <iostream>
#include <algorithm>
using namespace std;

void divideDistrict(int x, int y, int d1, int d2, int** district, int n)
{
    int tmpD1 = 0, tmpD2 = 0;
    bool middleTmpD1 = false, middleTmpD2 = false;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i >= 0 && i < x + d1 && j >= 0 && j <= y) district[i][j] = 1;
            else if(i >= 0 && i <= x + d2 && j > y && j < n) district[i][j] = 2;
            else if(i >= x + d1 && i < n && j >= 0 && j < y - d1 + d2) district[i][j] = 3;
            else if(i > x + d2 && i < n && j >= y - d1 + d2 && j < n) district[i][j] = 4;
        }
    }

    for(int i = x; i <= x + d1 + d2; i++)
    {
        for(int j = y - tmpD1; j <= y + tmpD2; j++)
            district[i][j] = 5;
        if(!middleTmpD1) tmpD1++;
        else tmpD1--;
        if(!middleTmpD2) tmpD2++;
        else tmpD2--;
        if(tmpD1 == d1) middleTmpD1 = true;
        if(tmpD2 == d2) middleTmpD2 = true;
    }
}

int populationDiff(int** district, int** city, int n)
{
    int sum[6] = {0};
    int max, min;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            sum[district[i][j]] += city[i][j];
    max = *max_element(sum, sum + 6);
    min = *min_element(sum + 1, sum + 6);
    return max - min;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, **city, **district, min = 100000000;

    cin >> n;
    city = new int*[n];
    district = new int*[n];
    for(int i = 0; i < n; i++)
    {
        city[i] = new int[n];
        district[i] = new int[n];
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> city[i][j];

    for(int i = 0; i < n - 2; i++)
    {
        for(int j = 1; j < n - 1; j++)
        {
            int d1 = 1, d2 = 1;

            for(; j - d1 >= 0; d1++)
            {
                d2 = 1;
                for(; j + d2 < n; d2++)
                {
                    if(i + d1 + d2 >= n) continue;
                    divideDistrict(i, j, d1, d2, district, n);
                    int tmp = populationDiff(district, city, n);
                    if(tmp < min) min = tmp;
                }
            }
        }
    }
    cout << min;
    return 0;
}
