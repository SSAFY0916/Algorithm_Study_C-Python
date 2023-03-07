#include <iostream>
#include <vector>
#include <utility>
#include <queue>

// 17142 연구소 3

using namespace std;

int n, m;
int answer = 2500; // 가장 적은 시간이 걸리는 경우
bool spreadable = false; // 모든 곳으로 확산될 수 있는 경우
int space[50][50];

vector<pair<int, int>> virus;
vector<bool> virus_select;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool checkFilled(int grid[50][50]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}

void calculateSpread() {
	if (checkFilled(space)) {
		spreadable = true;
		answer = 0;
		return;
	}

	bool check[50][50] = { false, }; // 방문 확인
	int tmp[50][50]; // 바이러스가 확산되는 연구소의 상태
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (space[i][j] == 2) {
				tmp[i][j] = -1; // (비활성화) 바이러스
			}
			else {
				tmp[i][j] = space[i][j]; // 벽 혹은 빈 공간
			}
		}
	}

	queue<pair<int, int>> spread;
	for (int i = 0; i < virus.size(); i++) {
		if (virus_select[i]) {
			spread.push({ virus[i].first, virus[i].second });
			check[virus[i].first][virus[i].second] = true;
			tmp[virus[i].first][virus[i].second] = 1; // 활성화된 바이러스
		}
	}

	int time = 1;
	while (!spread.empty()) {

		int size = spread.size();

		while (size-- > 0) {
			int x = spread.front().first;
			int y = spread.front().second;
			spread.pop();

			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (tmp[nx][ny] > 0) continue; // 벽 혹은 방문한 곳

				if (check[nx][ny]) continue;
				check[nx][ny] = true;

				if (tmp[nx][ny] == 0) { // 빈 공간으로 퍼짐
					tmp[nx][ny] = time;
				}

				spread.push({ nx, ny }); // 빈 공간과 비활성화 바이러스
			}
		}

		if (!checkFilled(tmp)) {
			time++;
		}

		if (time > answer) return;
	}

	if (!checkFilled(tmp)) return;

	spreadable = true;
	if (time < answer) answer = time;
}

void selectVirus(int pos, int cnt) {
	if (cnt == m) {
		calculateSpread();
		return;
	}

	if (pos >= virus_select.size()) return;

	// 바이러스 선택
	virus_select[pos] = true;
	selectVirus(pos + 1, cnt + 1);
	virus_select[pos] = false;
	selectVirus(pos + 1, cnt);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	// 연구소의 상태
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> space[i][j];
			if (space[i][j] == 2) {
				virus.push_back({ i, j });
				virus_select.push_back(false);
			}
		}
	}

	// 바이러스 m개 선택
	selectVirus(0, 0);

	if (spreadable) cout << answer;
	else cout << "-1";

	return 0;
}
