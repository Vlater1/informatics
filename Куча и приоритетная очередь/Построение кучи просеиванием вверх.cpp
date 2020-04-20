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

int main()
{
	int n, x, m, y, ind, len = 0, heap[100002], a[100002];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n + 1; i++) {
		heap[i] = a[i - 1];
		sift_up(heap, i);
	}
	for (int i = 1; i < n + 1; i++) {
		cout << heap[i] << " ";
	}
}