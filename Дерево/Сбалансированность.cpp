#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> tree;
vector<int> values;
int res = 0;
int dfs(int v) {
	if (v == -1) {
		return 0;
	}
	int a = dfs(tree[v][0]);
	int b = dfs(tree[v][1]);
	if (abs(a - b) > 1) {
		cout << "NO";
		exit(0);
	}
	return max(a, b) + 1;
}
void insert(int x, int v) {
	if (values[v] == x) {
		return;
	}
	if (values[v] > x) {
		if (tree[v][0] != -1) {
			insert(x, tree[v][0]);
		}
		else {
			tree[v][0] = values.size();
			values.push_back(x);
			tree.push_back(vector<int>(2, -1));
		}
	}
	else {
		if (tree[v][1] != -1) {
			insert(x, tree[v][1]);
		}
		else {
			tree[v][1] = values.size();
			values.push_back(x);
			tree.push_back(vector<int>(2, -1));
		}
	}
}
int main() {
	int x;
	while (1) {
		cin >> x;
		if (!x) {
			break;
		}
		if (!tree.size()) {
			values.push_back(x);
			tree.push_back(vector<int>(2, -1));
		}
		else {
			insert(x, 0);
		}
	}
	dfs(0);
	cout << "YES";
}