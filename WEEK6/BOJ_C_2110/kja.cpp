// 2110 공유기 설치

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> house;

int searchDis() {
	int disL = 0;
	int disR = house[N - 1];

	int disA;
	while (disL <= disR) {
		int cnt = 1;
		int dis = (disL + disR) / 2;

		int pre = house[0];
		for (int i = 1; i < N; i++) {
			if (house[i] - pre >= dis) {
				cnt++;
				pre = house[i];
			}
		}
	
		if (cnt >= C) {
			disA = dis;
			disL = dis + 1;
		}
		else {
			disR = dis - 1;
		}
	}

	return disA;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		house.push_back(tmp);
	}
	
	sort(house.begin(), house.end());
	
	cout << searchDis();

	return 0;
}
