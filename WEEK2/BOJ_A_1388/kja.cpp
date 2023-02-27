#include <iostream>
#include <string>
using namespace std;

int n, m, answer = 0;
bool shape[50][50]; // true: '-', false: '|'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m;

	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			if (tmp[j] == '-') shape[i][j] = true;
			else shape[i][j] = false;
		}
	}

	bool counted = false;
	for (int i = 0; i < n; i++) {
		counted = false;
		for (int j = 0; j < m; j++) {
			if (shape[i][j]) {
				if (!counted) {
					answer++;
					counted = true;
				}
			}
			else {
				counted = false;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		counted = false;
		for (int j = 0; j < n; j++) {
			if (!shape[j][i]) {
				if (!counted) {
					answer++;
					counted = true;
				}
			}
			else {
				counted = false;
			}
		}
	}

	cout << answer;

	return 0;
}
