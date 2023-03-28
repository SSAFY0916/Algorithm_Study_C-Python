// 17845 수강 과목

#include <iostream>
#include <algorithm>
#define N_MAX 10001
#define K_MAX 1001
using namespace std;

int N, K;
int importance[K_MAX], studyTime[K_MAX];

int dp[K_MAX][N_MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int k = 1; k <= K; k++) {
		cin >> importance[k] >> studyTime[k];
	}

	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			if (studyTime[i] > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - studyTime[i]] + importance[i]);
		}
	}

	cout << dp[K][N];

	return 0;
}
