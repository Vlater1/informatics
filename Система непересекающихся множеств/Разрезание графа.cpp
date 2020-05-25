#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>
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
	int n, m, q;

	cin >> n >> m >> q;
	dsu.resize(n + 1);
	r.resize(n + 1);
	vector < tuple<int, int, int> > que(q);
	for (int i = 0; i < n; ++i)
		dsu[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
	}
	for (int i = 0; i < q; i++) {
		string str;
		int a, b;
		cin >> str >> a >> b;
		if (str == "ask") {
			que[i] = make_tuple(1, a, b);
		}
		else {
			que[i] = make_tuple(2, a, b);
		}
	}
	vector <string> res;
	for (int i = que.size() - 1; i >= 0; i--) {
		int a, b, c;
		tie(a, b, c) = que[i];
		if (a == 1) {
			if (find_set(b) == find_set(c)) {
				res.push_back("YES\n");
			}
			else {
				res.push_back("NO\n");
			}
		}
		else {
			union_sets(b, c);
		}
	}
	for (int i = res.size() - 1; i >= 0; i--) {
		cout << res[i];
	}
}