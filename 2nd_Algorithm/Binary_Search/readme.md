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

![binary-and-linear-search-animations.gif](2nd_Algorithm/Binary_Search/binary-and-linear-search-animations.gif)

길어지는 시간과 다음 작성자를 위해 이진탐색트리는 남겨두도록 하겠습니다! 이진 탐색 트리에 대하여 설명 해주셨으면 합니다!

### 출처

[https://www.khanacademy.org/computing/computer-science/algorithms/binary-search/a/binary-search](https://www.khanacademy.org/computing/computer-science/algorithms/binary-search/a/binary-search)

[https://ko.wikipedia.org/wiki/이진_검색_알고리즘](https://ko.wikipedia.org/wiki/%EC%9D%B4%EC%A7%84_%EA%B2%80%EC%83%89_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)

[https://namu.wiki/w/이진 탐색](https://namu.wiki/w/%EC%9D%B4%EC%A7%84%20%ED%83%90%EC%83%89)

[https://yoongrammer.tistory.com/75#시간_복잡도(Time_complexity)](https://yoongrammer.tistory.com/75#%EC%8B%9C%EA%B0%84_%EB%B3%B5%EC%9E%A1%EB%8F%84(Time_complexity))

[https://velog.io/@dhwlddjgmanf/이분-탐색](https://velog.io/@dhwlddjgmanf/%EC%9D%B4%EB%B6%84-%ED%83%90%EC%83%89)

[https://www.khanacademy.org/computing/computer-science/algorithms/intro-to-algorithms/a/a-guessing-game](https://www.khanacademy.org/computing/computer-science/algorithms/intro-to-algorithms/a/a-guessing-game)
