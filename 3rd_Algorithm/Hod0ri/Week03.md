# 체육복 (프로그래머스)
![image](https://user-images.githubusercontent.com/65306839/153964315-e2742d31-7cc9-4c80-860f-04512c349458.png)

### 풀이 과정

##### 핵심 키워드
- 중복이 없다  
  도난 당한 학생들의 번호와 여벌의 체육복을 가져온 학생들의 번호에는 중복이 없다.
  ```py
  lost = [1, 12, 55, 55, 58]
  reserve = [14, 22, 57, 22]
  ```
  위와 같은 상황이 없다는 이야기
- 여벌의 체육복이 있는 학생도 도난 당했을 수 있다.  
  도난 당한 학생들과 여벌의 체육복을 가져온 학생들 두 배열 간에는 공통 원소가 있다.
  ```py
  lost = [1, 12, 55, 58]
  reserve = [12, 14, 55, 58]
  ```
  위 상황이 가능하다는 이야기이다.
  
중복되지 않아야 하기에, Set 자료형을 사용한다.
또한 Reserve와 Lost 사이에 공통 원소가 존재하기에 두 값을 전처리를 하여야 한다.
 
```py
# Preprocessing Array
temp_reserve = set(reserve)-set(lost)
temp_lost = set(lost)-set(reserve)
```
 
문제에 아래와 같은 내용이 있기에, 탐욕 알고리즘을 사용하여야 한다.
```text
학생들의 번호는 체격 순으로 매겨져 있어, 바로 앞번호의 학생이나 바로 뒷번호의 학생에게만 체육복을 빌려줄 수 있습니다.
```

학생을 일렬로 나열했다고 가정했을때, 만일에 특정 번호의 양 옆에 학생이 체육복이 없다면 누구에게 우선적으로 빌려야하는지를 추상해내면 아래와 같이 서술된다.
```text
[17] (18) [19] (20) [21] (22) [23]
대괄호로 묶인 사람이 여분의 체육복을, 소괄호로 묶인 사람이 도난 당한 학생이라고 가정하자,
이때, 각 사람들이 오른쪽 학생을 우선적으로 주게 되는 경우 18번 학생이 체육을 참여하지 못한다.
따라서 왼쪽 우선으로 지급하는 경우, 모든 학생이 체육활동에 참여가 가능하다.
```

### 코드
```py
def solution(n, lost, reserve):
  # Preprocessing Array
  temp_reserve = set(reserve)-set(lost)
  temp_lost = set(lost)-set(reserve)
  
  # Search
  for value in temp_reserve:
      # Check Left Student
      if value-1 in temp_lost:
          temp_lost.remove(value-1)
      # Check Right Student
      elif value+1 in temp_lost:
          temp_lost.remove(value+1)
  return n-len(temp_lost)
```

### 결과
![image](https://user-images.githubusercontent.com/65306839/153965907-aa45a886-9411-44da-84d0-4f5e39e2a55c.png)
