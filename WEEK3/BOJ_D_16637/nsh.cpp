#include <iostream>
#include <algorithm>
using namespace std;

int num[10];
int arithMode[9];

int cal(int n)
{
    int maxRet = -2147483648;
    int tmp[10];

    for(int i = 0; i < (1 << (n / 2)); i++)
    {
        int test = i, testC = 0;
        while(test != 0)
        {
            if(test % 2 == 1) testC++;
            if(testC > 1) break;
            else if(test % 2 == 0) testC = 0;
            test /= 2;
        }
        if(testC > 1) continue;
        copy(num, num + 10, tmp);
        for(int j = 0; j < n / 2; j++)
        {
            if((i & (1 << j)) != 0)
            {
                if(arithMode[j] == 0) tmp[j + 1] = tmp[j] + tmp[j + 1];
                else if(arithMode[j] == 1) tmp[j + 1] = tmp[j] - tmp[j + 1];
                else if(arithMode[j] == 2) tmp[j + 1] = tmp[j] * tmp[j + 1];
            }
        }
        for(int j = 0; j < n / 2; j++)
        {
            if((i & (1 << j)) == 0)
            {
                int nextInd = j + 1;
                while(nextInd < n / 2 && (i & (1 << nextInd)) != 0)
                    nextInd++;
                if(arithMode[j] == 0) tmp[nextInd] = tmp[j] + tmp[nextInd];
                else if(arithMode[j] == 1) tmp[nextInd] = tmp[j] - tmp[nextInd];
                else if(arithMode[j] == 2) tmp[nextInd] = tmp[j] * tmp[nextInd];
                j = nextInd - 1;
            }
        }
        if(tmp[n / 2] > maxRet) maxRet = tmp[n / 2];
    }
    return maxRet;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, numInd = 0, arithInd = 0, ret = 0;
    char exp[20];

    cin >> n >> exp;
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0) num[numInd++] = exp[i] - '0';
        else if(i % 2 == 1)
        {
            if(exp[i] == '+') arithMode[arithInd++] = 0;
            else if(exp[i] == '-') arithMode[arithInd++] = 1;
            else if(exp[i] == '*') arithMode[arithInd++] = 2;
        }
    }
    ret = cal(n);
    cout << ret;
    return 0;
}