#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int p[100001];
typedef pair<pair<int, int>, pair<int, int>> logg;
vector<logg> v;

void makeSet(int a)
{
    p[a] = a;
}

int findSet(int a)
{
    if(a == p[a]) return a;
    else return p[a] = findSet(p[a]);
}

void unionSet(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    if(a != b)
    {
        if(a > b) p[a] = b;
        else p[b] = a;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    for(int i = 0; i <= n; i++)
        makeSet(i);
    v.push_back({{0, 0}, {-1, 0}});
    for(int i = 0; i < n; i++)
    {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        v.push_back({{x1, x2}, {y, i + 1}});
    }
    
    sort(v.begin() + 1, v.end());
    int maxI = v[1].second.second, maxX = v[1].first.second;
    for(int i = 2; i <= n; i++)
    {
        logg cur = v[i];
        if(cur.first.first <= maxX)
            unionSet(maxI, cur.second.second);
        if(cur.first.second > maxX)
        {
            maxX = cur.first.second;
            maxI = cur.second.second;
        }
    }

    for(int i = 0; i < q; i++)
    {
        int x1, x2;
        cin >> x1 >> x2;
        if(findSet(x1) == findSet(x2)) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}