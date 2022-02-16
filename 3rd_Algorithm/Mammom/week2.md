# 10816 숫자 카드 2(실버 4)

![image](https://user-images.githubusercontent.com/89181586/154258707-a2ebdd10-3367-4547-9842-5fbdd34f8cf4.png)

### 풀이과정
~~~
  1. 첫째줄과 셋째줄에 받을 수의 크기를 입력합니다.
  2. 두번째와 네번째줄에는 비교할 수를 입력받습니다.
  3. 두번째 집합과 첫번째집합을 비교하며 몇개가 존재하는지를 구한다.
~~~

### 코드과정
~~~
  1. 수의 입력을 먼저 받습니다.
  2. 같은수이면 갯수가 몇개인지를 알려줄 변수를 설정해준다.
  3. 받은 숫자의 길이만큼 for문에 넣어줍니다.
  4. 같은 수가 있으면 1씩더해주고 몇개인지를 출력해준다.
  5. 갯수로 사용한 변수를 0으로 초기화 해준다.
~~~

### CODE

```kotlin
import java.io.*
import java.util.*

fun main() = with(Scanner(System.`in`.bufferedReader())){
    var n = nextLine().toInt()
    var a = nextLine().split(" ").map { it.toInt() }
    var m = nextLine().toInt()
    var b = nextLine().split(" ").map { it.toInt() }
    var c=0

    for (i in 0 until  m){
        for (j in 0 until n){
            if (b[i] == a[j]){
                c++
            }
        }
        println(c)
        c=0
    }
}
```
<br>

# 4673 셀프 넘버(실버 5)

![image](https://user-images.githubusercontent.com/89181586/154258774-94379fe3-eb9a-4687-88cc-f2e5428971cf.png)

### 풀이과정
~~~
  1. 셀프넘버를 구하는 식을 만들어야한다.
  2. 셀프넘버란 어떤 정수와 그정수의 각 자리 숫자의 합으로 나타낼수 없는 수를 말한다.
  3. 셀프넘버는 나타낼수 없는 값을 말하기 때문에 나타낼수 있는 값을 구하고
  4. 못나타내는 것을 출력해 주려고 한다.
~~~

### 코드과정
~~~
  1. 배열 만드고 10001만큼 돌려줍니다.
  2. for문안에 함수 호출해서 셀프 넘버가 아닌수를 받아서 배열에 표시해 줍니다.
  3. 표시를 안한 배열값과 일치할때만 몇번째 인지 표시를 해주면 됩니다.
~~~

### CODE

```kt
import java.util.*

fun main() = with(Scanner(System.`in`.bufferedReader())){
    var gen = Array(10001) { 0 }
    for (i in 1..10001){
        var num = plus(i)
        if (num < 10001) gen[num] = 1
    }
    for (i in 1..10000){
        if (gen[i]==0) println(i)
    }
}
fun plus(value : Int) : Int{
    var v = value
    var sum = value
    while (v !=0){
        sum += v % 10
        v /= 10
    }
    return sum
}
```
<br>

# 12845 모두의 마블(실버 3)

![image](https://user-images.githubusercontent.com/89181586/154258822-6207cded-41ef-412b-8bdc-3c2c83d957ad.png)

### 풀이과정
~~~
  0. 주어진 두개의 값을 더했을때 가장 큰 합을 구하라는 문제입니다.
  1. 수를 몇개 받을 건지 물어봅니다.
  2. 내가 사용할 수를 일렬로 이쁘게 적어줍니다.
  3. 내가 적은 가장 큰 수와 각기다른 수를 더해주면 됩니다.
~~~

### 코드과정
~~~
  1. 크기랑 수들을 받아 줍니다.
  2. sorted로 큰순으로 정렬해줍니다.
  3. 가장 큰수와 차례로 더해줍니다.
  4. 더해준 값을 출력해주면 됩니다.
~~~

### CODE
```kt
fun main() = with(System.`in`.bufferedReader()) {
    var n = readlnOrNull()?.toInt()
    var a = readlnOrNull()?.split(" ")!!.map{ it.toInt() }
    var sum =0
    a.sorted()
    for (i in 1 until n!!){
        sum += a[0] +a[i]
    }
    println(sum)
}
```
