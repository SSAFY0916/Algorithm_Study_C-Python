#include <iostream>
#include <string>
#include <vector>
using namespace std;

int h, w, x = 1, y = 1;
vector<int> height;
vector<int> width;
char grid[1000][1000]; // a ~ z

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> h >> w;

	string tmp;
	for (int i = 0; i < h; i++) {
		cin >> tmp;
		for (int j = 0; j < w; j++) {
			grid[i][j] = tmp[j];
		}
	}

	bool shorten;

	for (int c = h; c > 1; c--) { // 세로방향으로 c개만큼 동일한지 확인
		if (h%c != 0) continue; // c는 h의 약수
		shorten = true;

		for (int i = 0; i < w; i++) { // i번째 열
			char bef = grid[0][i];
			for (int j = 0; j < h; j++) {
				if (j%c == 0) {
					bef = grid[j][i];
				}
				else {
					if (bef != grid[j][i]) {
						shorten = false;
						j = h;
						i = w;
					}
				}
			}
		}

		if (shorten) {
			x = c;
			c = 1;
		}
	}

	for (int c = w; c > 1; c--) { // 가로방향으로 c개만큼 동일한지 확인
		if (w%c != 0) continue; // c는 w의 약수
		shorten = true;

		for (int i = 0; i < h; i++) { // i번째 행
			char bef = grid[i][0];
			for (int j = 0; j < w; j++) {
				if (j%c == 0) {
					bef = grid[i][j];
				}
				else {
					if (bef != grid[i][j]) {
						shorten = false;
						j = w;
						i = h;
					}
				}
			}
		}

		if (shorten) {
			y = c;
			c = 1;
		}
	}

	cout << h / x << " " << w / y << "\n";
	for (int i = 0; i < h; i += x) {
		for (int j = 0; j < w; j += y) {
			cout << grid[i][j];
		}
		cout << "\n";
	}

	return 0;
}
