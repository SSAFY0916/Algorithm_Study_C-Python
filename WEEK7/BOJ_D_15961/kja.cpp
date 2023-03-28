// 15961 회전 초밥

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 3001
using namespace std;

int N, d, k, c;
int answer, tmp;
int chobab[MAX];
vector<int> tray;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		tray.push_back(tmp);
	}

	chobab[c]++;
	int start = 0, end = 0, total = 1;
	while (end < k) {
		chobab[tray[end]]++;
		if (chobab[tray[end]] == 1) total++;
		end++;
	}
	answer = max(answer, total);

	for (int i = 1; i < N; i++) {
		chobab[tray[start]]--;
		if (chobab[tray[start]] == 0) total--;
		start++;
		// start %= N;
		chobab[tray[end]]++;
		if (chobab[tray[end]] == 1) total++;
		end++;
		end %= N;

		answer = max(answer, total);
	}

	cout << answer;

	return 0;
}
