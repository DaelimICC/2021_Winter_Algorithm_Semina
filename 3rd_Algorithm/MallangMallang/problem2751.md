# 2751 수 정렬하기 2 (실버 5)
![2751](https://user-images.githubusercontent.com/70959328/153127655-08c27877-d3cc-444c-b6cf-b4fdbe59ace8.PNG)
### 풀이 과정
1. N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 정렬 알고리즘
2. O(nlongn)의 시간 복잡도를 넘지만 않으면 성공할 수 있는 알고리즘


### 코드 설계
1. ArrayList를 생성한다.
2. 리스트에 값을 받는다.
3. Collections.sort를 이용해 정렬해준다.
4. 값을 출력한다.

```java
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int N = sc.nextInt();
		
		ArrayList<Integer> list = new ArrayList<>();


		for(int i = 0; i < N; i++) {
			list.add(sc.nextInt());
		}

		// Arrays.sort가 아닌 Collections.sort를 사용
		Collections.sort(list);

		for(Integer i : list) {
			sb.append(i).append("\n");
		}
		
		System.out.println(sb);
	}
}
```
