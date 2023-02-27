#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input;
    int ret = 1001, aNum = 0, bNum = 0;

    cin >> input;
    for(int i = 0; i < input.size(); i++)
        if(input[i] == 'a') aNum++;
    for(int i = 0; i < aNum; i++)
        if(input[i] == 'b') bNum++;
    ret = bNum;
    int endP = aNum - 1;
    for(int i = 1; i < input.size(); i++)
    {
        if(input[i - 1] == 'b') bNum--;
        endP++;
        if(endP >= input.size()) endP = 0;
        if(input[endP] == 'b') bNum++;

        if(ret > bNum) ret = bNum;
    }
    cout << ret;
    return 0;
}