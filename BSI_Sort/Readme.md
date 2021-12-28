# BSI Sort
1st Writter : NightRabbit  

## 1-1. Bubble Sort 의 정의
~~~
- 서로 인접한 두 원소의 대소를 비교하고, 조건에 맞지 않다면 자리를 교환하며 정렬하는 알고리즘 이다.
- 이름의 유래로는 정렬 과정에서 원소의 이동이 거품이 수면으로 올라오는 듯한 모습을 보이기 때문에 지어졌다고 한다.
~~~

## 1-2. Bubble Sort Java Code
```java
void bubbleSort(int[] arr) {
    int temp = 0;
	for(int i = 0; i < arr.length; i++) {       // 1.
		for(int j= 1 ; j < arr.length-i; j++) { // 2.
			if(arr[j-1] > arr[j]) {             // 3.
                // swap(arr[j-1], arr[j])
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	System.out.println(Arrays.toString(arr));
}
//출처 : https://gyoogle.dev/blog/algorithm/Bubble%20Sort.html
```
1. 제외될 원소의 갯수를 의미한다. 1회전이 끝난 후 배열의 마지막 위치에는 가장 큰<br>
   원소가 위치하기 때문에 하나씩 증가시켜준다.<br>
   
2. 원소를 비교할 index를 뽑는 반복문이다. j는 현재 원소를 가리키고, j-1은 이전 원소를<br>
   가리키게 되므로, j는 1부터 시작하게 된다.<br>
   
3. 현재 가리키고 있는 두 원소의 대소를 비교한다. 해당 코드는 오름차순 정렬이므로 현재 원소보다<br>
   이전 원소가 더 크다면 이전 원소가 뒤로 가야하므로 서로 자리를 교환해준다.   

## 1-3.  Bubble Sort 의 시간 복잡도 와 공간 복잡도
시간 복잡도를 계산하려면 우선 비교 횟수와 교환 횟수를 구해야 한다.<br>
Bubble Sort의 비교 횟수는 최상, 평균, 최악일때도 모두 일정하므로 다음과 같다.
~~~
n-1, n-2, … , 2, 1 번 = n(n-1)/2
~~~
교환 횟수는 입력 자료가 역순으로 정렬되어 있는 최악의 경우, 한 번 교환하기 위하여 3번의 이동이 필요 하므로 다음과 같다.
~~~
(비교 횟수 * 3) 번 = 3n(n-1)/2
~~~
하지만 입력 자료가 이미 정렬되어 있는 최상의 경우에는 자료의 이동이 발생하지 않는다.<br>
그러므로 시간복잡도는 다음과 같다
~~~
T(n) = O(n^2)
~~~
공간 복잡도는 주어진 배열 안에서 교환을 통해 정렬이 수행이 되므로 다음과 같다.
~~~
S(n) = O(n)
~~~

## 1-4. Bubble Sort의 장단점
<장점>
~~~
- 구현이 매우 간단하고, 소스코드가 직관적이다.
- 정렬하고자 하는 배열 안에서 교환하는 방식이므로, 다른 메모리 공간을 필요로 하지 않는다.(제자리 정렬)
- 안정 정렬(Stable Sort)이다.
~~~
<단점>
~~~
- 시간 복잡도가 최악, 최선, 평균 모두 O(n^2)으로 굉장히 비효율적이다.
- 정렬 되어있지 않은 원소가 정렬이 되었을 때의 자리로 가기 위해서 교환 연산이 많이 일어나게 된다.
~~~

## 2-1. Selection Sort의 정의
~~~
- Selection Sort는 Bubble Sort와 유사한 알고리즘으로, 해당 순서에 원소를 넣을 위치는 이미 정해져 있고
  어떤 원소를 넣을지 선택하는 알고리즘 이다.
- Selection Sort는 배열에서 해당 자리를 선택하고 그 자리에 오는 값을 찾는 것 이다.
~~~

## 2-2. Selection Sort Java Code
```java
void selectionSort(int[] arr) {
    int indexMin, temp;
    for (int i = 0; i < arr.length-1; i++) {        // 1.
        indexMin = i;
        for (int j = i + 1; j < arr.length; j++) {  // 2.
            if (arr[j] < arr[indexMin]) {           // 3.
                indexMin = j;
            }
        }
        // 4. swap(arr[indexMin], arr[i])
        temp = arr[indexMin];
        arr[indexMin] = arr[i];
        arr[i] = temp;
  }
  System.out.println(Arrays.toString(arr));
}
//출처 : https://gyoogle.dev/blog/algorithm/Selection%20Sort.html
```
1. 우선, 위치(index)룰 선택해준다.

2. i+1번째 원소부터 선택한 위치(index)의 값과 비교를 시작한다.

3. 오름차순이므로 현재 선택한 자리에 있는 값보다 순회하고 있는 값이 작다면, 위치(index)를 갱신해준다.

4. '2'번 반복문이 끝난 뒤에는 indexMin에 '1'번에서 선택한 위치(index)에 들어가야 하는 값의 위치(index)<br>
   를 갖고 있으므로 서로 교환 해준다.
   
## 2-3.  Selection Sort 의 시간 복잡도 와 공간 복잡도
시간 복잡도를 계산하려면 우선 비교 횟수와 교환 횟수를 구해야 한다.<br>
데이터의 개수가 n개라고 했을 때, 비교 횟수는 다음과 같다
~~~
두 개의 for 루프의 실행 횟수
외부 루프 : (n-1)번
내부 루프(최솟값 찾기) : n-1, n-2, ..., 2, 1 번
~~~

데이터의 개수가 n개라고 했을 때, 교환 횟수는 다음과 같다.
~~~
- 외부 루프의 실행 횟수와 동일. 즉 상수 시간 작업
- 한번 교환하기 위해 3번의 이동이 필요하므로 3(n-1)번
~~~
따라서 시간 복잡도는 다음과 같다.
~~~
T(n) = (n-1) + (n-2) + … + 2 + 1 = n(n-1)/2 = O(n^2)
~~~

## 2-4. Selection Sort의 장단점
<장점>
~~~
- 알고리즘이 단순하다
- 정렬을 위한 비교 횟수는 많지만, Bubble Sort에 비해 실제로 교환하는 횟수는 적기 때문에
  많은 교환이 일어나야 하는 자료상테에서 비교적 효율적이다.
- 정렬하고자 하는 배열 안에서 교환하는 방식이므로, 다른 메모리 공간을 필요로 하지 않는다.(제자리 정렬)
~~~

<단점>
~~~
- 시간 복잡도가 O(n^2)로 비효율적이다.
- 불안정 정렬(Unstable Sort)이다.
~~~

## 3-1. Insertion Sort의 정의
