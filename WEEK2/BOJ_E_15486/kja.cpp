#include <iostream>
#define MAX 1500005

using namespace std;

int n, answer = 0;
int times[MAX];
int prices[MAX];
int dp[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> times[i] >> prices[i];
		dp[i] = 0;
	}

	for (int i = 1; i <= n + 1; i++) {
		if (answer < dp[i])
			answer = dp[i];
		if (i + times[i] > n + 1)
			continue;
		if (dp[i + times[i]] < answer + prices[i])
			dp[i + times[i]] = answer + prices[i];
	}
	
	cout << answer;

	return 0;
}
