#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define CITY_SIZE 10001

// 1949 우수 마을

using namespace std;

int N;
int population[CITY_SIZE];
vector<int> way[CITY_SIZE];

bool beenCity[CITY_SIZE] = { false, };
int dp[CITY_SIZE][2]; // 우수 마을일 경우의 dp와 아닐 경우의 dp

void getMaxPopulation(int city);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> population[i];
		dp[i][0] = 0;
		dp[i][1] = 0;
	}
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		way[a].push_back(b);
		way[b].push_back(a);
	}

	// 한 마을을 첫 우수 마을로 선정한 뒤 뻗어 나가기
	getMaxPopulation(1);

	cout << max(dp[1][0], dp[1][1]);

	return 0;
}

void getMaxPopulation(int city) {
	beenCity[city] = true;

	queue<int> cities;
	for (int i = 0; i < way[city].size(); i++) {
		int nxt = way[city][i];
		if (beenCity[nxt]) continue;
		getMaxPopulation(nxt);
		cities.push(nxt);
	}

	dp[city][0] = population[city]; // 우수 마을인 경우
	dp[city][1] = 0; // 우수 마을이 아닌 경우

	if (cities.size() > 0) {
		int s = cities.size();
		while (s-- > 0) {
			int nxt = cities.front();
			cities.pop();
			dp[city][0] += dp[nxt][1];
			dp[city][1] += max(dp[nxt][0], dp[nxt][1]);
		}
	}
}
