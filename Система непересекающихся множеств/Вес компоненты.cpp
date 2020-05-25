#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
vector<int> dsu;
vector<int> r;
vector<int> cost;

int find_set(int v) {
	if (v == dsu[v])
		return v;
	return dsu[v] = find_set(dsu[v]);
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (r[a] < r[b])
			swap(a, b);
		cost[a] += cost[b];
		dsu[b] = a;
		if (r[a] == r[b])
			++r[a];
	}
}

int main()
{
	int n, m, a, x, y, w;
	cin >> n >> m;
	dsu.resize(n + 1);
	r.resize(n + 1);
	cost.resize(n + 1);
	for (int i = 0; i < n + 1; i++) {
		cost[i] = 0;
	}
	vector < pair<int, pair<int, int>> > graph(m);
	for (int i = 0; i < n; ++i)
		dsu[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (a == 1) {
			cin >> x >> y >> w;
			if (find_set(x) == find_set(y)) {
				y = find_set(x);
				cost[y] += w;
			}
			else {
				union_sets(x, y);
				y = find_set(x);
				cost[y] += w;
			}
		}
		if (a == 2) {
			cin >> x;
			y = find_set(x);
			cout << cost[y] << "\n";
		}
	}
}