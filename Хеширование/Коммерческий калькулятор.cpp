#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
multiset<int> values;

int main()
{
	int n, a, sum;
	double res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		values.insert(a);
	}
	while (values.size() > 1) {
		auto it1 = values.begin();
		auto it2 = values.begin();
		it2++;
		sum = *it1 + *it2;
		values.erase(it2);
		values.erase(it1);
		values.insert(sum);
		res += sum * 0.05;
	}
	cout << fixed << setprecision(2) << res;
}