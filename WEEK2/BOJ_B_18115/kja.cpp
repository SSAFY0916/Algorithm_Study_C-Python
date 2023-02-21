#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, tmp;
vector<int> skill;
deque<int> origin;
deque<int>::iterator iter;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		skill.push_back(tmp);
	}

	int card = 1;
	for (int i = n - 1; i >= 0; i--) {
		if (skill[i] == 1) {
			origin.push_front(card++);
		}
		else if (skill[i] == 2) {
			tmp = origin.front();
			origin.pop_front();
			origin.push_front(card++);
			origin.push_front(tmp);
		}
		else {
			origin.push_back(card++);
		}
	}

	for (iter = origin.begin(); iter != origin.end(); iter++)
		cout << *iter << " ";


	return 0;
}
