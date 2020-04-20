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
	vector <char> stack;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {

		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
			stack.push_back(str[i]);

		}
		else {
			if (stack.size() == 0) {
				cout << "no";
				return 0;
			}
			char ch = stack.back();
			if (ch == '(' && str[i] == ')') {
				stack.pop_back();
			}
			else if (ch == '{' && str[i] == '}') {
				stack.pop_back();
			}
			else if (ch == '[' && str[i] == ']') {
				stack.pop_back();
			}
			else {
				cout << "no";
				return 0;
			}
		}
	}
	if (stack.size() == 0) {
		cout << "yes";
	}
	else {
		cout << "no";
	}
}