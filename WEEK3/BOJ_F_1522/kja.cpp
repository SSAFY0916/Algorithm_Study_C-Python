#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;

	int s = str.size();

	int answer = s;
	char arr[1000];
	for (int i = 0; i < s; i++) {
		// shift
		int fst = s, lst = -1;
		for (int j = 0; j < s; j++) {
			arr[j] = str[(j + i) % s];
			if (j < fst && arr[j] == 'b') fst = j;
			if (arr[j] == 'a') lst = j;
		}

		int ch = 0;

		while (fst < lst) {
			// swap
			int tmp = arr[fst];
			arr[fst] = arr[lst];
			arr[lst] = tmp;
			ch++;

			while (arr[fst] != 'b')fst++;
			while (arr[lst] != 'a')lst--;
		}

		if (ch < answer) answer = ch;
	}

	cout << answer;

	return 0;
}
