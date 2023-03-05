#include <iostream>
#include <string>
using namespace std;

int cardStat[10][3];
int com[3];
int HOkayCom[64];
int HOkayNum = 0;
int visit[64];

void HCheck()
{
    int first = com[0];
    int second = com[1];
    int third = com[2];
    bool flag = true;

    for(int i = 0; i < 3; i++)
    {
        int tmp = cardStat[first][i] + cardStat[second][i] + cardStat[third][i];
        if(tmp != 7)
            if(!(cardStat[first][i] == cardStat[second][i]
                && cardStat[second][i] == cardStat[third][i]))
                flag = false;
    }
    if(flag == true)
    {
        HOkayCom[HOkayNum] = (1 << first) + (1 << second) + (1 << third);
        HOkayNum++;
    }
}

void combination(int start, int count)
{
    if(count == 3)
        HCheck();
    else
    {
        for(int i = start; i <= 9; i++)
        {
            com[count] = i;
            combination(i + 1, count + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, score = 0;
    bool gFlag = false;
    
    for(int i = 1; i <= 9; i++)
    {
        string tmp1, tmp2, tmp3;

        cin >> tmp1 >> tmp2 >> tmp3;
        if(tmp1.compare("CIRCLE") == 0) cardStat[i][0] = 1;
        else if(tmp1.compare("TRIANGLE") == 0) cardStat[i][0] = 2;
        else if(tmp1.compare("SQUARE") == 0) cardStat[i][0] = 4;
        if(tmp2.compare("YELLOW") == 0) cardStat[i][1] = 1;
        else if(tmp2.compare("RED") == 0) cardStat[i][1] = 2;
        else if(tmp2.compare("BLUE") == 0) cardStat[i][1] = 4;
        if(tmp3.compare("GRAY") == 0) cardStat[i][2] = 1;
        else if(tmp3.compare("WHITE") == 0) cardStat[i][2] = 2;
        else if(tmp3.compare("BLACK") == 0) cardStat[i][2] = 4;
    }
    combination(1, 0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        char cmd;

        cin >> cmd;
        if(cmd == 'H')
        {
            int tmp1, tmp2, tmp3;
            int tCom, i = 0;

            cin >> tmp1 >> tmp2 >> tmp3;
            tCom = (1 << tmp1) + (1 << tmp2) + (1 << tmp3);
            for(; i < HOkayNum; i++)
            {
                if(HOkayCom[i] == tCom)
                {
                    if(visit[i] == 0)
                    {
                        visit[i] = 1;
                        score++;
                        break;
                    }
                    else
                    {
                        score--;
                        break;
                    }
                }
            }
            if(i == HOkayNum) score--;
        }
        else if(cmd == 'G')
        {
            int i = 0;
            bool flag = true;

            for(; i < HOkayNum; i++)
                if(visit[i] == 0)
                    flag = false;
            if(flag && !gFlag)
            {
                score += 3;
                gFlag = true;
            }
            else score--;
        }
    }
    cout << score;
    return 0;
}