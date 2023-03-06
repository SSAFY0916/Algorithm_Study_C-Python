// 3079 입국심사

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, c;
vector<int> counter;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> c;
		counter.push_back(c);
	}
	sort(counter.begin(), counter.end());

	long long int answer = (long long int)M * counter[0];

	long long int left = 1;
	long long int right = M * counter[0];
	long long int mid, passed;
	while (left <= right) {
		mid = (left + right) / 2;
		passed = 0;
		for (int i = 0; i < N; i++) {
			passed += mid / counter[i];
		}
		if (passed < M) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			if (mid < answer)
				answer = mid;
		}
	}

	cout << answer;

	return 0;
}
