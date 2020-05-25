#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
set<long long> hash_table;
vector<long long> p_pow(10);

void add_string(string s) {
	long long hash = 0;
	for (int i = 0; i < s.length(); ++i)
		hash += (s[i] - 'a' + 1) * p_pow[i];
	hash_table.insert(hash);
}
void del_string(string s) {
	long long hash = 0;
	for (int i = 0; i < s.length(); ++i)
		hash += (s[i] - 'a' + 1) * p_pow[i];
	if (hash_table.find(hash) != hash_table.end()) {
		hash_table.erase(hash);
	}
}
void check_string(string s) {
	long long hash = 0;
	for (int i = 0; i < s.length(); ++i)
		hash += (s[i] - 'a' + 1) * p_pow[i];
	if (hash_table.find(hash) != hash_table.end()) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}
int main()
{
	const int n = 1e6;
	const int p = 31;
	p_pow[0] = 1;
	for (size_t i = 1; i < p_pow.size(); ++i)
		p_pow[i] = p_pow[i - 1] * p;

	string s, str = "";
	while (str != "#") {
		cin >> str;
		if (str == "+") {
			cin >> s;
			add_string(s);
		}
		if (str == "?") {
			cin >> s;
			check_string(s);
		}
		if (str == "-") {
			cin >> s;
			del_string(s);
		}
	}
}