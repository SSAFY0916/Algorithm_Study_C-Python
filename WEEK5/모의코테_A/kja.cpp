#include <iostream>
#include <queue>

// 25331 Drop 7

using namespace std;

int N, minimum = 343;
int origin[7][7];

int dropBall(int c);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			cin >> origin[i][j];
		}
	}
	
	cin >> N;
	
	for (int i = 0; i < 7; i++) {
		int tmp = dropBall(i); // i번째 열에 공 떨어뜨리기
		if (tmp < minimum) minimum = tmp;
	}

	cout << minimum;

	return 0;
}

int dropBall(int c){
	int copied[7][7];
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			copied[i][j] = origin[i][j];
		}
	}

	// 공 떨어뜨리기
	for (int i = 1; i < 7; i++) {
		if (copied[i][c] > 0) {
			copied[i - 1][c] = N;
			i = 7;
		}
	}
	if (copied[6][c] == 0) copied[6][c] = N;

	bool boomed = false;
	do {
		boomed = false;

		bool boom[7][7];
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				boom[i][j] = false;
			}
		}

		// 세로 방향 터지는 것 확인
		for (int i = 0; i < 7; i++) {
			int cnt = 0;
			for (int j = 0; j < 7; j++) {
				if (copied[j][i] > 0) cnt++;
			}
			if (cnt == 0) continue;
			for (int j = 0; j < 7; j++) {
				if (copied[j][i] == cnt) {
					boom[j][i] = true;
				}
			}
		}
		// 가로 방향 터지는 것 확인
		for (int i = 0; i < 7; i++) {
			int cnt = 0, stt = 0;
			for (int j = 0; j < 7; j++) {
				if (copied[i][j] == 0) { // 지금까지의 가로 그룹 확인
					if (cnt > 0) {
						for (int k = stt; k < j; k++) {
							if (copied[i][k] == cnt) boom[i][k] = true;
						}
						cnt = 0;
						stt = j + 1;
					}
				}
				else { // 새 가로 그룹 진행
					cnt++;
				}
			}
			if (cnt > 0) { // stt~ 6의 가로 그룹 확인
				for (int k = stt; k < 7; k++) {
					if (copied[i][k] == cnt) boom[i][k] = true;
				}
			}
		}

		// 터뜨리기 (지우기)
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				if (boom[i][j]) {
					copied[i][j] = 0;
					boomed = true;
				}
			}
		}
		
		if (boomed) {
			for (int i = 0; i < 7; i++) {
				queue<int> q;
				for (int j = 6; j >= 0; j--) {
					if (copied[j][i] > 0) {
						q.push(copied[j][i]);
						copied[j][i] = 0;
					}
				}
				int j = 6;
				while (!q.empty()) {
					copied[j][i] = q.front();
					q.pop();
					j--;
				}
			}
		}

	} while (boomed);
	
	// 남은 공 개수 반환
	int total = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (copied[i][j] > 0) total++;
		}
	}

	return total;
}
