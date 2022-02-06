# 1543 문서 검색 (실버 4)
![image](https://user-images.githubusercontent.com/65306839/152671830-173c86c8-7f38-4f81-abd9-1b4b73011078.png)

### 풀이 과정
1. 첫째 줄에 문서, 둘째 줄에 찾을 워드라면 워드의 길이 만큼 문서를 잘라 비교
2. 비교해서 찾은 경우 셈을 함

※ 주의 : 같지 않은 경우, 인덱스 1만 증가

### 코드 순서 (with Pseudo-code)
doc, word, count, index 할당  
반복하는데, word와 word길이 만큼 자른 doc이 같으면 count  
이후 count 출력  
```
GET doc, word
SET count = 1, index = 0
WHILE index <= doc's Length - word's Length
  IF doc[index:index + word's Length] == word
    INCREMENT 1 count
    INCREMENT word's Length index
  ELSE
    INCREMENT 1 index
PRINT count
```

### 코드 (Code)
```py
# Input Value
doc = input()
word = input()

# Init Value (Count, Index)
count = 0
index = 0

while index <= len(doc) - len(word):
    if doc[index:index + len(word)] == word:
        count += 1
        # Add Index (word Length)
        index += len(word)
    else:
        index += 1
print(count)
```


# 7569 토마토 (골드 5)
![image](https://user-images.githubusercontent.com/65306839/152678171-f537d222-3f9a-4326-9f9e-a704ddf2e4e1.png)

### 풀이 과정
1. 토마토가 익는 것은 주변에 익은 토마토에 의해서 이루어짐 >> 따라서 모든 토마토가 익을 때 까지 걸리는 시간을 출력하는 문제
2. 전형적인 BFS 문제

※ 주의 : 3차원 리스트로 구성되기에 인덱싱 조심

### 코드 순서 (with Pseudo-code)
BFS 함수 선언  
M, N, H 입력 >> M * N 상자 H개  
arr 입력 >> 하나의 상자에 담긴 토마토의 정보  
1 : 익음 0 : 안익음 -1 : 없음  
반복문 사용을 위한 데크(Deque : 양방향 큐)를 사용  

Start_Point 메서드를 활용하여 처음 익은 토마토 위치 확인 >> Next_Queue의 첫 좌표  
-> 최초 기록일 (0일차)에 익은 토마토 저장  
각 지점별로 BFS를 통해 count 증가  
이전날의 Next_Queue를 Today로 복사하여 오늘 할당량 대비  
오늘 할당량에서 하나씩 꺼내어 탐색  
익지 않은 토마토의 상태를 변경하여 위 과정 반복  

시간 문제로 인하여 PyPy3로 해결  

### 코드
```py
from collections import deque
import copy

m, n, h = map(int, input().split())
graph = [[] for _ in range(h)]

dx = [0,0,0,0,1,-1]
dy = [0,0,1,-1,0,0]
dz = [1,-1,0,0,0,0]

next_queue = deque()
count = 0
flag = 0

for i in range(h):
    for j in range(n):
        graph[i].append(list(map(int, input().split())))

def Start_Point():
    for i in range(h):
        for j in range(n):
            for k in range(m):
                if graph[i][j][k] == 1:
                    next_queue.append((i, j, k))

def bfs():
    global count
    today = copy.deepcopy(next_queue)

    while today:
        x, y, z = today.popleft()
        next_queue.popleft()
        for i in range(6):
            nx = x + dx[i]
            ny = y + dy[i]
            nz = z + dz[i]
            if nx < 0 or nx >= h or ny < 0 or ny >= n or nz < 0 or nz >= m:
                continue
            if graph[nx][ny][nz] == 0:
                graph[nx][ny][nz] = 1
                next_queue.append((nx, ny, nz))
    count += 1


Start_Point()
while next_queue:
    bfs()

for i in range(h):
    for j in range(n):
        if 0 in graph[i][j]:
            flag = 1

if flag == 1:
    print(-1)
else:
    print(count-1)
```
