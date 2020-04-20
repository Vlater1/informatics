#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int sift_up(int* heap, int ind) {
	if (ind > 1) {
		while (heap[ind] >= heap[ind / 2]) {
			swap(heap[ind], heap[ind / 2]);
			ind /= 2;
			if (ind == 1) {
				break;
			}
		}
	}
	return ind;
}
int sift_down(int* heap, int ind, int sum, int n) {
	heap[ind] -= sum;
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
int main()
{
	int n, x, m, ind, sum, heap[100002], s = 0;
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> x;
		heap[i] = x;
		sift_up(heap, i);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> ind >> sum;
		ind = sift_down(heap, ind, sum, n + 1);
		cout << ind << "\n";
	}
	for (int i = 1; i < n + 1; i++) {
		cout << heap[i] << " ";
	}
}