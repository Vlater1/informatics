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
		dsu[b] = a;
		if (r[a] == r[b])
			++r[a];
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector < pair<int, int> > graph(m);
	for (int i = 0; i < m; i++) {
		cin >> graph[i].first >> graph[i].second;
	}

	set < pair<int, int> > res;
	pair<int, int> num;

	dsu.resize(n + 1);
	r.resize(n);
	for (int i = 0; i < n; ++i)
		dsu[i] = i;
	for (int i = 0; i < m; ++i) {
		int a = graph[i].first, b = graph[i].second;
		if (find_set(a) != find_set(b)) {
			res.insert(graph[i]);
			num = graph[i];
			union_sets(a, b);
		}
	}
	int ans = 1;

	for (int i = 0; i < m; i++) {
		if (graph[i] == num) {
			break;
		}
		ans++;
	}
	cout << ans;
}