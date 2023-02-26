#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int n, m, total, whitePower, bluePower;
bool target; // true: white, false: blue
bool arr[100][100]; // true: white, false: blue
bool check[100][100];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void searchArea(int x, int y) {
	check[x][y] = true;
	total++;

	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if (check[nx][ny] || (arr[nx][ny] ^ target)) continue;
		searchArea(nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	string str;
	for (int i = 0; i < m; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			if (str[j] == 'W') arr[i][j] = true;
			else arr[i][j] = false;
			check[i][j] = false;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				total = 0;
				target = arr[i][j];
				searchArea(i, j);
				if (target) whitePower += pow(total, 2);
				else bluePower += pow(total, 2);
			}
		}
	}

	cout << whitePower << " " << bluePower;

	return 0;
}
