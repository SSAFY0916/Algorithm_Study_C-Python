#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, tmp;
vector<int> cake1; // 10 ...
vector<int> cake2; // else ...

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp < 10) continue;
		if (tmp % 10 == 0)cake1.push_back(tmp);
		else cake2.push_back(tmp);
	}
	sort(cake1.begin(), cake1.end());
	sort(cake2.begin(), cake2.end());

	int answer = 0;
	for (int i = 0; i < cake1.size(); i++) {
		if (cake1[i] == 10) {
			answer++;
		}
		else {
			int cur = cake1[i] / 10;
			if (cur <= m + 1) {
				answer += cur;
				m -= cur - 1;
			}
			else {
				answer += m;
				m = 0;
				i = n;
			}
		}
	}

	if (m > 0) {
		for (int i = 0; i < cake2.size(); i++) {
			if (cake2[i] / 10 > m) {
				answer += m;
				m = 0;
				i = n;
			}
			else {
				answer += cake2[i] / 10;
				m -= cake2[i] / 10;
			}
		}

	}

	cout << answer;

	return 0;
}
