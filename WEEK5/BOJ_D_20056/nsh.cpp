#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class FireBall{
    public:
        int r, c, m, speed, dir;
        int live = 1;
        FireBall(int r, int c, int m, int speed, int dir)
        {
            this->r = r;
            this->c = c;
            this->m = m;
            this->speed = speed;
            this->dir = dir;
        }
};
vector<FireBall> fi;
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void ballMov(int n)
{
    vector<int> copy[51][51];
    for(int i = 0; i < (int)fi.size(); i++)
    {
        if(fi[i].live == 1)
        {
            int curR = fi[i].r;
            int curC = fi[i].c;
            int curDir = fi[i].dir;
            int curSp = fi[i].speed;

            curR += n * 1000;
            curC += n * 1000;
            curR += dr[curDir] * curSp;
            curC += dc[curDir] * curSp;
            curR %= n;
            curC %= n;
            if(curR == 0) curR = n;
            if(curC == 0) curC = n;

            copy[curR][curC].push_back(i);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(copy[i][j].size() == 0) continue;
            else if(copy[i][j].size() == 1)
            {
                int curIndex = copy[i][j][0];
                fi[curIndex].r = i;
                fi[curIndex].c = j;
            }
            else
            {
                int mSum = 0, spSum = 0;
                int fbNum = (int)copy[i][j].size();
                int *dirC;
                dirC = new int[fbNum];
                for(int k = 0; k < fbNum; k++)
                {
                    int tmpCur = copy[i][j][k];
                    mSum += fi[tmpCur].m;
                    spSum += fi[tmpCur].speed;
                    dirC[k] = fi[tmpCur].dir;
                }

                mSum /= 5;
                spSum /= fbNum;
                if(mSum == 0)
                {
                    for(int k = 0; k < fbNum; k++)
                    {
                        int tmpCur = copy[i][j][k];
                        fi[tmpCur].live = 0;
                    }
                }
                else
                {
                    bool sameFlag = true;
                    int tmpCheck = fi[copy[i][j][0]].dir % 2;
                    for(int k = 1; k < fbNum; k++)
                    {
                        int tmpCur = copy[i][j][k];
                        if(fi[tmpCur].dir % 2 != tmpCheck)
                        {
                            sameFlag = false;
                            break;
                        }
                    }

                    int setDir;
                    if(sameFlag) setDir = 0;
                    else setDir = 1;
                    for(int k = 0; k < min(4, fbNum); k++)
                    {
                        int tmpCur = copy[i][j][k];
                        fi[tmpCur].r = i;
                        fi[tmpCur].c = j;
                        fi[tmpCur].m = mSum;
                        fi[tmpCur].speed = spSum;
                        fi[tmpCur].dir = setDir;
                        setDir += 2;
                    }
                    if(fbNum < 4)
                    {
                        for(int k = 0; k < 4 - fbNum; k++)
                        {
                            fi.push_back(FireBall(i, j, mSum, spSum, setDir));
                            setDir += 2;
                        }
                    }
                    else if(fbNum > 4)
                        for(int k = 4; k < fbNum; k++)
                            fi[copy[i][j][k]].live = 0;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, ret = 0;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        fi.push_back(FireBall(r, c, m, s, d));
    }

    for(int i = 0; i < k; i++)
        ballMov(n);
    
    for(int i = 0; i < (int)fi.size(); i++)
        if(fi[i].live == 1)
            ret += fi[i].m;
    cout << ret;
    return 0;
}