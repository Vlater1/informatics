﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

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
	for (int i = 1; i < n - 1; i++) {
		int ans = heap[1];
		heap[1] = heap[count];
		ind = sift_down(heap, 1, count);
		count--;
		cout << ind << " " << ans << "\n";
	}
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
	extract_max(heap, n + 1);
}