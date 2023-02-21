#include <iostream>
#include <stack>
using namespace std;

int n, p, answer = 0;
int string_num, fret_num;
stack<int> fret[7]; // 1 ~ 6

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		cin >> string_num >> fret_num;

		if (fret[string_num].size() == 0) {
			fret[string_num].push(fret_num);
			answer++;
		}
		else {
			while (fret[string_num].size() > 0 && fret[string_num].top() > fret_num) {
				fret[string_num].pop();
				answer++;
			}

			if (fret[string_num].size() == 0) {
				fret[string_num].push(fret_num);
				answer++;
			}
			else if (fret[string_num].top() < fret_num) {
				fret[string_num].push(fret_num);
				answer++;
			}
		}

	}

	cout << answer;

	return 0;
}
