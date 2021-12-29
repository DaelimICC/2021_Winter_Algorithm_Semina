#include <iostream>

using namespace std;

void Counting_sort(int* arr, int size)
{
	// Creat Sorted Array and Counting Array
	// Dynamic Array
	int* counting, * sorted;
	int maxNum = 0;

	// Find Max Number to create Counting Array
	for (int index = 0; index < size; index++) if (arr[index] > maxNum) maxNum = arr[index];

	// Create Counting Array size of MaxNuM + 1 (because Zero-Start)
	counting = new int[maxNum + 1]{ 0 };

	// Create Sorted Array
	sorted = new int[size] {0};

    // Counting Element
	for (int index = 0; index < size; index++) counting[arr[index]]++;

	// Cumulative Sum
	for (int index = 1; index <= maxNum; i++) counting[i] += counting[index - 1];
	
	// Sorting
	for (int index = 0; index < size; index++)
	{
		sorted[counting[arr[index]] - 1] = arr[index];
		counting[arr[index]]--;
	}
	for (int index = 0; index < size; index++) arr[index] = sorted[index];

	// Clear Dynamic
	delete[] counting;
	delete[] sorted;
}

int main(void)
{
	// Testing Value
	int arr[10] = { 5, 9, 8, 3, 5, 4, 6, 12, 2, 4 };

	// Print Pre-Sort List Values
	for (int index = 0; index < 10; index++) cout << arr[index] << " ";
	cout << '\n';

	Counting_sort(arr, 10);

	// Print Post-Sort List Values
	for (int index = 0; index < 10; index++) cout << arr[index] << " ";
	cout << '\n';

	return 0;
}
