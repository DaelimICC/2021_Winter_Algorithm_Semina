# Code Review C++

### Main Function
```cpp
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
```

메인함수는 다음과 같이 테스트 할 배열을 선언하고, 비교를 위해 섞인 배열을 출력한다.  
다음, Counting_sort()메서드를 활용해 계수 정렬을 하고, 정렬된 배열을 출력한다.  

### Step 01 : Initialize Variable
```cpp
void Counting_sort(int* arr, int size)
```
Counting_sort()메서드는 배열의 주소값과 사이즈를 받아온다. 

```cpp
// Creat Sorted Array and Counting Array
// Dynamic Array
int* counting, * sorted;
int maxNum = 0;
```
다음, 정렬에 필요한, 원소들을 셀 Counting 배열, 정렬 된 이후의 배열을 저장항 Sorted 배열을 동적 배열로 생성한다.  
또한, Counting 배열의 사이즈를 위해 최대값을 저장할 maxNum 변수를 선언한다.  

```cpp
// Find Max Number to create Counting Array
for (int index = 0; index < size; index++) if (arr[index] > maxNum) maxNum = arr[index];

// Create Counting Array size of MaxNuM + 1 (because Zero-Start)
counting = new int[maxNum + 1]{ 0 };

// Create Sorted Array
sorted = new int[size] {0};
```

우선, 간단하게 maxNum에 배열의 최대값에 해당하는 원소를 할당하고, 그 최대값 + 1만큼 Counting 배열을 생성한다.  
1을 더하는 이유는 0 Index 배열이기에, 1을 더해주어야 인덱스가 곧 원소 값이 되기 때문이다.  
<br/>
마무리로, sorted 배열도 원본 배열하고 같은 길이만큼 생성한다.

```cpp
// Counting Element
for (int index = 0; index < size; index++) counting[arr[index]]++;

// Cumulative Sum
for (int index = 1; i <= maxNum; index++) counting[index] += counting[index - 1];
```
다음, 각 원소의 개수를 세주면 된다.  
각 원소를 센 다음, 각 원소의 누적합을 연산해준다.  
누적합을 통해 정렬하기 위함이다.  

```cpp
// Sorting
for (int index = 0; index < size; index++)
{
	sorted[counting[arr[index]] - 1] = arr[index];
	counting[arr[index]]--;
}
for (int index = 0; index < size; index++) arr[index] = sorted[index];
```
다음, 누적합 배열을 통해 정렬된 배열을 도출해내면 정렬은 끝나며, 동적 배열을 마무리로 아래와 같이 해제해주면 된다.  
```cpp
// Clear Dynamic
delete[] counting;
delete[] sorted;
```
