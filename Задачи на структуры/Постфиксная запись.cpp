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
	vector <int> stack;
	string str, num;
	int a, b;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if ('0' <= str[i] && str[i] <= '9') {
			num += str[i];
			if (str[i + 1] == ' ') {
				stringstream s;
				s << num;
				int n;
				s >> n;
				stack.push_back(n);
				num = "";
			}
		}
		if (str[i] == '+') {
			a = stack.back();
			stack.pop_back();
			b = stack.back();
			stack.pop_back();
			stack.push_back(a + b);
		}
		if (str[i] == '-') {
			a = stack.back();
			stack.pop_back();
			b = stack.back();
			stack.pop_back();
			stack.push_back(b - a);
		}
		if (str[i] == '*') {
			a = stack.back();
			stack.pop_back();
			b = stack.back();
			stack.pop_back();
			stack.push_back(a * b);
		}
	}
	cout << stack.back();
}