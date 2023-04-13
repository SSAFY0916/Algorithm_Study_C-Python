#include <iostream>
#include <vector>
using namespace std;

int comp[10][10];
int JwKyMh[3][21];
int visit[10];
int ret = 0;

void playRound(int n, int k)
{
    int JwKyMhIndex[3] = {0};
    int win[3] = {0};
    int turnA = 0, turnB = 1;
    while(true)
    {
        if(JwKyMhIndex[0] >= n) break;

        int AHand = JwKyMh[turnA][JwKyMhIndex[turnA]];
        int BHand = JwKyMh[turnB][JwKyMhIndex[turnB]];
        if(comp[AHand][BHand] == 2)
        {
            win[turnA]++;
            JwKyMhIndex[turnA]++;
            JwKyMhIndex[turnB]++;
            if(turnA == 0 && turnB == 1) turnB = 2;
            else if(turnA == 0 && turnB == 2) turnB = 1;
            else if(turnA == 1 && turnB == 0) turnB = 2;
            else if(turnA == 1 && turnB == 2) turnB = 0;
            else if(turnA == 2 && turnB == 0) turnB = 1;
            else if(turnA == 2 && turnB == 1) turnB = 0;
        }
        else if(comp[AHand][BHand] == 0)
        {
            win[turnB]++;
            JwKyMhIndex[turnA]++;
            JwKyMhIndex[turnB]++;
            if(turnA == 0 && turnB == 1) turnA = 2;
            else if(turnA == 0 && turnB == 2) turnA = 1;
            else if(turnA == 1 && turnB == 0) turnA = 2;
            else if(turnA == 1 && turnB == 2) turnA = 0;
            else if(turnA == 2 && turnB == 0) turnA = 1;
            else if(turnA == 2 && turnB == 1) turnA = 0;
        }
        else if(comp[AHand][BHand] == 1)
        {
            if(turnB > turnA)
            {
                win[turnB]++;
                JwKyMhIndex[turnA]++;
                JwKyMhIndex[turnB]++;
                if(turnA == 0 && turnB == 1) turnA = 2;
                else if(turnA == 0 && turnB == 2) turnA = 1;
                else if(turnA == 1 && turnB == 0) turnA = 2;
                else if(turnA == 1 && turnB == 2) turnA = 0;
                else if(turnA == 2 && turnB == 0) turnA = 1;
                else if(turnA == 2 && turnB == 1) turnA = 0;
            }
            else
            {
                win[turnA]++;
                JwKyMhIndex[turnA]++;
                JwKyMhIndex[turnB]++;
                if(turnA == 0 && turnB == 1) turnB = 2;
                else if(turnA == 0 && turnB == 2) turnB = 1;
                else if(turnA == 1 && turnB == 0) turnB = 2;
                else if(turnA == 1 && turnB == 2) turnB = 0;
                else if(turnA == 2 && turnB == 0) turnB = 1;
                else if(turnA == 2 && turnB == 1) turnB = 0;
            }
        }

        if(win[0] == k)
        {
            ret = 1;
            break;
        }
        else if(win[1] == k || win[2] == k) break;
    }
}

void permu(int n, int k, int count)
{
    if(count == n)
    {
        playRound(n, k);
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            if(visit[i] == 1) continue;
            JwKyMh[0][count] = i;
            visit[i] = 1;
            permu(n, k, count + 1);
            if(ret == 1) break;
            visit[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> comp[i][j];
    }
    for(int i = 1; i <= 2; i++)
    {
        for(int j = 0; j < 20; j++)
            cin >> JwKyMh[i][j];
    }

    permu(n, k, 0);
    cout << ret;
    return 0;
}