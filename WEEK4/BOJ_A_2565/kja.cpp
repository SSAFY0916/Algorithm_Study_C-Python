#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

// 2565 전깃줄

using namespace std;

int n; // 전깃줄의 개수 (1 ~ 100)
int dp[501] = { 0, }; // 각 높이에서 최대 연속 전깃줄의 수
vector<pair<int, int>> lines; // 전깃줄의 연결 정보

bool compare(pair<int, int> a, pair<int, int> b) {
	return a < b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		lines.push_back({ a, b });
	}

	sort(lines.begin(), lines.end(), compare);

	// 가장 길게 오름차순이 되는 수를 구한 뒤 n에서 그만큼 빼고 출력
	int pre = 0;
	int length = 0;

	for (int i = 0; i < n; i++) { // i번째 선의 연속된 최댓값
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (lines[j].second > lines[i].second) continue;
			if (dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	int max_dp = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] > max_dp) max_dp = dp[i];
	}
	cout << lines.size() - max_dp;
	
	return 0;
}
