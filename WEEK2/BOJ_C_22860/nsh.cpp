#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
using namespace std;

map<string, vector<pair<string, int>>> mainDirectory;
map<string, int> fileNumCheck;

void fileMake(string upper, string cur, int isDirectory)
{
    if(mainDirectory.find(upper) == mainDirectory.end())
    {
        vector<pair<string, int>> ttmp;
        mainDirectory.insert({upper, ttmp});
    }
    if(isDirectory == 1)
    {
        mainDirectory[upper].push_back({cur, isDirectory});
        if(mainDirectory.find(cur) == mainDirectory.end())
        {
            vector<pair<string, int>> ttmp;
            mainDirectory.insert({cur, ttmp});
        }
    }
    else
        mainDirectory[upper].push_back({cur, isDirectory});
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;

    cin >> n >> m;
    for(int i = 0; i < n + m; i++)
    {
        string upper, cur;
        int isDirectory;
        
        cin >> upper >> cur >> isDirectory;
        fileMake(upper, cur, isDirectory);
    }

    cin >> q;
    for(int i = 0; i < q; i++)
    {
        string query;
        int curr = 0, position;
        int ret1 = 0, ret2 = 0;

        cin >> query;
        while ((position = query.find("/", curr)) != string::npos) 
            curr = position + 1;
        string findFolder = query.substr(curr);

        queue<string> tmpQ;
        tmpQ.push(findFolder);
        while(!tmpQ.empty())
        {
            string curD = tmpQ.front();
            tmpQ.pop();
            vector<pair<string, int>>::iterator iter;
            for(iter = mainDirectory[curD].begin(); iter != mainDirectory[curD].end(); iter++)
            {
                if(iter->second == 1)
                    tmpQ.push(iter->first);
                else
                    fileNumCheck[iter->first]++;
            }
        }

        map<string, int>::iterator iter;
        for(iter = fileNumCheck.begin(); iter != fileNumCheck.end(); iter++)
        {
            ret1++;
            ret2 += iter->second;
        }
        fileNumCheck.clear();
        cout << ret1 << " " << ret2 << "\n";
    }
    return 0;
}