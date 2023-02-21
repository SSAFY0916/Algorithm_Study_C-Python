#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m, c, x, y, tmp;
bool grid[1000][1000];
int answer[1000][1000];
queue<pair<int, pair<int, int>>> mv;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			if (tmp == 0) {
				grid[i][j] = false;
				answer[i][j] = 0;
			}
			else {
				grid[i][j] = true;
				if (tmp == 2) {
					answer[i][j] = 0;
					mv.push({ answer[i][j], { i, j } });
				}
				else {
					answer[i][j] = -1;
				}
			}
		}
	}
	
	while (!mv.empty()) {
		c = mv.front().first + 1;
		x = mv.front().second.first;
		y = mv.front().second.second;
		mv.pop();;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (answer[nx][ny] == -1) {
				answer[nx][ny] = c;
				mv.push({ c,{ nx, ny } });
			}
		}
		c++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
