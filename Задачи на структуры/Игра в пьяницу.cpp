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
	queue <int> first, second;
	int n, count = 0;
	for (int i = 0; i < 5; i++) {
		cin >> n;
		first.push(n);
	}
	for (int i = 0; i < 5; i++) {
		cin >> n;
		second.push(n);
	}
	while (first.size() && second.size()) {
		int a = first.front();
		int b = second.front();
		first.pop();
		second.pop();
		count++;
		if (a == 0 && b == 9) {
			first.push(a);
			first.push(b);
		}
		else {
			if (a == 9 && b == 0) {
				second.push(a);
				second.push(b);
			}
			else {
				if (a > b) {
					first.push(a);
					first.push(b);
				}
				else {
					second.push(a);
					second.push(b);
				}
			}
		}
	}
	if (count >= 1e6) {
		cout << "botva";
	}
	else {
		if (!first.size()) {
			cout << "second " << count;
		}
		else {
			cout << "first " << count;
		}
	}
}