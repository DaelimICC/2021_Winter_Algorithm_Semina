## 2606번 문제 - 바이러스

![image](https://user-images.githubusercontent.com/92222661/152972772-07d3c017-5387-431b-820d-7cf41a706abe.png)

## 정답코드 for Java
```java
import java.util.Scanner;

class asd {
    static int Vcom = 0;

    // DFS 메소드
    static void dfs(int[][] arr, boolean[] check, int v) {
        if(check[v]==true){
            return;
        }

        check[v] = true;
        Vcom++;

        for(int i=0; i<arr[v].length; i++) { // 인접행렬을 탐색
            if(arr[v][i]==1 && !check[i]) // 연결된 정점이면서 방문하지 않은 경우
                dfs(arr,check,i); // DFS 수행
        }
    }
    //메인 메소드
    public static void main(String[] args)  {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt(); // 정점의 수
        int M = scanner.nextInt(); // 간선의 수

        int [][] arr = new int[N+1][N+1];
        boolean [] check = new boolean[N+1];

        for(int i=0;i<M;i++) {
            int v1 = scanner.nextInt();
            int v2 = scanner.nextInt();

            arr[v1][v2] = 1;
            arr[v2][v1] = 1;
        }

        dfs(arr,check,1);

        System.out.println(Vcom-1);

    }
}
```
