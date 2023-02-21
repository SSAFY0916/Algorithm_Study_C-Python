#include <iostream>
#include <queue>
#include <vector>
#include <utility>

#define MX 4

using namespace std;

struct fish {
	int x; int y; int d;
};

int M, S;
pair<int, int> shark;
vector<fish> fishGrid[MX][MX]; // 현재 물고기
vector<fish> copyGrid[MX][MX]; // 복제할 물고기

int smellGrid[MX][MX];

int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

void copyFish(vector<fish> a[MX][MX], vector<fish> b[MX][MX]) {
	for (int i = 0; i < MX; i++) {
		for (int j = 0; j < MX; j++) {
			b[i][j] = a[i][j];
		}
	}
}

bool found_way;
int max_shark;
int max_way[3];
int tmp_way[3];
bool checkGrid[MX][MX];

void findSharkWay(int p, int x, int y, int c) {
	if (p == 3) {
		if (!found_way) {
			for (int i = 0; i < 3; i++) {
				max_way[i] = tmp_way[i];
			}
			found_way = true;
		}

		if (c > max_shark) {
			max_shark = c;
			for (int i = 0; i < 3; i++) {
				max_way[i] = tmp_way[i];
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dr[i];
		int ny = y + dc[i];
		if (nx < 0 || nx >= MX || ny < 0 || ny >= MX) continue;
		tmp_way[p] = i;
		if (checkGrid[nx][ny]) {
			findSharkWay(p + 1, nx, ny, c);
		}
		else {
			checkGrid[nx][ny] = true;
			findSharkWay(p + 1, nx, ny, c + fishGrid[nx][ny].size());
			checkGrid[nx][ny] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> S;

	for (int i = 0; i < M; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		fishGrid[x - 1][y - 1].push_back(fish{ x - 1, y - 1, d });
	}
	cin >> shark.first >> shark.second;
	shark.first--; shark.second--;

	for (int i = 0; i < MX; i++) {
		for (int j = 0; j < MX; j++) {
			smellGrid[i][j] = 0;
		}
	}

	for (int s = 0; s < S; s++) {
		// 1. 물고기 복제
		copyFish(fishGrid, copyGrid);

		// 2. 물고기 이동
		vector<fish> tmpGrid[MX][MX];
		
		for (int i = 0; i < MX; i++) {
			for (int j = 0; j < MX; j++) {

				for (int k = 0; k < fishGrid[i][j].size(); k++) {
					int x = fishGrid[i][j][k].x;
					int y = fishGrid[i][j][k].y;
					int d = fishGrid[i][j][k].d;

					for (int j = 0; j < 8; j++) {
						int nd = d - j; // 이동 불가 시 이동 방향을 45도 반시계 회전
						if (nd <= 0) nd += 8;
						int nx = x + dx[nd];
						int ny = y + dy[nd];

						if (nx < 0 || nx >= MX || ny < 0 || ny >= MX) continue; // 격자 밖
						if (shark.first == nx && shark.second == ny) continue; // 상어

						if (smellGrid[nx][ny] == 0) { // 냄새 없음
							x = nx;
							y = ny;
							d = nd;
							j = 8;
						}
					}
					tmpGrid[x][y].push_back(fish{ x, y, d });
				}

			}
		}
		copyFish(tmpGrid, fishGrid);

		// 3. 상어 이동
		max_shark = 0;
		for (int i = 0; i < MX; i++) {
			for (int j = 0; j < MX; j++) {
				checkGrid[i][j] = false;
			}
		}
		found_way = false;
		findSharkWay(0, shark.first, shark.second, 0);

		for (int i = 0; i < 3; i++) {
			int nx = shark.first + dr[max_way[i]];
			int ny = shark.second + dc[max_way[i]];
			if (fishGrid[nx][ny].size() > 0) {
				fishGrid[nx][ny].clear();
				smellGrid[nx][ny] = 3;
			}
			shark.first = nx;
			shark.second = ny;
		}

		// 4. 물고기 냄새 소멸
		for (int i = 0; i < MX; i++) {
			for (int j = 0; j < MX; j++) {
				if (smellGrid[i][j] > 0) smellGrid[i][j]--;
			}
		}

		// 5. 복제 적용
		for (int i = 0; i < MX; i++) {
			for (int j = 0; j < MX; j++) {
				for (int k = 0; k < copyGrid[i][j].size(); k++) {
					fishGrid[i][j].push_back(copyGrid[i][j][k]);
				}
			}
		}
	}

	// 6. 물고기 수 반환
	int answer = 0;
	for (int i = 0; i < MX; i++) {
		for (int j = 0; j < MX; j++) {
			answer += fishGrid[i][j].size();
		}
	}
	cout << answer;

	return 0;
}
