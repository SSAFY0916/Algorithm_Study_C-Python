#include <iostream>
#include <vector>
using namespace std;

int n, tmp;
vector<int> bomb;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;
	bomb.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		bomb.push_back(tmp);
	}
	bomb.push_back(0);

	bool inc = true;
	for (int i = 1; i <= n + 1; i++) {
		if (inc) {
			if (bomb[i] == bomb[i - 1]) {
				cout << i - 1 << "\n";
			}
			else if(bomb[i] < bomb[i-1]){
				cout << i - 1 << "\n";
				inc = false;
			}
		}
		else {
			if (bomb[i] >= bomb[i - 1]) {
				inc = true;
			}
		}
	}

	return 0;
}
