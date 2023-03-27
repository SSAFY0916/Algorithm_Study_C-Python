#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, int>> edge;
int p[200001];

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

    while(true)
    {
        int m, n;
        cin >> m >> n;
        if(m == 0 && n == 0) break;
        
        for(int i = 0; i < m; i++)
            makeSet(i);
        vector<edge> el;
        int costSum = 0;
        for(int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            el.push_back({z, {x, y}});
            costSum += z;
        }

        sort(el.begin(), el.end());
        int index = 0, saveCost = 0, treeI = 0;
        while(true)
        {
            int x = findSet(el[index].second.first);
            int y = findSet(el[index].second.second);
            int z = el[index].first;
            index++;
            if(x != y)
            {
                unionSet(x, y);
                saveCost += z;
                treeI++;
                if(treeI == m - 1) break;
            }
        }
        cout << costSum - saveCost << "\n";
    }
    return 0;
}