## 1072번 문제 - 게임

![image](https://user-images.githubusercontent.com/92222661/153145419-aac2b385-fe73-456f-9f45-35478e495980.png)

## 정답코드 for Java
```java
import java.util.Scanner;

public class asd {

    static long X, Y, Z;

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

         X = scanner.nextInt(); // 게임횟수
         Y = scanner.nextInt(); // 이긴 게임
         Z = Y * 100 / X; //형택이의 승률

        if(Z >= 99)
            System.out.println(-1);
        else
            binarySearch(1, X);
        }
    private static void binarySearch(long start, long end) { // 이분탐색 알고리즘
        long mid = 0, per = 0; // 중간값과 확률변화 비율 선언
        while(start <= end) {
            mid = (start + end) /2;
            per = (Y + mid) * 100 / (X + mid);

            if (per > Z){
                end = mid - 1;
            } else{
                start = mid + 1;
            }
        }
        System.out.println(start);
        }
    }

```
