// 16928 뱀과 사다리 게임

#include <iostream>
#include <map>
#include <queue>
#include <utility>

using namespace std;

int N, M;
map<int, int> goup;
map<int, int> godown;

queue<pair<int, int>> q;
int answer[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		goup[a] = b;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		godown[a] = b;
	}

	answer[1] = 1;
	q.push({ 1,0 });
	while (!q.empty()) {
		int p = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int np = p + i;
			if (np > 100) continue;
			if (answer[np] > 0) continue;

			if (goup.find(np) != goup.end()) {
				answer[np] = c + 1;
				answer[goup[np]] = c + 1;
				q.push({ goup[np],c + 1 });
			}
			else if (godown.find(np) != godown.end()) {
				answer[np] = c + 1;
				answer[godown[np]] = c + 1;
				q.push({ godown[np],c + 1 });
			}
			else {
				answer[np] = c + 1;
				q.push({ np,c + 1 });
			}
		}
	}

	cout << answer[100];
	return 0;
}
