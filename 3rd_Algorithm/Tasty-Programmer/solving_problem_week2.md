![image](https://user-images.githubusercontent.com/47372381/154297300-73d19097-8fcb-4765-b4eb-df37c67e175b.PNG)

### 풀이 과정 
LCA 알고리즘의 문제입니다. 

보통 LCA 문제들은 조상을 찾는 트리구조 들이 주어지거나 비슷한 그림들로 설명하는 문제들이 많으니 어떠한 방식으로 접근해야 하는지는 설명하지 않도록 하겠습니다.

각 노드의 부모 노드를 저장한뒤
공통 조상을 구하려는 두 노드를 따로 저장하여 두 노드의 부모 노드들을 찾습니다. 그런뒤 부모노드들을 레벨별로 비교하여 마지막에 같았던 부모노드를 구합니다.
제일 마지막에 같았던 부모 노드가 가장 가까운 공통 조상 노드가 됍니다.



```py
import sys

t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())
    parent = [0] * (n + 1) # parent's node

    # parent's node save
    for _ in range(n - 1):
        a, b = map(int, sys.stdin.readline().split())
        parent[b] = a

    # solving node save
    a, b = map(int, sys.stdin.readline().split())
    target_a = [a]
    target_b = [b]

    # solving parent's node save
    while parent[a]:
        target_a.append(parent[a])
        a = parent[a]

    while parent[b]:
        target_b.append(parent[b])
        b = parent[b]

     
    #finding root node 
    target_a_level = len(target_a) - 1
    target_b_level = len(target_b) - 1

    # finding Common Ancestor
    # 두 노드의 차이가 발생할떄까지 반복
    while target_a[target_a_level] == target_b[target_b_level]:
        target_a_level -= 1
        target_b_level -= 1

    # Common Ancestor in previous level
    print(target_a[target_a_level + 1])
```
![image](https://user-images.githubusercontent.com/47372381/154297508-64b616f8-f5a6-4f85-be43-a6b08b53a342.PNG)

### 풀이 과정
한수에 대한 이해가 필요한 문제입니다. 
어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. 쉽게 말해 숫자 하나나를 떼서 봤을때 등차수열이 이루어지면 된다고 생각하시면 됍니다.
1의 자리는 당연히 등차수열이고 10 ~ 99 또한 가능하니 110 아래에선 99개의 한수를 발견할 수 있습니다.
아래는 코드입니다.



```py
def hansu(num) :
    hansu_cnt = 0
    for i in range(1, num+1):
        num_list = list(map(int,str(i)))
        if i < 100:
            hansu_cnt += 1  # 100보다 작으면 모두 한수
        elif num_list[0]-num_list[1] == num_list[1]-num_list[2]:
            hansu_cnt += 1  # x의 각 자리가 등차수열이면 한수
    return hansu_cnt

num = int(input())
print(hansu(num))
```
