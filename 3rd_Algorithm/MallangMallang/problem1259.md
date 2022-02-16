# 1259 팰린드롬수 (브론즈 1)
![image](https://user-images.githubusercontent.com/70959328/154292954-8652a88f-256e-4041-8326-348168ba36f1.png)
### 풀이 과정
1. 각 줄마다 1 이상 99999 이하의 수를 받는다.
2. 0을 입력하면 프로그램을 종료하며, 주어진 수가 팰린드롬수면 'yes', 아니면 'no'를 출력한다.


### 코드 설계
1. BufferedReader를 통해 입력값을 자동으로 나누어 char 배열에 저장한다.
2. 입력받은 수의 길이에 절반값 반큼 반복을 한다.
3. 저장된 배열의 i번째 값과 길이 - 1 - i 번 째 값과 비교하여 서로 다르면 false를 반환한다.
4. 입력받은 배열의 1번 째 값이 0이면 프로그램을 종료하고 flag가 ture이면 yes를, false면 no를 출력한다.

### 핵심 코드
```java
  char[] str = br.readLine().toCharArray(); //BufferedReader를 통해 값을 char형으로 나누어 배열에 저장한다.
  boolean flag = true; //수를 판별하기 위해 flag를 선언한다.
  if (str[0] == '0') { //입력받은 배열의 1번 째 값이 0이면
    System.out.print(sb); //sb값에 저장된 값을 출력하고 프로그램을 종료한다.
    break;
  }
```
1. BufferedReader를 통해 값을 char형으로 나누어 배열에 저장한다.
2. 수를 판별하기 위해 flag를 선언한다.
3. 입력받은 배열의 1번 째 값이 0이면 sb값에 저장된 값을 출력하고 프로그램을 종료한다.


```java
for (int i = 0; i < str.length / 2; i++) { 
  if (str[i] != str[str.length - 1 - i]) {
      flag = false; // 저장된 배열의 i번째 값과 길이 - 1 - i 번 째 값과 비교하여 서로 다르면 false를 반환한다.
  }
}
sb.append(flag ? "yes\n" : "no\n"); // flag가 ture이면 yes를, false면 no를 출력한다.
```
1. 입력받은 수의 길이에 절반값 반큼 반복을 한다.
2. 저장된 배열의 i번째 값과 길이 - 1 - i 번 째 값과 비교하여 서로 다르면 false를 반환한다.
3. flag가 ture이면 yes를, false면 no를 출력한다.


### 전체 코드
```java
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            char[] str = br.readLine().toCharArray();
            boolean flag = true;
            if (str[0] == '0') {
                System.out.print(sb);
                break;
            }

            for (int i = 0; i < str.length / 2; i++) {
                if (str[i] != str[str.length - 1 - i]) {
                    flag = false;
                }
            }
            sb.append(flag ? "yes\n" : "no\n");
        }
    }
}
```
