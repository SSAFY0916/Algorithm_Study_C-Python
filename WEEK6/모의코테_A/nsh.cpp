#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> infor;
deque<pair<int, infor>> zeroA;
deque<pair<int, infor>> oneA;
vector<infor> ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, t;
    cin >> n >> m >> t;
    ans.resize(n + 1, {-1, -1});
    for(int i = 0; i < n; i++)
    {
        int d, m, r;
        cin >> d >> m >> r;
        if(d == 0)
            zeroA.push_back({i, {m, r}});
        else
            oneA.push_back({i, {m, r}});
    }

    int curc = 0, curTime = 0;
    while(!zeroA.empty() || !oneA.empty())
    {
        int curM = m;
        if(oneA.empty() && curc == 1)
        {
            curc = 0;
            curTime += t;
            continue;
        }
        if(zeroA.empty() && curc == 0)
        {
            curc = 1;
            curTime += t;
            continue;
        }

        if(curc == 0)
        {
            if(curTime >= zeroA.front().second.second)
            {
                while(curTime >= zeroA.front().second.second && curM > 0)
                {
                    if(zeroA.front().second.first <= curM)
                    {
                        curM -= zeroA.front().second.first;
                        if(ans[zeroA.front().first].first == -1)
                            ans[zeroA.front().first].first = curTime;
                        ans[zeroA.front().first].second = curTime + t;
                        zeroA.pop_front();
                    }
                    else
                    {
                        zeroA.front().second.first -= curM;
                        curM = 0;
                        if(ans[zeroA.front().first].first == -1)
                            ans[zeroA.front().first].first = curTime;
                    }
                    if(zeroA.empty()) break;
                }
                curTime += t;
                curc = 1;
            }
            else if(!oneA.empty() && curTime >= oneA.front().second.second)
            {
                curTime += t;
                curc = 1;
            }
            else
            {
                if(oneA.empty())
                    curTime = zeroA.front().second.second;
                else if(zeroA.front().second.second <= oneA.front().second.second)
                    curTime = zeroA.front().second.second;
                else
                {
                    curTime = oneA.front().second.second + t;
                    curc = 1;
                }
            }
        }
        else
        {
            if(curTime >= oneA.front().second.second)
            {
                while(curTime >= oneA.front().second.second && curM > 0)
                {
                    if(oneA.front().second.first <= curM)
                    {
                        curM -= oneA.front().second.first;
                        if(ans[oneA.front().first].first == -1)
                            ans[oneA.front().first].first = curTime;
                        ans[oneA.front().first].second = curTime + t;
                        oneA.pop_front();
                    }
                    else
                    {
                        oneA.front().second.first -= curM;
                        curM = 0;
                        if(ans[oneA.front().first].first == -1)
                            ans[oneA.front().first].first = curTime;
                    }
                    if(oneA.empty()) break;
                }
                curTime += t;
                curc = 0;
            }
            else if(!zeroA.empty() && curTime >= zeroA.front().second.second)
            {
                curTime += t;
                curc = 0;
            }
            else
            {
                if(zeroA.empty())
                    curTime = oneA.front().second.second;
                else if(oneA.front().second.second <= zeroA.front().second.second)
                    curTime = oneA.front().second.second;
                else
                {
                    curTime = zeroA.front().second.second + t;
                    curc = 0;
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout << ans[i].first << " " << ans[i].second << "\n";
    return 0;
}