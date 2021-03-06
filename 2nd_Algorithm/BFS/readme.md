1st Writter : NightRabbit  
2st Writter : Mammom

## 그래프 탐색이란
~~~
* 하나의 정점으로 부터 시작하여 차례대로 모든 정점들을 한번씩 방문하는 것
* EX) 특정도시에서 다른 도시로 갈수 있는지 없는지, 전자 회로에서 특정단자와 단자가 서로 연결
  되어 있는지
~~~

## BFS의 정의
~~~
* BFS는 탐색을 할 때, 너비를 우선으로 하여 탐색을 수행하는 탐색 알고리즘이다.
* '맹목적인 탐색'을 하고자 할 때 사용할 수 있고, 최단경로를 찾아준다는 점에서
  최단 길이를 보장해야 할 때 많이 사용한다.
* 루트 노드에서 시작해서 인접한 노드를 먼저 탐색하는 방법
* 깊게 탐색하기전에 넓게 탐색하는 것이다.
* 너비 우선 탐색이 깊이 우선탐색보다 좀더 복잡하다.
    이유는 bfs는 재귀적으로 동작하지 않아서 인것같다
~~~

## BFS의 특징
~~~
* 직관적이지 않은 면이 있다.
    * BFS는 시작 노드에서 시작해서 거리에 따라 단계별로 탐색한다고 볼 수 있다.
* BFS는 재귀적으로 동작하지 않는다.
* 이 알고리즘을 구현할 때 가장 큰 차이점은, 그래프 탐색의 경우 어떤 노드를 방문했었는지 여부를
  반드시 검사 해야 한다는 것이다.
    * 이를 검사하지 않을 경우 무한 루프에 빠질 위험이 있다.
* BFS는 방문한 노드들을 차례로 저장한 후 꺼낼 수있는 자료 구조인 큐를 사용한다.
  * 즉, 선입선출(FIFO)원칙으로 탐색
  * 일반적으로 큐를 이용해서 반복적 형태로 구현하는 것이 가장 잘 동작한다.
~~~

## BFS의 활용
~~~
* P2P(peer-to-peer)어 네트워크에서 이웃노드를 찾는데 사용할 수 있다.
* GPS 시스템에서 가까운 위치를 찾고
* 소셜 네트워킹 사이트에서 지정된 거리에 있는 사람을 찾는 등의 작업을 수행할 수 있다.
* 가계도가 주어지면 가까운 가족을 찾을때 사용된다.(먼 조상을 찾을때는 DFS가 효과적이다.)
* Facebook에서 친구의 친구에 대한 제안을 할때에도 사용된니다.
~~~

## BFS의 원리
<img src="https://postfiles.pstatic.net/MjAxODAzMTZfMTA3/MDAxNTIxMTgwNDAzNjA0.UHWvRTbVmw6QVDorhYZgSBpDAUI90FWNRj2SVraQL-8g.dlSTfXYCJEtptG0p71HQckj8i56_LnCIhtGkC_cxvYgg.PNG.ndb796/image.png?type=w773" width="800" height="500">

~~~
- 우선 BFS를 하기 위해 큐와 그래프를 준비한다.
~~~

<img src="https://postfiles.pstatic.net/MjAxODAzMTZfMjgx/MDAxNTIxMTgxNTE5NzA1.5ui24F9iF_0jLLkda_oI4dlJSQeJCsUX-NaltK7zl1og.00nI0SnR1F8XezyXKUcR13lzPMEMEWjUc75mhfrH1aQg.PNG.ndb796/image.png?type=w773" width="800" height="500">

~~~
- 그다음 맨 처음에 시작 노드를 큐에 삽입하면서 시작한다. 시작 노드를 방문처리를 해준다.
  알아보기 쉽게 빨간색으로 색칠을 한다.
~~~
이제부터는 다음과 같은 간단한 알고리즘으로 진행된다.<br>
~~~
1. 큐에서 하나의 노드를 꺼냄.

2. 해당 노드에 연결된 노드 중 방문하지 않은 노드를 방문하고, 차례대로 큐에 삽입한다.

3. 위 1번과 2번을 계속 반복한다.
~~~

