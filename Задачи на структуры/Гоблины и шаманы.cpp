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
	deque <int> first, second;
	string str, num;
	int n, a, b;
	char ch;
	cin >> n;
	getline(cin, str);
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		stringstream s;
		s << str;
		s >> ch;
		if (ch == '+') {
			s >> a;
			if (first.size() == 0) {
				first.push_back(a);
			}
			else if (first.size() == second.size()) {
				b = second.front();
				second.pop_front();
				first.push_back(b);
				second.push_back(a);
			}
			else {
				second.push_back(a);
			}
		}
		if (ch == '*') {
			s >> a;
			if (first.size() == 0) {
				first.push_back(a);
			}
			else if (first.size() == second.size()) {
				first.push_back(a);
			}
			else {
				second.push_front(a);
			}
		}
		if (ch == '-') {
			cout << first.front() << "\n";
			first.pop_front();
			if (first.size() < second.size()) {
				b = second.front();
				second.pop_front();
				first.push_back(b);
			}
		}
	}

}