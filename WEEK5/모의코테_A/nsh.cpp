#include <iostream>
#include <stack>
using namespace std;

int arr[7][7];
int colGroup[7] = {0};
int minRet = 100;

void ballD(int num, int curC, int curR)
{
    int copy[7][7];
    int copyCol[7];
    for(int i = 0; i < 7; i++)
        copyCol[i] = colGroup[i];
    for(int i = 0; i < 7; i++)
        for(int j = 0; j < 7; j++)
            copy[i][j] = arr[i][j];
    copy[curR][curC] = num;
    copyCol[curC]++;

    int turn = 49;
    while(turn--)
    {
        for(int i = 0; i < 7; i++)
        {
            int seq = 0;
            bool seqFlag = false;
            for(int j = 0; j < 7; j++)
            {
                if(!seqFlag && copy[i][j] == 0)
                    seq = 0;
                else if(seqFlag && copy[i][j] == 0)
                {
                    seqFlag = false;
                    for(int r = j - seq; r < j; r++)
                        if(copy[i][r] == seq)
                            copy[i][r] = 0;
                    seq = 0;
                }
                else if(copy[i][j] != 0)
                {
                    seqFlag = true;
                    seq++;
                }
            }
            if(seqFlag)
                for(int r = 7 - seq; r < 7; r++)
                    if(copy[i][r] == seq)
                        copy[i][r] = 0;
        }
        
        for(int j = 0; j < 7; j++)
            for(int i = 0; i < 7; i++)
                if(copy[i][j] == copyCol[j])
                    copy[i][j] = 0;
        for(int j = 0; j < 7; j++)
        {
            stack<int> tmp;
            for(int i = 0; i < 7; i++)
            {
                if(copy[i][j] != 0) tmp.push(copy[i][j]);
                copy[i][j] = 0;
            }
            int ri = 7;
            while(!tmp.empty())
            {
                ri--;
                copy[ri][j] = tmp.top();
                tmp.pop();
            }
            copyCol[j] = 7 - ri;
        }
    }
    int tmpRet = 0;
    for(int i = 0; i < 7; i++)
        tmpRet += copyCol[i];
    if(tmpRet < minRet) minRet = tmpRet;
}

void selectCol(int num)
{
    for(int t = 0; t < 7; t++)
    {
        int firstZero = 7 - colGroup[t] - 1;
        ballD(num, t, firstZero);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            cin >> arr[i][j];
            if(colGroup[j] == 0 && arr[i][j] != 0) colGroup[j] = 7 - i;
        }
    }
    int num;
    cin >> num;

    selectCol(num);
    cout << minRet;
    return 0;
}