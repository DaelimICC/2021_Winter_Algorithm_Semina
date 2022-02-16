# 11047 동전 0 (실버 3)
![image](https://user-images.githubusercontent.com/70959328/154314450-b389f934-1597-4507-b4ba-ee3721cc43bc.png)
### 풀이 과정
1. 동전의 종류 N과 가지고 있는 금액 K를 입력 받는다.
2. 그리디 알고리즘을 통해 최적해를 찾아 필요한 동전 개수 최솟값을 찾는다.
3. K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다.


### 코드 설계
1. 동전의 종류 N과 가지고 있는 금액 K를 입력 받는다.
2. coin 배열을 선언하여 동전 값을 받는다.
3. count 변수를 선언하여 동전 개수를 할당한다.
4. 반복문의 동전 가치가 K보다 작거나 같다면 K와 동전 값을 나누어 count에 할당해준다.
5. K값에 K와 현재 동전값의 나머지를 재할당한다.
6. count 값을 출력한다.

### 핵심 코드
```java
for(int i = N - 1; i >= 0; i--) {
  // 현재 동전의 가치가 K보다 작거나 같아야지 구성가능하다.
  if(coin[i] <= K) {
    // 현재 가치의 동전으로 구성할 수 있는 개수를 더해준다.
    count += (K / coin[i]);
    K = K % coin[i];
  }
}
```
1. 반복문의 동전 가치가 K보다 작거나 같다면 K와 동전 값을 나누어 count에 할당해준다.
2. K값에 K와 현재 동전값을 나눈 나머지를 재할당한다.


### 전체 코드
```java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int K = sc.nextInt();

        int[] coin = new int[N];

        for(int i = 0; i < N; i++) {
            coin[i] = sc.nextInt();
        }

        int count = 0;

        for(int i = N - 1; i >= 0; i--) {
            if(coin[i] <= K) {
                count += (K / coin[i]);
                K = K % coin[i];
            }
        }
        System.out.println(count);
    }
}

```
