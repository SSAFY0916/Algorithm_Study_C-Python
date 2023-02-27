#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#define MAX 2000

using namespace std;

int n, m;
int index = 0;
map<string, int> filemap; // file 마다 번호 부여
bool isfile[MAX]; // true: file, false: folder
vector<string> files[MAX]; // file structure

int filecount;
map<int, bool> check;

void countFile(string query) {
	int cur = filemap[query];
	if (isfile[cur]) {
		check[cur] = true;
		filecount++;
		return;
	}

	for (int i = 0; i < files[cur].size(); i++) {
		countFile(files[cur][i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		string p, f;
		int c;

		cin >> p >> f >> c;

		if (filemap.find(p) == filemap.end()) {
			filemap[p] = index++;
		}

		if (filemap.find(f) == filemap.end()) {
			filemap[f] = index++;
		}

		if (c == 0) {
			isfile[filemap[f]] = true;
		}
		else {
			isfile[filemap[f]] = false;
		}

		files[filemap[p]].push_back(f);
	}

	int q;
	cin >> q;
	string query;
	for (int i = 0; i < q; i++) {
		cin >> query;

		while (query.find("/") != string::npos) {
			string tmp = query.substr(0, query.find("/"));
			query = query.substr(tmp.size() + 1, query.size() - tmp.size());
		}

		filecount = 0;
		check.clear();
		countFile(query);
		cout << check.size() << " " << filecount << "\n";
	}

	return 0;
}
