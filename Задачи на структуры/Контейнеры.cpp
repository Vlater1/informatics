#include <iostream>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <sstream>
using namespace std;

int main()
{
	vector <vector<int>> kont;
	int n, m, k;
	kont.resize(4);
	cin >> n;
	if (n == 1) {
		return 0;
	}
	if (n == 2) {
		for (int i = 0; i < n; i++) {
			cin >> m;
			if (m) {
				for (int j = 0; j < m; j++) {
					cin >> k;
					kont[i].push_back(k);
					kont[i + 2].push_back(k);
				}
			}
		}
		k = kont[3].size() - 1;
		while (kont[3].size() > 0) {
			kont[2].push_back(kont[3][k]);
			kont[3].pop_back();
			k = kont[3].size() - 1;
		}
		k = kont[2].size() - 1;
		while (kont[2].size() > 0) {
			if (kont[2][k] == 1) {
				for (int i = k - 1; i >= 0; i--) {
					if (kont[2][i] == 2) {
						cout << "0";
						return 0;
					}
				}
				break;
			}
			else {
				kont[2].pop_back();
				k = kont[2].size() - 1;
			}
		}
		k = kont[0].size() - 1;
		if (k != -1) {
			while (kont[0][k] == 2) {
				cout << "1 2\n";
				kont[1].push_back(kont[0][k]);
				kont[0].pop_back();
				k = kont[0].size() - 1;
			}
		}
		k = kont[1].size() - 1;
		if (k != -1) {
			while (kont[1][k] == 1) {
				cout << "2 1\n";
				kont[0].push_back(kont[1][k]);
				kont[1].pop_back();
				k = kont[1].size() - 1;
			}
		}
	}
	else {
		cin >> m;
		if (m) {
			for (int i = 0; i < m; i++) {
				cin >> k;
				kont[0].push_back(k);
			}
		}
		for (int i = 1; i < n; i++) {
			cin >> m;
			if (m) {
				for (int j = 0; j < m; j++) {
					cin >> k;
					kont[1].push_back(k);
				}
				for (int j = kont[1].size() - 1; j >= 0; j--) {
					kont[0].push_back(kont[1][j]);
					cout << i + 1 << " " << "1\n";
				}
				kont[1].clear();
			}
		}
		while (kont[0].size() > 0) {
			k = kont[0].size() - 1;
			if (kont[0][k] == 1 || kont[0][k] == 2) {
				kont[1].push_back(kont[0][k]);
				kont[0].pop_back();
				cout << "1 2\n";
			}
			else {
				cout << "1 " << kont[0][k] << "\n";
				kont[0].pop_back();
			}
		}
		if (kont[1].size() > 0) {
			while (kont[1].size() > 0) {
				k = kont[1].size() - 1;
				if (kont[1][k] == 1) {
					cout << "2 1\n";
					kont[1].pop_back();
				}
				else if (kont[1][k] == 2) {
					cout << "2 3\n";
					kont[2].push_back(kont[1][k]);
					kont[1].pop_back();
				}
			}
			for (int j = kont[2].size() - 1; j >= 0; j--) {
				cout << "3 2\n";
			}
		}
	}
}