#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int sift_up(int* heap, int ind, int sum) {
	heap[ind] += sum;
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
int main()
{
	int n, x, m, ind, sum, heap[100002], s = 0;
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> x;
		heap[i] = x;
		if (i > 1) {
			if (heap[i] >= heap[i / 2]) {
				swap(heap[i], heap[i / 2]);
			}
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> ind >> sum;
		ind = sift_up(heap, ind, sum);
		cout << ind << "\n";
	}
	for (int i = 1; i < n + 1; i++) {
		cout << heap[i] << " ";
	}
}