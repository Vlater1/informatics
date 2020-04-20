#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector <int> stack;
	int n;
	string str = "";
	while (str != "exit") {
		cin >> str;
		if (str == "push") {
			cin >> n;
			stack.push_back(n);
			cout << "ok\n";
		}
		if (str == "size") {
			cout << stack.size() << "\n";
		}
		if (str == "clear") {
			stack.clear();
			cout << "ok\n";
		}
		if (str == "pop") {
			if (stack.size() == 0) {
				cout << "error\n";
			}
			else {
				cout << stack[stack.size() - 1] << "\n";
				stack.pop_back();
			}
		}
		if (str == "back") {
			if (stack.size() == 0) {
				cout << "error\n";
			}
			else {
				cout << stack[stack.size() - 1] << "\n";
			}
		}
	}
	cout << "bye";
	return 0;


}