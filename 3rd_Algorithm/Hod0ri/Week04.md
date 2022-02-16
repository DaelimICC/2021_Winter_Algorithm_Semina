![image](https://user-images.githubusercontent.com/65306839/154273127-50ac2bfd-d21e-4e79-9358-2894f6afaa79.png)
```py
# 인수 분해 했을때, 0이 늘어나는 순간은 10이 곱해져야 0의 개수가 늘어남
N = int(input())
print(N//5 + N//25 + N//125)
```

![image](https://user-images.githubusercontent.com/65306839/154274324-7a61a22e-5ae3-4c53-9e30-65c2a3b6c95b.png)
### 풀이 과정
1. 정수형의 리스트를 문자열 리스트로 치환
2. 정렬!
3. 1000이하의 수이기 때문에, 문자열을 3번씩 반복하여 3자리수로 맞추어 비교
4. 문자열 비교는 ASCII 값으로 치환 (문제 없음)

```py
def solution(numbers):
    numbers = list(map(str, numbers))
    numbers.sort(key=lambda x: x * 3, reverse=True)
    return str(int(''.join(numbers)))
```
