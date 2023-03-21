// 8982 수족관 1

#include <iostream>
#include <vector>

using namespace std;

int N, K, pleft, pright;
int pool[40001];
int water[40001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	int px, py;
	cin >> px >> py;
	pleft = px;
	for (int i = 1; i < N; i++) {
		int x, y;
		cin >> x >> y;

		if (px == x) { // 수직선분
			py = y;
		}
		else { // 수평선분
			for (int j = px; j < x; j++) {
				pool[j] = y;
			}
			px = x;
		}
	}
	pright = px;

	cin >> K;
	for (int i = 0; i < K; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int x = (a + c) / 2;
		int y = b;

		water[x] = y;
		int upper = y;
		bool upped = false;
		while (x-- > pleft) {
			if (water[x] > upper) continue;
			if (pool[x] >= upper) {
				water[x] = upper;
			}
			else {
				upped = true;
				upper = pool[x];
				water[x] = upper;
			}

		}
		x = (a + c) / 2;
		upper = y;
		while (x++ < pright) {
			if (water[x] > upper) continue;
			if (pool[x] >= upper) {
				water[x] = upper;
			}
			else {
				upped = true;
				upper = pool[x];
				water[x] = upper;
			}
		}

	}

	int total = 0;
	for (int i = pleft; i <= pright; i++) {
		if (pool[i] <= water[i]) continue;
		total += pool[i] - water[i];
	}
	cout << total;

	return 0;
}
