#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	const int size = 1e6;
	int n, mas[size], qh = 0, qt = 0, len = 0;
	string str = "";
	while (str != "exit") {
		cin >> str;
		if (str == "push_back") {
			cin >> n;
			mas[qt] = n;
			qt++;
			if (qt >= size) {
				qt = 0;
			}
			len++;
			cout << "ok\n";
		}
		if (str == "push_front") {
			cin >> n;
			qh--;
			if (qh < 0) {
				qh = size - 1;
			}
			mas[qh] = n;
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
		if (str == "pop_back") {
			if (len == 0) {
				cout << "error\n";
			}
			else {
				if (!qt) {
					cout << mas[size - 1] << "\n";
				}
				else {
					cout << mas[qt - 1] << "\n";
				}
				qt--;
				if (qt < 0) {
					qt = size - 1;
				}
				len--;
			}
		}
		if (str == "pop_front") {
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
		if (str == "back") {
			if (len == 0) {
				cout << "error\n";
			}
			else {
				if (!qt) {
					cout << mas[size - 1] << "\n";
				}
				else {
					cout << mas[qt - 1] << "\n";
				}
			}
		}
	}
	cout << "bye";
	return 0;


}