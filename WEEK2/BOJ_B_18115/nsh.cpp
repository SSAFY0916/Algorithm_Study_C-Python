#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, *arr, cardNum = 1;
    deque<int> card;
    cin >> n;
    arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = n - 1; i >= 0; i--)
    {
        if(arr[i] == 1) card.push_front(cardNum++);
        else if(arr[i] == 2)
        {
            int tmp = card.front();
            card.pop_front();
            card.push_front(cardNum++);
            card.push_front(tmp);
        }
        else if(arr[i] == 3) card.push_back(cardNum++);
    }

    for(auto i : card)
        cout << i << " ";
    return 0;
}