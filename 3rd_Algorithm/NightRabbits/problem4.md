## 1434번 문제 - 책 정리

![image](https://user-images.githubusercontent.com/92222661/154315923-419ac835-f41f-4f9f-9f6f-740175ef6745.png)


## 정답코드 for Java
```java
import java.util.Scanner;

public class asd {
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt(); // 박스의 갯수
        int M = scanner.nextInt(); // 책의 갯수
        int x = 0;
        int sum = 0;

        int []box = new int[N];
        int []book = new int[M];

        for (int i = 0; i < N; i++){
            box[i] = scanner.nextInt();
        }
        for (int i = 0; i < M; i++){
            book[i] = scanner.nextInt();
        }

        for (int book_val = 0; book_val < N; book_val++) {
            while(true){
                if (box[x]<book[book_val]){
                    x++;
                }
                else{
                    box[x] -= book[book_val];
                    break;
                }
            }
        }
        for (int i = 0; i < N; i++){
            sum += box[i];
        }
        System.out.println(sum);
    }
}
```