<img src="https://postfiles.pstatic.net/MjAxODAzMTZfMjA3/MDAxNTIxMTgxOTIzNzY2.HNHjTAyjqxA_i2jejRMwpyhZdD6jkZj81X_fZ8UL4AMg.rmqPi6prf0g81341bFGgPC4FqYwHnfZasCjbo6T16MYg.PNG.ndb796/image.png?type=w773" width="800" height="500">

~~~
- 먼저 시작노드 1을 큐에서 꺼내고 가장 위에다가 놓는다. 그리고 1에서 갈 수 있는 주변노드
  2와 3을 큐에 차례대로 넣는다.
~~~

<img src="https://postfiles.pstatic.net/MjAxODAzMTZfODUg/MDAxNTIxMTgyMDk0NzA1.TJNwLI8Y5Yi3RTbFOwtko5rHDkyhROG2fJimEeVM2Oog.E4y_RrvVid7BO5FkdyjTUQw3Cai-Kjh07QvnP7FJb6cg.PNG.ndb796/image.png?type=w773" width="800" height="500">

~~~
- 큐에서 2를 꺼낸 직후에 2와 인접한 노드 1, 3, 4, 5 중 1과 3은 이미 방문한 적이 있으므로 넘어가고
  4와 5를 큐에 삽입한다.
~~~

<img src="https://postfiles.pstatic.net/MjAxODAzMTZfMjAy/MDAxNTIxMTgyMTkzMDg3.iYTA1bQOvfWZlMlfT7zGxsaC2Ulqjndgop8RtBCHOVEg.D1qrG99pyf4vYlPkLbyiN5Hs8z55TuQXqdMBMe0cYw4g.PNG.ndb796/image.png?type=w773" width="800" height="500">

~~~
- 이후에 노드 3을 큐에서 꺼낸 후 3과 인접한 노드 1, 2, 6, 7 중 1과 2는 이미 방문한 적이 있으므로 넘어가고
  6과 7을 차례로 큐에 넣어준다. 따라서 그래프 내에 모든 노드가 방문처리가 되었다.
~~~

<img src="https://postfiles.pstatic.net/MjAxODAzMTZfMjc1/MDAxNTIxMTgyMjc0ODc0.rsN_4H-xqNQls_-LYV8oBwa2S6svKfT-0RSfY7a8K0Yg.fAkxep6hFhh8sSgxrYErVYkvQzSz5CVMdwMJaZXuRGAg.PNG.ndb796/image.png?type=w773" width="800" height="500">

~~~
- 마지막으로 차례대로 큐에서 꺼내준다.
~~~

## BFS의 시간복잡도 와 공간복잡도

BFS의 시간복잡도는 인접리스트로 구현했을 때와 인접행렬로 구현했을 때가 각각 다르다.
~~~
- 인접리스트 구현했을 때 시간복잡도 = O(V^2)
- 인접행렬로 구현했을 때 시간복잡도 = O(V+E)
~~~
공간복잡도는 다음과 같다.
~~~
- 공간복잡도 = O(n)
~~~

## BFS의 장단점

<장점>
~~~
- 너비를 우선으로 탐색하기 때문에 답이 되는 경로가 여러 개인 경우에도 최단경로임을 보장함
- 최단경로가 존재한다면, 어느 한 경로가 무한히 깊어진다 해도 최단경로를 반드시 탐색 가능함
- 노드 수가 적고 깊이가 얕은 해가 존재할 때 유리함
~~~

<단점>
~~~
- 재귀호출을 사용하는 DFS와 달리 큐를 사용해 다음에 탐색할 노드를 저장하기 때문에 노드 수가 많을수록
  필요없는 노드들 까지 저장해야 하기 때문에 더 큰 저장공간을 요구함
- 노드의 수가 늘어나면 탐색해야하는 노드가 많아지기 때문에 비효율적임
~~~

## 
[사진출처](https://blog.naver.com/ndb796/221230944971) / 
[BFS의 이론](https://gmlwjd9405.github.io/2018/08/15/algorithm-bfs.html) / 
[BFS의 예시](https://stackoverflow.com/questions/3332947/when-is-it-practical-to-use-depth-first-search-dfs-vs-breadth-first-search-bf)
