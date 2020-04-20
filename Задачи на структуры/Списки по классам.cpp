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
	vector <string> a, b, c;
	string str;
	while (getline(cin, str)) {
		stringstream s;
		s << str;
		int n;
		string name;
		s >> n >> name;
		if (n == 9) {
			a.push_back(name);
		}
		if (n == 10) {
			b.push_back(name);
		}
		if (n == 11) {
			c.push_back(name);
		}
	}
	for (int i = 0; i < a.size(); i++) {
		cout << "9 " << a[i] << "\n";
	}
	for (int i = 0; i < b.size(); i++) {
		cout << "10 " << b[i] << "\n";
	}
	for (int i = 0; i < c.size(); i++) {
		cout << "11 " << c[i] << "\n";
	}

}