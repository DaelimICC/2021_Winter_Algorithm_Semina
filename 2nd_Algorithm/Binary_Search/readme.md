# Binary_Search

먼저 이진 검색 알고리즘은 오름차순으로 정렬된 리스트에서 특정한 값의 위치를 찾는 알고리즘이다.

## 방법에 대하여..

이진 검색 알고리즘의 방식은 기본적으로 비교하는 방식을 채택하고있는데, 처음에 중간의 값을 임의의 값으로 선택한뒤 찾는값과 비교후 크면 임의의 값이 새로운 최대값으로 작다면 새로운 최솟값이 되는 형태를 이루고 있다.

원리상으로 정렬된 리스트에서만 사용이 가능하다는 점이있지만 , 검색이 반복될수록 목표값을 찾을 확률이 두배로 증가하므로 속도가 빠른 검색 알고리즘이라고 할 수 있다.

## 예를 들면?

예를 들어 당신이 1부터 300까지 정수로 이루어진 리스트를 가지고있다 할때 찾으려는 값을 찾기 위해서는 최소 9번의 비교만으로 찾을 수 있을것이다. 

이것은 이진 검색 알고리즘의 특성을 활용해서 나온 기대값입니다. 

## 의사 코드

```
function 이진탐색(데이터, 찾는 값)

데이터가 혹시 비어 있는가?
(네) return 찾는 값 없음.

데이터의 가운데 지점을 찾는다.
찾은 지점의 값을 뽑는다.
뽑은 값이 찾는 값인가?

(네) return 뽑은 값.
(아니요)
  뽑은 값과 찾는 값을 비교한다.
  (뽑은 값이 찾는 값보다 큰 값인가?)
    return 이진탐색(데이터 앞쪽 절반, 찾는 값)
  (작은 값인가?)
    return 이진탐색(데이터 뒤쪽 절반, 찾는 값)
```

## 시간복잡도

좋은 컨디션에서는 O(1)
평균 컨디션에서는 O(log N)

나쁜 컨디션에서는 O(log N)

N = 데이터의 수를 일컫는다.

## 계산을 통한 중간값을 구하는 방식

mid = low + (high - low) / 2

mid = (low+high)/2

두가지의 경우가 있지만 보통 2번째 방식이 채택되어집니다. 그러나 low + high 의 값이 범위를 넘어서는 경우에선 첫번째 방식을 채택해야 합니다.

## 종료 조건에 대하여.

이진 탐색의 종료 조건은 보통 두가지로 생각 되어지는데 둘중 하나의 조건을 성립한다면 검색을 종료 합니다.

1. 검색을 성공할경우
이 경우에서는 리스트에서 검색할 값과 같은 요소를 발견한 경우 성립되어 집니다.
2. 검색을 실패한 경우
이 경우에서는 리스트에서 더이상 검색할 범위가 없을 경우 성립되어 집니다.

## 장단점

장점

탐색 과정에서 봤던 것처럼 순차 탐색에 비해서 월등한 성능을 자랑합니다.

구현하기에 부담이 없습니다.

단점

반드시 정렬된 리스트를 필요로 하는 알고리즘 입니다.

