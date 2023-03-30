// 6497 전력난

#include <iostream>
#include <climits>
#include <vector>
#include <utility>
#include <algorithm>

#define MAX 200001
using namespace std;

struct Con {
	int c1, c2, d;
};

int m, n, answer;
vector<Con> route;
int parent[MAX];

bool compare(Con a, Con b) {
	return a.d < b.d;
}

int findParent(int a) {
	if (a == parent[a]) return a;
	else return parent[a] = findParent(parent[a]);
}

bool checkParent(int a, int b) {
	return findParent(a) == findParent(b);
}

void unionParent(int a, int b) {
	int ap = findParent(a);
	int bp = findParent(b);
	parent[bp] = ap;
}

void checkRoute() {
	for (int i = 0; i < n; i++) {
		int c1 = route[i].c1;
		int c2 = route[i].c2;

		if (!checkParent(c1, c2)) {
			unionParent(c1, c2);
			answer += route[i].d;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	while(true) {
		cin >> m >> n;
		if (m == 0 && n == 0) break;

		// initialize
		answer = 0;
		route.clear();
		for (int i = 0; i < m; i++) {
			parent[i] = i;
		}

		int totalRoute = 0;
		for (int i = 0; i < n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			route.push_back(Con{ x, y, z });
			totalRoute += z;
		}

		sort(route.begin(), route.end(), compare);

		checkRoute();
		cout << totalRoute - answer << "\n";
	}

	return 0;
}
