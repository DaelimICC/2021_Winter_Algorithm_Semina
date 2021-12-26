# Code Review C++

### Main Function
```cpp
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
```

메인함수는 다음과 같이 테스트 할 배열을 선언하고, 비교를 위해 섞인 배열을 출력한다.  
다음, Counting_sort()메서드를 활용해 계수 정렬을 하고, 정렬된 배열을 출력한다.  

### Step 01 : Initialize Variable
```cpp
void Counting_sort(int* arr, int size)
```
Counting_sort()메서드는 배열의 주소값과 사이즈를 받아온다.  
```

```cpp
// Creat Sorted Array and Counting Array
// Dynamic Array
int* counting, * sorted;
int maxNum = 0;
```
다음, 정렬에 필요한, 원소들을 셀 Counting 배열, 정렬 된 이후의 배열을 저장항 Sorted 배열을 동적 배열로 생성한다.  
또한, Counting 배열의 사이즈를 위해 최대값을 저장할 maxNum 변수를 선언한다.  
