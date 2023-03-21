// 2240 자두나무

#include <iostream>
#include <cmath>

using namespace std;

int T, W;
bool fall[1000]; // true: 1, false: 2
int dp[1000][31][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> T >> W;

	int tmp;
	for (int t = 0; t < T; t++) {
		cin >> tmp;
		if (tmp == 1) fall[t] = true;
	}
	
	if (fall[0]) {
		dp[0][0][0] = 1;
	}
	else {
		dp[0][1][1] = 1;
	}

	int moved = 0;
	for (int t = 1; t < T; t++) {
		if (fall[t]) {
			dp[t][0][0] = dp[t - 1][0][0] + 1;
			dp[t][0][1] = dp[t - 1][0][1];
			for (int i = 1; i <= W; i++) {
				dp[t][i][0] = max(dp[t - 1][i][0], dp[t - 1][i - 1][1]) + 1;
				dp[t][i][1] = max(dp[t - 1][i - 1][0], dp[t - 1][i][1]);
			}
		}
		else {
			dp[t][0][0] = dp[t - 1][0][0];
			dp[t][0][1] = dp[t - 1][0][1] + 1;
			for (int i = 1; i <= W; i++) {
				dp[t][i][0] = max(dp[t - 1][i][0], dp[t - 1][i - 1][1]);
				dp[t][i][1] = max(dp[t - 1][i - 1][0], dp[t - 1][i][1]) + 1;
			}
		}
	}
  
	int answer = 0;
	for (int i = 0; i <= W; i++) {
		answer = max(answer, dp[T - 1][i][0]);
		answer = max(answer, dp[T - 1][i][1]);
	}
	cout << answer;

	return 0;
}
