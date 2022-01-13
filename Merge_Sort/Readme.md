# Merge Sort (병합정렬)
>1st Writter : MallangMallang
><br> 2st Writter : Mammon

## 합병 정렬(Merge sort)알고리즘이란?
~~~
* 배열의 모든 숫자를 계속 나눈 뒤 병합하는 분할정복 알고리즘
* 존 폰 노이만(John von Neumann)이라는 사람이 제안한 방법
* 일반적인 방법으로 구현했을 때 이 정렬은 안정 정렬에 속하며, 분할 정복 알고리즘의 하나이다.
    * 분할 정복(divide and conquer)방법
        *문제를 작은 2개의 문제로 분리하고 각각을 해결한 다음, 결과를 모아서 원래의 문제를 해결하는 전략이다.
        * 분할 정복 방법은 대개 순환 호출을 이용하여 구현한다.
~~~

## 분할정복법
~~~
* 분할 : 해결하고자 하는 문제를 작은 크기의 동일한 문제들로 분할
* 정복 : 각각의 작은 문제를 순환적으로 해결
* 합병 : 작은 문제의 해를 합하여(merge) 원래 문제에 대한 해를 구함
~~~
## 분할과 정복 합병
![screenshot](./img/divide.png)

<br> 분할은 문제를 부분문제로 나누는 일이고 정복은 이 부분문제들을 부분문제의 해결법으로 정복하는것이고
마지막으로 조합은 즉 합병은 이 부분문제의 해결법을 최종 문제해결법으로 만드는 알고리즘이다.

## 합병 정렬(merge sort)알고리즘의 구체적인 개념과 과정
~~~
* 하나의 리스트를 두 개의 균등한 크기로 분할하고 분할된 부분 리스트를 정렬한 다음, 
  두개의 정렬된 부분 리스트를 합하여 전체가 정렬된 리스트가 되게 하는 방법이다.
* 합병 정렬의 과정
    * 초기 상태에 정렬되지 않은 리스트가 주어집니다.
    * 이 전체 리스트를, 두 개의 리스트가 되도록 분할합니다.
    * 그 다음, 분할한 부분 리스트를 정렬합니다.
    * 정렬된 부분 리스트들을 하나의 리스트에 병합(merge)합니다. 
~~~

## 합병정렬(merge sort)알고리즘의 특징
~~~
* 단점
    * 만약 레코드를 배열(Array)로 구성하면, 임시 배열이 필요하다.
        * 제자리 정렬(in-place sorting)이 아니다.
    * 레코드들의 크기가 큰 경우에는 이동 횟수가 많으므로 매우 큰 시간적 낭비를 초래한다.
    
* 장점
    * 안정적인 정렬 방법
        * 데이터의 분포에 영향을 덜 받는다. 즉, 
          입력 데이터가 무엇이든 간에 정렬되는 시간은 동일하다. (O(nlog₂n)로 동일)
    * 만약 레코드를 연결 리스트(Linked List)로 구성하면, 
      링크 인덱스만 변경되므로 데이터의 이동은 무시할 수 있을 정도로 작아진다.
        * 제자리 정렬(in-place sorting)로 구현할 수 있다.
    * 크기가 큰 레코드를 정렬할 경우에 연결 리스트를 사용한다면, 
      합병 정렬은 퀵 정렬을 포함한 다른 어떤 졍렬 방법보다 효율적이다.
~~~

## 합병 정렬(merge sort)알고리즘의 예제
~~~
* 배열에 8,2,6,4,7,3,9,5가 저장되어 있다고 가정하고 자료를 오름차순으로 정렬해 보자.
* 2개의 정렬된 리스트를 합병(merge)하는 과정
    1. 2개의 리스트의 값들을 처음부터 하나씩 비교하여 두 개의 리스트의 값 중에서 더 작은 값을
       새로운 리스트(sorted)로 옮긴다.
    2. 둘 중에서 하나가 끝날 때까지 이과정을 되풀이한다.
    3. 만약 둘중에서 하나의 리스트가 먼저 끝나게 되면 나머지 리스트의 값들을 전부 새로운 리스트(sorted)로 복사한다.
    4. 새로운 리스트(sorted)를 원래의 리스트(list)로 옮긴다.
~~~

![screenshot](./img/img1.png)
![screenshot](./img/img2.png)

## 합병 정렬 C언어 코드
```C
# include <stdio.h>
# define MAX_SIZE 8
int sorted[MAX_SIZE]; // 추가적인 공간이 필요

// i: 정렬된 왼쪽 리스트에 대한 인덱스
// j: 정렬된 오른쪽 리스트에 대한 인덱스
// k: 정렬될 리스트에 대한 인덱스
/* 2개의 인접한 배열 list[left...mid]와 list[mid+1...right]의 합병 과정 */
/* (실제로 숫자들이 정렬되는 과정) */
void merge(int list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    /* 분할 정렬된 list의 합병 */
    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    // 남아 있는 값들을 일괄 복사
    if (i > mid) {
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    }
    // 남아 있는 값들을 일괄 복사
    else {
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];
    }

    // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
    for (l = left; l <= right; l++) {
        list[l] = sorted[l];
    }
}

// 합병 정렬
void merge_sort(int list[], int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2;// 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide);;
       merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
        merge_sort(list, mid + 1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
        merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
    }
}

void main() {
    int i;
    
    int list[MAX_SIZE] = { 21, 10, 12, 20, 25, 13, 15, 22 };

    // 합병 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 7)
    merge_sort(list, 0, MAX_SIZE - 1);

    // 정렬 결과 출력
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", list[i]);
    }
}
```
<br>

## 시간복잡도

 |평균|최선|최악|
 |:---: | :---: | :---: |  
 | O(N logN) | O(N logN) | O(N logN) |

 ![screenshot](./img/img3.png)

<br>

>출처<br>
>https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=ndb796&logNo=221227934987
>https://hazung.tistory.com/194?category=835202<br>
>https://gmlwjd9405.github.io/2018/05/08/algorithm-merge-sort.html<br>
>https://chanhuiseok.github.io/posts/algo-48/
>https://namu.wiki/w/%EB%B6%84%ED%95%A0%20%EC%A0%95%EB%B3%B5%20%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98?from=%EB%B6%84%ED%95%A0%20%EC%A0%95%EB%B3%B5
