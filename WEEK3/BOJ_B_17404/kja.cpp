#include <iostream>
#include <algorithm>
#define MAX 1000000

// 17404 RGB거리 2

using namespace std;

int n, answer = MAX;
int cost[1000][3];
int paint[1000][3];
// 0: R, 1: G, 2: B

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	for (int i = 0; i < 3; i++) { // picked color
		for (int j = 0; j < 3; j++) {
			if (i == j) paint[0][j] = cost[0][j];
			else paint[0][j] = MAX;
		}
		for (int j = 1; j < n; j++) {
			paint[j][0] = min(paint[j - 1][1], paint[j - 1][2]) + cost[j][0];
			paint[j][1] = min(paint[j - 1][0], paint[j - 1][2]) + cost[j][1];
			paint[j][2] = min(paint[j - 1][0], paint[j - 1][1]) + cost[j][2];
		}
		for (int j = 0; j < 3; j++) {
			if (i == j) continue;
			answer = min(answer, paint[n - 1][j]);
		}
	}

	cout << answer;

	return 0;
}