![binary-and-linear-search-animations.gif](https://user-images.githubusercontent.com/47372381/150161771-35680c05-1816-4442-90e7-97dc45344f27.gif)

길어지는 시간과 다음 작성자를 위해 이진탐색트리는 남겨두도록 하겠습니다! 이진 탐색 트리에 대하여 설명 해주셨으면 합니다!
## 이진탐색 문제 예시
백준 문제 1920
N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다.

출력
M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.

예제 입력 
5
4 1 5 2 3
5
1 3 7 9 5


예제 출력  
1
1
0
0
1


### 문제 해결 코드
~~~C
#include <stdio.h>
int arr[100000];
void quickSort(int arr[], int left, int right)
{
    int l = left, r = right;
    int temp;
    int pivot = arr[(left + right) / 2];

    while (l <= r)
    {
        while (arr[l] < pivot)
            l++;
        while (arr[r] > pivot)
            r--;

        if (l <= r)
        {
            if (l != r)
            {
                temp = arr[l];
                arr[l] = arr[r];
                arr[r] = temp;
            }
            l++; r--;
        }
    }
    if (l < right)
        quickSort(arr, l, right);
    if (r > left)
        quickSort(arr, left, r);
}
void found(int n, int result) {
    int st = 0, end = n - 1;
    int pivot;

    while (st <= end) {
        pivot = (st + end) / 2;

        if (arr[pivot] == result) {
            return printf("1 \n");
        }
        else if (arr[pivot] > result) {
            end = pivot - 1;
        }
        else {
            st = pivot + 1;
        }
    }
    printf("0 \n");
    return;
}
int main() {
    int num,qus,find;
    scanf_s("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf_s("%d", &arr[i]);
    }
    quickSort(arr, 0, num - 1);
    scanf_s("%d", &qus);
    for (int i = 0; i < qus; i++) {
        scanf_s("%d", &find);
        found(num, find);
    }
    return 0;
}
~~~

문제는 간단하게 n개의 숫자를 나열해서 m개의 숫자를 또 나열했을때 만약 m개의 숫자를 나열한것이 n개안에 있으면 1로 표시하고 아니면 0으로 표시하는 문제

개인적인 생각으로는 굳이 이분탐색을 사용하지 않아도 해결할 수 있을것 같다고 생각했지만 이분 탐색 카테고리에 들어가 있어서 이분탐색을 사용하려고 노력했다.

먼저 n개의 데이터를 넣고 n개 안에 넣은 데이터를 m개 안에 넣은 데이터와 비교하기 위해 먼저 1주차에 배운 퀵정렬을 사용하여 나열하고 그 후 m 안에 넣은
데이터들을 이분탐색하여 존재하는지를 비교하였다.

## 이진검색트리
이진탐색트리란 이진탐색과 연결리스트를 결합한 자료구조의 일종이고 이진탐색의 효율적인 탐새 능력을 유지하면서도,빈번한 자료 입력과 삭제를 가능하게끔 고안되었다.

추상적으로 나타내면 다음 그림과 같다.
<img src= "https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbCe3QD%2Fbtq2ytHuN1Z%2FAi82KHYBlgY01j9hbwjOO1%2Fimg.png" width="800" height="500"/>

* 각 노드의 왼족 서브트리에는 해당 노드의 값보다 작은 값을 지닌 노드들로 이루어져 있다.
* 각 노드의 오른쪽 서브트리에는 해당 노드의 값보다 큰 값을 지닌 노드들로 이루어져 있다.
* 중복된 노드가 없어야한다.
* 왼쪽 서브트리, 오른쪽 서브트리 또한 이진탐색이다.

배열로 표현하여 이진탐색트리를 구현할 수 있다. 하지만 추가 삭제가 어려운 경우가 생긴다.
포인터를 사용해서도 이진트리를 사용하여 이진탐색트리를 구현할 수 있다.


### 배열에 정렬되어있는 데이터를 이진검색 트리로 구현한 코드 

~~~java
class Tree {
	class Node { 
		int data;
		Node left;
		Node right;
		Node (int data) {
			this.data = data;
		}
	}
	Node root;
	public void makeTree(int [] a) {
		root = makeTreeR(a,0,a.length-1); 
	}
	public Node makeTreeR(int[] a, int start, int end) {
		if(start > end) return null;
		int mid = (start + end) / 2; // 중간값 즉 pivot
		Node node = new Node(a[mid]);
		node.left = makeTreeR(a,start,mid-1); // 왼쪽 서브트리 범위설정 재귀함수
		node.right = makeTreeR(a,mid+1,end); // 오른쪽 서브트리 범위설정 재귀함수
		return node;
	}
	public void searchBTree(Node n , int find)
	{
		if(find < n.data) {
			System.out.println("데이터가 "+n.data+ "보다 작다");
			searchBTree(n.left,find); // 재귀함수 이용
		}
		else if(find > n.data) {
			System.out.println("데이터가 "+n.data+ "보다 더 크다 ");
			searchBTree(n.right,find); // 재귀함수로 데이터 찾기
		}
		else 
			System.out.println("찾은 데이터 = "+ n.data);
	}
}
public class BST {

	public static void main(String[] args) {
	int [] arr = {1,12,15,30,60,63,72,84,93,100}; // 배열안에 정렬되어있는 데이터

	
	Tree t = new Tree();
	t.makeTree(arr);
	t.searchBTree(t.root, 72);//72라는 데이터 찾기
	}

}
~~~

pdh = 제가 AVL 트리와 AVL 트리의 탐색까지 조사하고 싶었으나 시간이 부족한 관계로 다음분께서 AVL 트리와 탐색에 관해서 설명해주시면 감사하겠습니다.

### 출처

[https://www.khanacademy.org/computing/computer-science/algorithms/binary-search/a/binary-search](https://www.khanacademy.org/computing/computer-science/algorithms/binary-search/a/binary-search)

[https://ko.wikipedia.org/wiki/이진_검색_알고리즘](https://ko.wikipedia.org/wiki/%EC%9D%B4%EC%A7%84_%EA%B2%80%EC%83%89_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)

[https://namu.wiki/w/이진 탐색](https://namu.wiki/w/%EC%9D%B4%EC%A7%84%20%ED%83%90%EC%83%89)

[https://yoongrammer.tistory.com/75#시간_복잡도(Time_complexity)](https://yoongrammer.tistory.com/75#%EC%8B%9C%EA%B0%84_%EB%B3%B5%EC%9E%A1%EB%8F%84(Time_complexity))

[https://velog.io/@dhwlddjgmanf/이분-탐색](https://velog.io/@dhwlddjgmanf/%EC%9D%B4%EB%B6%84-%ED%83%90%EC%83%89)

[https://www.khanacademy.org/computing/computer-science/algorithms/intro-to-algorithms/a/a-guessing-game](https://www.khanacademy.org/computing/computer-science/algorithms/intro-to-algorithms/a/a-guessing-game)
