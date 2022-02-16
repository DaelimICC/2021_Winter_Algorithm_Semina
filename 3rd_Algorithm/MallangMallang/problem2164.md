# 2164 카드2 (실버 4)
![2164](https://user-images.githubusercontent.com/70959328/154320495-2e967ac1-e184-4dbf-ae95-729233a55866.PNG)
### 풀이 과정
1. N을 입력하면 1부터N까지의 순서로 놓아진다.
2. 맨 앞의 수를 삭제하고 그 다음 앞의 수를 삭제한 뒤 삭제한 수를 맨 뒤에 삽입한다.
3. 위 과정을 1개가 남을 때 까지 반복하고 남은 값을 출력한다.


### 코드 설계
1. 자바의 Queue와 LinkedList 라이브러리를 이용해 선언한다.
2. q.offer()를 통해 1부터 N까지의 수를 큐에 할당한다.
3. q.poll()로 맨 앞의 원소를 버리고 맨 앞의 원소를 버림과 동시에 버려진 원소를 맨 뒤에 삽입한다.
4. 1개가 남을 때 까지 반복하여 마지막으로 남은 원소를 출력한다.

### 핵심 코드
```java
while(q.size() > 1) { //원소가 한 개만 남을 때 까지 반복
  q.poll();	// 맨 앞의 원소 버림 
	q.offer(q.poll());	// 맨 앞의 원소를 버림과 동시에 버려진 원소를 맨 뒤에 삽입 
}
		
System.out.println(q.poll());	// 마지막으로 남은 원소 출력 
```

1. 원소가 한 개만 남을 때 까지 반복한다.
2. 우선 맨 앞의 원소 버린다.
3. 맨 앞의 원소를 버림과 동시에 버려진 원소를 맨 뒤에 삽입한다.
4. 마지막으로 남은 원소를 출력한다.



### 전체 코드
```java
import java.util.Queue;
import java.util.LinkedList;
 
import java.util.Scanner;
 
public class Main {
 
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		Queue<Integer> q = new LinkedList<>();
		
		int N = in.nextInt();
		
		for(int i = 1; i <= N; i++) {
			q.offer(i);
		}
		
		
		while(q.size() > 1) {
			q.poll();
			q.offer(q.poll());
		}
		
		System.out.println(q.poll());
	}
}
```
