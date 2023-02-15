#include <iostream>
#define LIMIT 100000
using namespace std;

int n, r, x, y, dir; // 1: right, 2: down, 3: left, 4: up
int laser_x, laser_y;
bool grid[52][52];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n >> r;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				grid[i][j] = false;
			}
		}

		for (int i = 0; i < r; i++) {
			cin >> x >> y;
			grid[x][y] = true;
		}

		cin >> x >> y;
		if (x == 0) {
			x = 1;
			dir = 2;
		}
		else if (x == n + 1) {
			x = n;
			dir = 4;
		}
		else if (y == 0) {
			y = 1;
			dir = 1;
		}
		else if (y == n + 1) {
			y = n;
			dir = 3;
		}

		int count = 0;
		while (count < LIMIT) {
			if (x == 0 || x == n + 1 || y == 0 || y == n + 1) {
				cout << x << " " << y << "\n";
				break;
			}

			if (grid[x][y]) {
				dir++;
				if (dir > 4)
					dir -= 4;

				switch (dir)
				{
				case 1:
					y++;
					break;
				case 2:
					x++;
					break;
				case 3:
					y--;
					break;
				case 4:
					x--;
					break;
				}
			}
			else {
				switch (dir)
				{
				case 1:
					y++;
					break;
				case 2:
					x++;
					break;
				case 3:
					y--;
					break;
				case 4:
					x--;
					break;
				}
			}
			count++;
		}

		if (count >= LIMIT)
			cout << "0 0\n";
	}

	return 0;
}
