1st Writter : NightRabbit  

## BFS의 정의
~~~
BFS는 탐색을 할 때, 너비를 우선으로 하여 탐색을 수행하는 탐색 알고리즘이다.
'맹목적인 탐색'을 하고자 할 때 사용할 수 있고, 최단경로를 찾아준다는 점에서
최단 길이를 보장해야 할 때 많이 사용한다.
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
