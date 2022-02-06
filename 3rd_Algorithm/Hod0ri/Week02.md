# 11402 이항계수 4 (플래티넘 5)
![image](https://user-images.githubusercontent.com/65306839/152678599-d25c151c-06ff-4575-a9c1-9ba60a1ec056.png)
### 풀이 과정
1. N과 K에 대해 이항 계수 nCk로 나눈 나머지를 구하는 문제
2. 음이 아닌 정수 n, k에 대해 위 나머지를 구하는 것은 뤼카 정리의 내용

### 뤼카 정리 (Lucas Theorem)
--
음이 아닌 정수 n, k 그리고 소수 p에 대하여, n과 k를 p진법 전개식으로 나타내었을때,  
![54bdc01ea5e65417c55a1d7550cf9fcf970b611d](https://user-images.githubusercontent.com/65306839/152678747-2e2ddd1c-1929-46b7-a086-89e22b6e5a80.svg)
###### 사진 : 위키 피디아
위 합동식이 성립한다.

### 코드 설계
1. 리스트를 2개 생성하여 n과 k에 대한 전개식을 저장한다.
2. 이항 계수의 값을 구해주는 함수 생성
3. xCr에서 x < r인 경우를 0으로 처리
4. 부분 이항 계수들을 모두 곱한 후 나머지 연산을 적용

```py
def calcCombination(x, r):
    a = 1
    # 3번 리스트 예외 처리
    if (x < r):
        return 0
    elif (x == r):
        return 1
    for i in range(1, r + 1):
        a *= (x - i + 1)
        a //= i
    return a

n, k, m = map(int, input().split())

# nj, kj를 저장할 리스트
nl = []
kl = []
cnt = 0

# 전개식
while (n != 0 or k != 0):
    nl.append(n % m)
    kl.append(k % m)
    n //= m;
    k //= m
ans = 1

# 합동식
for i in range(len(nl)):
    ans *= calcCombination(nl[i], kl[i])
    ans %= m

print(ans)
```
