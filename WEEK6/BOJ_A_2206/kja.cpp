// 2206 벽 부수고 이동하기

#include <iostream>
#include <string>
#include <queue>
#include <cmath>

#define SIZE 1000
#define MV 1000000

using namespace std;

struct Pos {
	int x;
	int y;
};

int N, M, A;
bool grid[SIZE][SIZE];
int gf[SIZE][SIZE];
int gs[SIZE][SIZE];

queue<Pos> mf;
queue<Pos> ms;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			if (str[j] == '1') grid[i][j] = true;

			gf[i][j] = MV;
			gs[i][j] = MV;
		}
	}

	A = MV;
	if (grid[0][0]) {
		gs[0][0] = 1;
		ms.push(Pos{ 0, 0 });
	}
	else {
		gf[0][0] = 1;
		mf.push(Pos{ 0, 0 });
	}

	while (!mf.empty()) {
		Pos p = mf.front();
		mf.pop();

		int c = gf[p.x][p.y];
		if (p.x == N - 1 && p.y == M - 1) {
			A = min(A, c);
		}
		for (int d = 0; d < 4; d++) {
			int nx = p.x + dx[d];
			int ny = p.y + dy[d];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			
			if (grid[nx][ny]) {
				if (gs[nx][ny] > c + 1) {
					gs[nx][ny] = c + 1;
					ms.push(Pos{ nx, ny });
				}
			}
			else {
				if (gf[nx][ny] > c + 1) {
					gf[nx][ny] = c + 1;
					mf.push(Pos{ nx, ny });
				}
			}
		}
	}

	while (!ms.empty()) {
		Pos p = ms.front();
		ms.pop();

		int c = gs[p.x][p.y];
		if (p.x == N - 1 && p.y == M - 1) {
			A = min(A, c);
		}

		for (int d = 0; d < 4; d++) {
			int nx = p.x + dx[d];
			int ny = p.y + dy[d];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (!grid[nx][ny]) {
				if (gs[nx][ny] > c + 1) {
					gs[nx][ny] = c + 1;
					ms.push(Pos{ nx, ny });
				}
			}
		}
	}

	if (A == MV) cout << -1;
	else cout << A;
	
	return 0;
}
