#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int sift_up(int* heap, int ind) {
	if (ind > 1) {
		while (heap[ind] > heap[ind / 2]) {
			swap(heap[ind], heap[ind / 2]);
			ind /= 2;
			if (ind == 1) {
				break;
			}
		}
	}
	return ind;
}
int sift_down(int* heap, int ind, int n) {
	int fl = 1;
	if (n > 1) {
		int left, right;
		while (2 * ind < n) {
			left = 2 * ind;
			right = 2 * ind + 1;
			int a = left;
			if (right < n && heap[left] < heap[right]) {
				a = right;
			}
			if (heap[ind] >= heap[a]) {
				break;
			}
			swap(heap[ind], heap[a]);
			ind = a;
		}
	}
	return ind;
}
void extract_max(int* heap, int n) {
	int count = n - 1, ind;
	if (!count) {
		cout << "-1\n";
	}
	else {
		int ans = heap[1];
		heap[1] = heap[count];
		ind = sift_down(heap, 1, count);
		count--;
		if (!count) {
			ind = 0;
		}
		cout << ind << " " << ans << "\n";
	}
}
int main()
{
	int n, x, m, y, ind, len = 0, heap[100002], s = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		if (x == 1) {
			extract_max(heap, len + 1);
			if (len > 0) {
				len--;
			}
		}
		if (x == 2) {
			if (len == n) {
				cin >> y;
				cout << "-1\n";
			}
			else {
				cin >> y;
				heap[len + 1] = y;
				len++;
				ind = sift_up(heap, len);
				cout << ind << "\n";
			}
		}
	}
	for (int i = 1; i < len + 1; i++) {
		cout << heap[i] << " ";
	}
}