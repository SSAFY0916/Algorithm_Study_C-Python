#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, p, **melody, ret = 0;
    stack<int> line[7];

    cin >> n >> p;
    melody = new int*[n];
    for(int i = 0; i < n; i++)
        melody[i] = new int[2];
    for(int i = 0; i < n; i++)
    {
        cin >> melody[i][0] >> melody[i][1];
    }

    for(int i = 0; i < n; i++)
    {
        if(line[melody[i][0]].empty())
        {
            line[melody[i][0]].push(melody[i][1]);
            ret++;
        }
        else
        {
            if(line[melody[i][0]].top() == melody[i][1]) continue;
            else if(line[melody[i][0]].top() < melody[i][1])
            {
                ret++;
                line[melody[i][0]].push(melody[i][1]);
            }
            else
            {
                while(!line[melody[i][0]].empty())
                {
                    line[melody[i][0]].pop();
                    ret++;
                    if(line[melody[i][0]].empty()) break;
                    if(line[melody[i][0]].top() ==  melody[i][1]) break;
                    if(line[melody[i][0]].top() < melody[i][1])
                    {
                        ret++;
                        line[melody[i][0]].push(melody[i][1]);
                        break;
                    }
                }
                if(line[melody[i][0]].empty())
                {
                    line[melody[i][0]].push(melody[i][1]);
                    ret++;
                }
            }
        }
    }
    cout << ret;
}