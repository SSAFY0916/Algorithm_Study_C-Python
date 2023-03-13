#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

// 20056 마법사 상어와 파이어볼

using namespace std;

struct FireBall {
	int r, c, m, s, d;
};

int N, M, K;
int grid[51][51]; // 1~50
vector<FireBall> pos[51][51];
queue<FireBall> balls;

int dx[9] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[9] = { 0, 1, 1, 1, 0, -1, -1, -1, };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;

		// grid[r][c] = i;
		balls.push(FireBall{ r, c, m, s, d });
	}

	for (int k = 0; k < K; k++) { // K초 동안 반복
		while (!balls.empty()) {
			FireBall cur = balls.front();
			balls.pop();

			int len = cur.s % N;
			int nr = cur.r + (dx[cur.d] * len);
			int nc = cur.c + (dy[cur.d] * len);
			
			if (nr < 1) nr += N;
			else if (nr > N) nr -= N;
			if (nc < 1) nc += N;
			else if (nc > N) nc -= N;
		
			cur.r = nr;
			cur.c = nc;
			pos[nr][nc].push_back(cur);
		}

		vector<FireBall> tmp[51][51]; // 나뉜 정보 저장
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (pos[i][j].size() == 0) continue;

				FireBall cur = pos[i][j][0];
				if (pos[i][j].size() == 1) {
					tmp[i][j].push_back(cur);
				}
				else {
					bool same = true;

					int mm = cur.m;
					int ss = cur.s;
					int dd = cur.d; // 기준 방향

					for (int l = 1; l < pos[i][j].size(); l++) {
						mm += pos[i][j][l].m;
						ss += pos[i][j][l].s;
						if (dd % 2 != pos[i][j][l].d % 2) {
							same = false;
						}
					}

					mm /= 5;
					if (mm > 0) {
						ss /= pos[i][j].size();
						if (same) { // 0, 2, 4, 6
							tmp[i][j].push_back(FireBall{ cur.r, cur.c, mm, ss, 0 });
							tmp[i][j].push_back(FireBall{ cur.r, cur.c, mm, ss, 2 });
							tmp[i][j].push_back(FireBall{ cur.r, cur.c, mm, ss, 4 });
							tmp[i][j].push_back(FireBall{ cur.r, cur.c, mm, ss, 6 });
						}
						else { // 1, 3, 5, 7
							tmp[i][j].push_back(FireBall{ cur.r, cur.c, mm, ss, 1 });
							tmp[i][j].push_back(FireBall{ cur.r, cur.c, mm, ss, 3 });
							tmp[i][j].push_back(FireBall{ cur.r, cur.c, mm, ss, 5 });
							tmp[i][j].push_back(FireBall{ cur.r, cur.c, mm, ss, 7 });
						}
					}
					
				}

				pos[i][j].clear();
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (tmp[i][j].size() == 0) continue;

				for (int l = 0; l < tmp[i][j].size(); l++) {
					balls.push(tmp[i][j][l]);
				}
			}
		}
	}

	int total = 0;
	while (!balls.empty()) {
		total += balls.front().m;
		balls.pop();
	}

	cout << total;

	return 0;
}
