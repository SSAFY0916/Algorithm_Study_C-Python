#include <iostream>
#include <vector>
using namespace std;

typedef struct fi{
    int curR;
    int curC;
    int direc;
} fish;

int sharkdirec[3] = {0};
int finalSharkDirec[3] = {0};
int fishNamsae[4][4] = {0};
vector<fish> fishInfor[4][4];
int dr[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dc[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

void fishMove(fish shark)
{
    vector<fish> temp[4][4];
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            for(int k = 0; k < fishInfor[i][j].size(); k++)
            {
                int tmpR = fishInfor[i][j][k].curR;
                int tmpC = fishInfor[i][j][k].curC;
                int tmpD = fishInfor[i][j][k].direc;
                int ii = 8;
                while(--ii >= 0)
                {
                    if((tmpR + dr[tmpD] != shark.curR || tmpC + dc[tmpD] != shark.curC)
                    && (tmpR + dr[tmpD] >= 0 
                    && tmpR + dr[tmpD] < 4
                    && tmpC + dc[tmpD] >= 0 
                    && tmpC + dc[tmpD] < 4)
                    && (fishNamsae[tmpR + dr[tmpD]][tmpC + dc[tmpD]] == 0))
                        break;

                    if(tmpD == 1) tmpD = 8;
                    else tmpD--;
                }
                if(ii >= 0)
                {
                    fish tmp;
                    tmp.curR = tmpR + dr[tmpD];
                    tmp.curC = tmpC + dc[tmpD];
                    tmp.direc = tmpD;
                    temp[tmp.curR][tmp.curC].push_back(tmp);
                }
                else
                {
                    fish tmp;
                    tmp.curR = tmpR;
                    tmp.curC = tmpC;
                    tmp.direc = tmpD;
                    temp[tmp.curR][tmp.curC].push_back(tmp);
                }
            } 
        }
    }

    for(int j = 0; j < 4; j++)
        for(int k = 0; k < 4; k++)
            fishInfor[j][k] = temp[j][k];
}

void sharkMove(fish shark, int cnt, int &maxKill)
{
    if(cnt == 3)
    {
        int visited[4][4] = {0};
        int tmpSum = 0;
        int tmpR = shark.curR;
        int tmpC = shark.curC;
        
        for(int i = 0; i < 3; i++)
        {
            if(sharkdirec[i] == 1)
            {
                if(tmpR - 1 < 0) return;
                tmpR--;
                if(visited[tmpR][tmpC] == 0)
                {
                    tmpSum += fishInfor[tmpR][tmpC].size();
                    visited[tmpR][tmpC] = 1;
                }
            }
            else if(sharkdirec[i] == 2)
            {
                if(tmpC - 1 < 0) return;
                tmpC--;
                if(visited[tmpR][tmpC] == 0)
                {
                    tmpSum += fishInfor[tmpR][tmpC].size();
                    visited[tmpR][tmpC] = 1;
                }
            }
            else if(sharkdirec[i] == 3)
            {
                if(tmpR + 1 > 3) return;
                tmpR++;
                if(visited[tmpR][tmpC] == 0)
                {
                    tmpSum += fishInfor[tmpR][tmpC].size();
                    visited[tmpR][tmpC] = 1;
                }
            }
            else if(sharkdirec[i] == 4)
            {
                if(tmpC + 1 > 3) return;
                tmpC++;
                if(visited[tmpR][tmpC] == 0)
                {
                    tmpSum += fishInfor[tmpR][tmpC].size();
                    visited[tmpR][tmpC] = 1;
                }
            }
        }
        if(tmpSum > maxKill)
        {
            maxKill = tmpSum;
            for(int i = 0; i < 3; i++)
                finalSharkDirec[i] = sharkdirec[i];
        }
        return;
    }
    else
    {
        for(int i = 1; i <= 4; i++)
        {
            sharkdirec[cnt] = i;
            sharkMove(shark, cnt + 1, maxKill);
        }
    }
    return;
}

void realSharkMove(fish &shark, int turn)
{
    vector<fish> temp[4][4];

    for(int j = 0; j < 4; j++)
        for(int k = 0; k < 4; k++)
            temp[j][k] = fishInfor[j][k];
    
    int tmpR = shark.curR;
    int tmpC = shark.curC;
    for(int i = 0; i < 3; i++)
    {
        if(finalSharkDirec[i] == 1)
        {
            tmpR--;
            if(temp[tmpR][tmpC].size() == 0) continue;
            temp[tmpR][tmpC].clear();
            fishNamsae[tmpR][tmpC] = turn;
        }
        else if(finalSharkDirec[i] == 2)
        {
            tmpC--;
            if(temp[tmpR][tmpC].size() == 0) continue;
            temp[tmpR][tmpC].clear();
            fishNamsae[tmpR][tmpC] = turn;
        }
        else if(finalSharkDirec[i] == 3)
        {
            tmpR++;
            if(temp[tmpR][tmpC].size() == 0) continue;
            temp[tmpR][tmpC].clear();
            fishNamsae[tmpR][tmpC] = turn;
        }
        else if(finalSharkDirec[i] == 4)
        {
            tmpC++;
            if(temp[tmpR][tmpC].size() == 0) continue;
            temp[tmpR][tmpC].clear();
            fishNamsae[tmpR][tmpC] = turn;
        }
    }
    shark.curR = tmpR;
    shark.curC = tmpC;
    
    for(int j = 0; j < 4; j++)
        for(int k = 0; k < 4; k++)
            fishInfor[j][k] = temp[j][k];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, s, retSum = 0;
    fish shark;
    cin >> m >> s;
    for(int i = 0; i < m; i++)
    {
        fish tmp;
        cin >> tmp.curR >> tmp.curC >> tmp.direc;
        tmp.curR -= 1;
        tmp.curC -= 1;
        fishInfor[tmp.curR][tmp.curC].push_back(tmp);
    }
    cin >> shark.curR >> shark.curC;
    shark.curR -= 1;
    shark.curC -= 1;

    for(int i = 0; i < s; i++)
    {
        int maxKill = -1;
        vector<fish> copyInfor[4][4];

        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 4; k++)
                copyInfor[j][k] = fishInfor[j][k];
        
        fishMove(shark);
        sharkMove(shark, 0, maxKill);
        realSharkMove(shark, i + 1);

        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 4; k++)
            {
                if(fishNamsae[j][k] == 0) continue;
                if((i + 1) - fishNamsae[j][k] == 2) fishNamsae[j][k] = 0;
            }

        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 4; k++)
                for(int ii = 0; ii < copyInfor[j][k].size(); ii++)
                    fishInfor[j][k].push_back(copyInfor[j][k][ii]);
    }

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            retSum += fishInfor[i][j].size();
    cout << retSum;
    return 0;
}