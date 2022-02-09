# 2750 수 정렬하기 1 (브론즈 1)
![2750](https://user-images.githubusercontent.com/70959328/153127318-7547ce8f-7ff6-4d4f-b8b9-5809a5f164cd.PNG)
### 풀이 과정
1. N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 정렬 알고리즘
2. O(n^2)의 시간 복잡도를 넘지만 않으면 성공할 수 있는 알고리즘


### 코드 설계
1. 코드의 가독성을 위해 swap함수 생성
2. 값을 받을 수 있는 반복문 작성
3. 값을 정렬할 수 있는 반복문 작성 (버블소트)
4. 값을 하나씩 출력하는 반복문 작성

```java
import java.util.Scanner;

public class Main {
    //스왑함수
    public static void swap(int arr[], num){
        if (arr[num] > arr[num+1]) {
                    int temp = arr[num+1];
                    arr[num+1] = arr[num];
                    arr[num] = temp;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int arr[] = new int[N];
        //값 입력
        for (int i = 0; i < arr.length; i++) {
            arr[i] += sc.nextInt();
        }
        //버블소트
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                swap(arr, j)
            }
        }
        //출력
        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }
}
```
