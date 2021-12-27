// MIT License
// Copyright (c) 2021 DaelimCollege_JumpStudy


#include <stdio.h>
#define max 30

void counting_sort(int* arr, int size) {

	int count[max];
	// Create Count Value
	for (int i = 0; i < max; i++) {
		count[i] = 0;
	}

	// Count Element
	for (int i = 0; i < size; i++) {
		int val = arr[i];
		count[val]++;
	}

	// Print Sorted Array
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < count[i]; j++) {
			printf("%d ", i);
		}
	}
}

int main() {

	int arr[] = { 1, 3, 0, 4, 5, 6, 3, 2, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);

	counting_sort(arr, size);

	return 0;
}
