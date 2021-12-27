#include <iostream>

using namespace std;

void Counting_sort(int* arr, int size)
{
	// Creat Sorted Array and Counting Array
	// Dynamic Array
	int* counting, * sorted;
	int maxNum = 0;

	// Find Max Number to create Counting Array
	for (int i = 0; i < size; i++) if (arr[i] > maxNum) maxNum = arr[i];

	// Create Counting Array size of MaxNuM + 1 (because Zero-Start)
	counting = new int[maxNum + 1]{ 0 };

	// Create Sorted Array
	sorted = new int[size] {0};

    // Counting Element
	for (int i = 0; i < size; i++) counting[arr[i]]++;

	// Cumulative Sum
	for (int i = 1; i <= maxNum; i++) counting[i] += counting[i - 1];
	
	// Sorting
	for (int i = 0; i < size; i++)
	{
		sorted[counting[arr[i]] - 1] = arr[i];
		counting[arr[i]]--;
	}
	for (int i = 0; i < size; i++) arr[i] = sorted[i];

	// Clear Dynamic
	delete[] counting;
	delete[] sorted;
}

int main(void)
{
	// Testing Value
	int arr[10] = { 5, 9, 8, 3, 5, 4, 6, 12, 2, 4 };

	// Print Pre-Sort List Values
	for (int i = 0; i < 10; i++) cout << arr[i] << " ";
	cout << '\n';

	Counting_sort(arr, 10);

	// Print Post-Sort List Values
	for (int i = 0; i < 10; i++) cout << arr[i] << " ";
	cout << '\n';

	return 0;
}