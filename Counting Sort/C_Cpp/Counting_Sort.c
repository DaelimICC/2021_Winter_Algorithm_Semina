#include <stdio.h>
#define max 30

void counting_sort(int* arr, int size) {

	int count[max];
	// Create Count Value
	for (int index = 0; index < max; index++) {
		count[index] = 0;
	}

	// Count Element
	for (int index = 0; index < size; index++) {
		int val = arr[index];
		count[val]++;
	}

	// Print Sorted Array
	for (int index = 0; index < max; index++) {
		for (int temp = 0; temp < count[index]; temp++) {
			printf("%d ", index);
		}
	}
}

int main() {

	int arr[] = { 1, 3, 0, 4, 5, 6, 3, 2, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);

	counting_sort(arr, size);

	return 0;
}