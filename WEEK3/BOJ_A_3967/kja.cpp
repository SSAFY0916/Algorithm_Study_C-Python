#include <iostream>
#include <string>

using namespace std;

bool made = false;
bool check[13] = { false, };
short int magic[5][9];
short int answer[5][9];
short int pos[12][2] = {
	{0, 4},
	{1, 1}, {1, 3}, {1, 5}, {1, 7},
	{2, 2}, {2, 6},
	{3, 1}, {3, 3}, {3, 5}, {3, 7},
	{4, 4}
};
short int sum[6][4] = {
	{0, 2, 5, 7},
	{0, 3, 6, 10},
	{1, 2, 3, 4},
	{1, 5, 8, 11},
	{4, 6, 9, 11}, 
	{7, 8, 9, 10}
};

void printMagic() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (answer[i][j] == 0) cout << '.';
			else cout << (char)(answer[i][j] - 1 + 'A');
		}
		cout << "\n";
	}
}

short int getValue(int num) {
	int x = pos[num][0];
	int y = pos[num][1];
	return magic[x][y];
}

bool checkNums() {
	int total, filled;

	for (int i = 0; i < 6; i++) {
		total = 0;
		filled = 0;
		for (int j = 0; j < 4; j++) {
			int tmp = getValue(sum[i][j]);
			if (tmp > 0) {
				filled++;
				total += tmp;
			}
		}
		if (filled == 4) {
			if (total != 26) return true;
		}
		else {
			if (total > 26) return true;
		}
	}
	
	return false;
}

void setMagic(int num) {
	if (num == 12) {
		
		if (!checkNums()) {
			made = true;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 9; j++) {
					answer[i][j] = magic[i][j];
				}
			}
		}
		
		return;
	}

	if (made) return;

	int x = pos[num][0];
	int y = pos[num][1];

	if (magic[x][y] != 0) setMagic(num + 1);
	else {
		
		for (int i = 1; i < 13; i++) {
			if (check[i]) continue;
			if (checkNums()) continue;
			
			magic[x][y] = i;
			check[i] = true;
			setMagic(num + 1);
			check[i] = false;
			magic[x][y] = 0;

			if (made) return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	for (int i = 0; i < 5; i++) {
		cin >> str;
		for (int j = 0; j < 9; j++) {
			if (str[j] >= 'A' && str[j] <= 'L') {
				magic[i][j] = (short int)(str[j] - 'A' + 1);
				check[magic[i][j]] = true;
			} else {
				magic[i][j] = 0;
			}
		}
	}

	setMagic(0);

	printMagic();

	return 0;
}
