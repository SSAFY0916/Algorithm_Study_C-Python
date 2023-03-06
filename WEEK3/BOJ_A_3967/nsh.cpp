#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> rInd;
vector<int> cInd;
int visit[12] = {0};
char map[5][9];
bool flag = false;
int emptyCount = 0;

bool cal()
{
    if((map[0][4] - 'A') + (map[1][3] - 'A') + (map[2][2] - 'A') + (map[3][1] - 'A') != 22) return false;
    if((map[0][4] - 'A') + (map[1][5] - 'A') + (map[2][6] - 'A') + (map[3][7] - 'A') != 22) return false;
    if((map[1][1] - 'A') + (map[1][3] - 'A') + (map[1][5] - 'A') + (map[1][7] - 'A') != 22) return false;
    if((map[3][1] - 'A') + (map[3][3] - 'A') + (map[3][5] - 'A') + (map[3][7] - 'A') != 22) return false;
    if((map[1][1] - 'A') + (map[2][2] - 'A') + (map[3][3] - 'A') + (map[4][4] - 'A') != 22) return false;
    if((map[1][7] - 'A') + (map[2][6] - 'A') + (map[3][5] - 'A') + (map[4][4] - 'A') != 22) return false;
    return true;
}

void permutaion(int count)
{
    if(count == emptyCount)
        flag = cal();
    else
    {
        for(int i = 0; i < 12; i++)
        {
            if(visit[i] == 1) continue;
            map[rInd[count]][cInd[count]] = i + 'A';
            visit[i] = 1;
            permutaion(count + 1);
            visit[i] = 0;
            if(flag) break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 5; i++)
    {
        string tmp;
        
        cin >> tmp;
        for(int j = 0; j < 9; j++)
        {
            map[i][j] = tmp.at(j);
            if(tmp.at(j) >= 'A' && tmp.at(j) <= 'L')
                visit[tmp.at(j) - 'A'] = 1;
            else if(tmp.at(j) == 'x')
            {
                emptyCount++;
                rInd.push_back(i);
                cInd.push_back(j);
            }
        }
    }
    permutaion(0);
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 9; j++)
            cout << map[i][j];
        cout << "\n";
    }
    return 0;
}