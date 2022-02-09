![image](https://user-images.githubusercontent.com/47372381/153209811-517be164-dffe-42ed-aa89-b5bc801e9847.PNG)

### 풀이과정 

2번째 챕터에서도 했고 설명도 했다시피 가장 긴 증가 수열 문제 즉 LIS 문제의 풀이방법에서는 두가지 풀이방법을 제시 할수있다.
첫번째 방식은 DP를 통해,
두번째 방식은 이분 탐색을 통해 해결할수있다. 
이 문제에서는 dp방식으로 먼저 해결해보려 시도하였으나 숫자의 갯수가 최대 1,000,000개까지의 범위를 서치해야하므로 dp방식으로 푼다면 시간문제로 해결하기가 복잡해진다. 그리하여 이분탐색을 이용하여 해결하는것이 더 쉬운방식이라고 생각되었다. 

항상 LIS 문제를 보면 DP 혹은 이분탐색 방식을 적용하여 풀어보는것이 정답인것같다.
이 문제를 풀면서 느낀점은 긴 범위의 탐색을 요하는 문제에서는 이분탐색을 활용하는것이 더 좋은 접근방식이었다는 것을 깨달을수 있었다. 

array는 수열 A를 뜻하고 A에 수열의 모든 원소들을 저장한다.
stack 부분은 정답을 가리킨다.

for 부분에서 현재 원소가 stack의 마지막 원소보다 크다면 수열을 연장해야 하는 상황이 생기는데 그때 stack에 마지막에 추가하는데 전에 마지막 원소는 버려져야할까? 그렇지 않다.
그래서 else 부분에 stack[binary_search(i, 0, len(stack) - 1)] = i 라는 조건을 준것입니다.


### 코드

```
n = int(input())
array = list(map(int, input().split()))
stack = [0]


def binary_search(target, start, end):
    while start <= end:
        mid = (start + end) // 2

        if stack[mid] < target:
            start = mid + 1
        else:
            end = mid - 1
    return start


for i in array:
    if stack[-1] < i:
        stack.append(i)
    else:
        stack[binary_search(i, 0, len(stack) - 1)] = i

print(len(stack) - 1)
```

![image](https://user-images.githubusercontent.com/47372381/153210002-536850b4-0230-4369-938f-d5d7039d65b7.PNG)

### 풀이 과정
위에서 설명 했던 방식에 따라 LIS 문제를 또 하나 풀이하였다. DP인지 이분탐색인지 먼저 생각해보자 위의 문제를 풀고나서 깨달았던점을 생각해보면 긴범위의 탐색이 필요한것같진 않았다. 그러므로 DP방식으로 접근해보도록 하자 
범위가 아까에 비해 적은 1000까지의 탐색이니 DP를 활용해야 한다는것을 알수있다. 그리하여 코드에서 dp 방식으로 접근하였다.

비교적 위의 문제보다 쉬운편이다. 

### 코드
증가하는 최대 수열이 되는 원소부터 길이를 1씩 감소시키면서 증가하는 순열의 값을 찾는다.


```
x = int(input())
arr = list(map(int, input().split()))

dp = [1 for i in range(x)]

for i in range(x):
    for j in range(i):
        if arr[i] > arr[j]:
            dp[i] = max(dp[i], dp[j] + 1)

max_dp = max(dp)
print(max_dp)

max_idx = dp.index(max_dp)
lis = []

while max_idx >= 0:
    if dp[max_idx] == max_dp:
        lis.append(arr[max_idx])
        max_dp -= 1
    max_idx -= 1

lis.reverse()
print(*lis)
```



![image](https://user-images.githubusercontent.com/47372381/153210108-ddec3eec-7f02-484a-94c8-19cc3dad6aa0.PNG)

### 풀이과정

위에서 너무 어려운 문제들을 다룬것같아서 나름? 쉬운문제를 가져와 보았다.

그냥 간단한 수학문제라고 보시면 됀다. while문의 수정사항을 받고 이슈를 걸어주었으면 합니다 ㅎㅎ.

```
sugar = int(input())

bag = 0
while sugar>=0:
    if sugar % 5 ==0:
        bag+=(sugar//5)
        print(bag)
        break
    sugar -=3
    bag+=1
else:
    print(-1)
```
