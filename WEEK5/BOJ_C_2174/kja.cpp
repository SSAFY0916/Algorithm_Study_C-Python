#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

// 2174 로봇 시뮬레이션

using namespace std;

struct Bot {
	int x;
	int y;
	int d;
};

int A, B, N, M;
int grid[101][101];
vector<Bot> robots;

// R D L U
int dx[5] = { 0, 0, 1, 0, -1 };
int dy[5] = { 0, 1, 0, -1, 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	robots.push_back(Bot{ -1, -1, -1 }); // robot in index 0

	cin >> A >> B >> N >> M;
	for (int i = 1; i <= N; i++) {
		int x, y;
		cin >> x >> y;
		grid[x - 1][y - 1] = i; // 좌표계 위에 각 로봇 위치 표시

		char d;
		cin >> d;
		// vector로 각 로봇의 위치와 방향 저장
		switch (d)
		{
			case 'N':
				robots.push_back(Bot{ x - 1, y - 1, 1 });
				break;
			case 'E':
				robots.push_back(Bot{ x - 1, y - 1, 2 });
				break;
			case 'S':
				robots.push_back(Bot{ x - 1, y - 1, 3 });
				break;
			case 'W':
				robots.push_back(Bot{ x - 1, y - 1, 4 });
				break;
		}
	}

	bool passed = false;
	for (int i = 0; i < M; i++) {
		int num, cnt;
		char dir;

		cin >> num >> dir >> cnt;
		if (passed) continue;

		if (dir == 'F') {
			int x = robots[num].x;
			int y = robots[num].y;
			int d = robots[num].d;
			grid[x][y] = 0;

			int hitted = 0;
			bool movable = true;
			for (int c = 0; c < cnt; c++) {
				int nx = x + dx[d];
				int ny = y + dy[d];

				if (nx < 0 || nx >= A || ny < 0 || ny >= B) {
					movable = false;
					hitted = -1;
				}
				else if (grid[nx][ny] != 0) {
					movable = false;
					hitted = grid[nx][ny];
				}
				else {
					x = nx;
					y = ny;
				}
			}

			if (movable) {
				grid[x][y] = num;

				robots[num].x = x;
				robots[num].y = y;
			}
			else {
				passed = true;
				if (hitted == -1) {
					cout << "Robot " << num << " crashes into the wall";
				}
				else {
					cout << "Robot " << num << " crashes into robot " << hitted;
				}
			}
		}
		else {
			cnt %= 4;
			if (dir == 'L') {
				robots[num].d -= cnt;
				if (robots[num].d < 1) robots[num].d += 4;
			}
			else { // dir == 'R'
				robots[num].d += cnt;
				if (robots[num].d > 4) robots[num].d -= 4;
			}
		}
	}

	if (!passed)
		cout << "OK";

	return 0;
}
