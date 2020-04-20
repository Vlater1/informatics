#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
	const int size = 1e6;
	int n, mas[size], qh = 0, qt = 0, len = 0;
	string str = "";
	while (str != "exit") {
		cin >> str;
		if (str == "push") {
			cin >> n;
			mas[qt] = n;
			qt++;
			if (qt >= size) {
				qt = 0;
			}
			len++;
			cout << "ok\n";
		}
		if (str == "size") {
			cout << len << "\n";
		}
		if (str == "clear") {
			qh = 0;
			qt = 0;
			len = 0;
			cout << "ok\n";
		}
		if (str == "pop") {
			if (len == 0) {
				cout << "error\n";
			}
			else {
				cout << mas[qh] << "\n";
				qh++;
				if (qh >= size) {
					qh = 0;
				}
				len--;
			}
		}
		if (str == "front") {
			if (len == 0) {
				cout << "error\n";
			}
			else {
				cout << mas[qh] << "\n";
			}
		}
	}
	cout << "bye";
	return 0;


}