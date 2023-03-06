#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> v;

    while(true)
    {
        string tmp;

        cin >> tmp;
        if(tmp.compare("-") == 0) break;
        v.push_back(tmp);
    }

    while(true)
    {
        string puzzle;
        set<char> charset;
        set<char> minset;
        set<char> maxset;
        int check[26] = {0};
        int min = 2100000000;
        int max = 0;

        cin >> puzzle;
        if(puzzle.compare("#") == 0) break;
        for(int i = 0; i < puzzle.size(); i++)
        {
            check[puzzle[i] - 'A']++;
            charset.insert(puzzle[i]);
        }
        
        for(auto i = charset.begin(); i != charset.end(); i++)
        {
            char center = *i;
            int tmpret = 0;

            for(int j = 0; j < v.size(); j++)
            {
                string tmp = v[j];
                int cp[26] = {0};
                int k;

                if(tmp.find(center) == string::npos) continue;
                for(k = 0; k < tmp.size(); k++)
                {
                    cp[tmp[k] - 'A']++;
                    if(cp[tmp[k] - 'A'] > check[tmp[k] - 'A']) break;
                }
                if(k == tmp.size()) tmpret++;
            }
            if(tmpret < min)
            {
                if(minset.size() > 0)
                    minset.clear();
                min = tmpret;
                minset.insert(center);
            }
            else if(tmpret == min)
                minset.insert(center);
            if(tmpret > max)
            {
                if(maxset.size() > 0)
                    maxset.clear();
                max = tmpret;
                maxset.insert(center);
            }
            else if(tmpret == max)
                maxset.insert(center);
        }

        for(auto i = minset.begin(); i != minset.end(); i++)
            cout << *i;
        cout << " " << min << " ";
        for(auto i = maxset.begin(); i != maxset.end(); i++)
            cout << *i;
        cout << " " << max << "\n";
    }
    return 0;
}