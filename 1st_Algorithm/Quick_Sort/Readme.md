# Quick Sort
>1st Writter : Mammom
>>2nd Writter : MallangMallang
# Update List (MallangMallang)
* 퀵 정렬, 병합 정렬 차이점 Update
* 오타, 출처 Update
* 안정 정렬, 불안정 정렬 정의 Add
* GIF Update
* JAVA Quick Sort Source Code Update

## 1) 퀵정렬(quick_sort)이란?
~~~
* 찰스 앤터니 리처 호어(Charles Antony Richard Hoare)가 개발한 정렬 알고리즘
* 퀵 정렬은 합병정렬과 비슷하게 분할정복(Divide and Conquer) 알고리즘
~~~
* 퀵 정렬은 병합 정렬과 동일한 분할정복 알고리즘 이지만 병합정렬은 정확하게 절반으로 나누어 가며 분할정복을 하는데, 퀵 정렬의 경우 피벗(pivot)의 값에 따라 비균등하게 나뉜다는 차이점이 있다.
## 2) 퀵정렬(quick_sort)개념?
~~~
* 분할 정복 알고리즘의 하나로, 평균적으로 매우 빠른 수행 속도를 자랑하는 정력 방법
* 분할 정복
  - 문제를 작은 2개의 문제로 분리하고 각각을 해결한 다음, 결과를 모아서 원래의 문제를 해결하는 전략이다.
  - 분활 정복 방법은 대개 순환 호출을 이용하여 구현한다.
~~~

## 3) 퀵정렬(quick_sort) 과정?
~~~
  1) 리스트 안에 있는 한 요소를 선택한다. 이렇게 고른 원소를 피벗(pivot) 이라고 한다.
  
  2) 피벗을 기준으로 피벗보다 작은 요소들은 모두 피벗의 왼쪽으로 옮겨지고 피벗보다 큰 요소들은 모두 피벗의 오른쪽으로 옮겨진다. 
    (피벗을 중심으로 왼쪽: 피벗보다 작은 요소들, 오른쪽: 피벗보다 큰 요소들)
    
  3) 피벗을 제외한 왼쪽 리스트와 오른쪽 리스트를 다시 정렬한다.
    - 분할된 부분 리스트에 대하여 순환 호출을 이용하여 정렬을 반복한다.
    - 부분 리스트에서도 다시 피벗을 정하고 피벗을 기준으로 2개의 부분 리스트로 나누는과정을 반복한다.
    
  4) 부분 리스트들이 더 이상 분할이 불가능할 때까지 반복한다.
    - 리스트의 크기가 0이나 1이 될 때까지 반복한다. 
~~~
<img src= "https://user-images.githubusercontent.com/89181586/147576062-5d39cf08-bc59-4516-882f-8d019e985bb9.PNG" width="500" height="300"/>

## >퀵정렬 GIF
<img src= "./img/quick-sort.gif">

## 4) 퀵정렬(quick_sort) 장단점?
~~~
  * 장점
    1. 속도가 빠르다.
      - 시간 복잡도가 O(nlog₂n)를 가지는 다른 정렬 알고리즘과 비교했을 때도 가장 빠르다.
      
    2. 추가 메모리 공간을 필요로 하지 않는다.
      - 퀵 정렬은 O(nlog n)만큼의 메모리를 필요로 한다.
  
  * 단점
    1. 정렬된 리스트에 대해서는 퀵 정렬의 불균형 분할에 의해 오히려 수행시간이 더 많이 걸린다.
    2. 불안정 정렬(Unstable Sort) 이다. 
~~~
- '거품 정렬(Bubble Sort)'과 '삽입 정렬(Insertion Sort)' 그리고
      '병합 정렬(Merge Sort)'은 안정정렬인데, 세가지 정렬 알고리즘의 특징은 ```비교 대상과 값이 같을 경우 그냥 넘어간다.```는 특징이 있는데 그에 비해 '퀵 정렬(Quick Sort)'는 값이 같은 경우에도 자리를 옮길 가능성이 있기 때문에 불안정 정렬이다.

##
[퀵 정렬(quick sort)이란](https://www.geeksforgeeks.org/msd-most-significant-digit-radix-sort/)


출처 : https://gyoogle.dev/blog/algorithm/Quick%20Sort.html#%E1%84%91%E1%85%A7%E1%86%BC%E1%84%80%E1%85%B2%E1%86%AB%E1%84%8B%E1%85%B4-%E1%84%80%E1%85%A7%E1%86%BC%E1%84%8B%E1%85%AE-average-cases-t-n-o-nlog2n
