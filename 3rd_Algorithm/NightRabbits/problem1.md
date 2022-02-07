## 2798번 문제 - 블랙잭

![image](https://user-images.githubusercontent.com/92222661/152747123-84b96109-b939-460a-bf8d-379ae3e97947.png)

## 문제 설명
이 문제는 Brute Force에 관한 문제로 여기서 Brute Force란 난폭한 힘 이라는 의미 그대로<br>
어떠한 값을 찾아내기 위해 무차별적으로 대입 해보는 방법이다.<br>

## 정답코드 for Java
```java
import java.util.Scanner;

public class asd {

    static int search(int[] arr, int N, int M) {
        int result = 0;

        for (int firstnum = 0; firstnum < N - 2; firstnum++) {


            for (int secondnum = firstnum + 1; secondnum < N - 1; secondnum++) {

                for (int thirdnum = secondnum + 1; thirdnum < N; thirdnum++) {

                    int Sum = arr[firstnum] + arr[secondnum] + arr[thirdnum];

                    if (M == Sum) {
                        return Sum;
                    }
                    if (result < Sum && Sum < M) {
                        result = Sum;
                    }
                }
            }
        }
        return result;
    }


        public static void main(String args[]){
            Scanner scanner = new Scanner(System.in);

            int N = scanner.nextInt();
            int M = scanner.nextInt();

            int[] arr = new int[N];

            for (int i = 0; i < N; i++) {
                arr[i] = scanner.nextInt();
            }
            int reuslt = search(arr, N, M);
            System.out.println(reuslt);


        }
    }
```
