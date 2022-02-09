# 1920 수찾기(실버 4)

![image](https://user-images.githubusercontent.com/89181586/153118066-0273ccdd-5ee7-4fa3-a20c-ca491a0a0dad.png)

### 풀이과정
~~~
  1. 첫째줄과 셋째줄에 받을 수의 크기를 입력합니다.
  2. 두번째와 네번째줄에는 비교할 수를 입력받습니다.
  3. 1번에서 받은수 만큼 숫자를 비교하는 방식입니다.
~~~

### 코드과정
~~~
  1. 수의 입력을 먼저 받습니다.
  2. 같은수인지 아닌지를 가려줄 변수 하나를 만들어 줍니다.
  3. 받은 숫자의 길이만큼 for문에 넣어줍니다.
  4. 같은 수가 있는지를 비교하고 출력해줍니다. 
~~~

### CODE

```kotlin
import java.io.*

fun main(){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    var n = br.readLine().toInt()
    var a = br.readLine().split(" ").map { it.toInt() }
    var m = br.readLine().toInt()
    var b = br.readLine().split(" ").map { it.toInt() }
    var c=0
    for (i in 0 until  n){
        c=0
        for (j in 0 until  m){
            if (a[j] == b[i]) c=1
        }
        if (c==1){
            bw.write("1\n")
        }else bw.write("0\n")
    }
    bw.flush()
    bw.close()
}
```
<br>

# 7795 먹을 것인가 먹힐 것인가(실버 3)

![image](https://user-images.githubusercontent.com/89181586/153118206-107d4c0f-3685-4bc2-bfff-765ca1db5de9.png)

### 풀이과정
~~~
  1. 첫째줄에 몇번 반복할지를 입력받습니다.
  2. 두번째줄에는 두그룹에 몇개의 수가 있는지를 입력합니다.
  3. 다음줄에 첫번째 그룹의 숫자를 그다음줄에는 두번째 그룹의 숫자를 입력합니다.
  4. 이중for문으로 비교하여 출력합니다.
~~~

### 코드과정
~~~
  1. 수의 입력을 먼저 받습니다.
  2. reoeat(for문이랑 비슷한 역할입니다.)를 이용하여 반복을 해줍니다.
  3. 두그룹의 수를 입력받고 for문을 사용하여 돌려 줍니다.
  4. 첫번째 그룹의 첫번째 숫자부터 크기를 비교하여 수의 크기가 크다면 count++ 해줍니다.
  5. repeat가 다음으로 넘어가기전에 count의 값을 출력해줍니다.
~~~

### CODE

```kt
fun main() = with(System.`in`.bufferedReader()){
    var n = readLine().toInt()
    var count=0
    repeat(n){
        c=0
        var x = readLine().split(" ").map { it.toInt() }
        var a = readLine().split(" ").map { it.toInt() }
        var b = readLine().split(" ").map { it.toInt() }
        for (i in 0 until  x[0]) {
            for(j in 0 until  x[1]){
                if (a[i] > b[j]) count+=1
            }
        }
        println("$count")
    }
}
```
<br>

# 1388 바닥장식(실버 4)

![image](https://user-images.githubusercontent.com/89181586/153124666-6e88b8a0-ab35-468f-a2c7-05551f8b33fa.png)

### 풀이과정
~~~
  1. 가로와 세로의 길이를 입력합니다
  2. 줄의 크기만큼의 바닥모양을 입력합니다.
  3. 가로와 세로에 이어져있는지 확인을 해줄 함수를 만들어줍니다.
  4. 함수는 오른쪽으로 1씩커지거나 아래로 1씩 커지는 형식으로
  5. 누워있는 모양은 가로일때만 이어질수있고 서있는 모양은 세로 일때만 이어집니다.
  6. 인접한 모양이 같으면 if로 비교해서 수를 하나로 처리를 해줍니다.
~~~

### 코드과정
~~~
  1. 수의 입력을 먼저 받습니다.
  2. 모양을 입력받습니다.
  3. for문을 돌려 줄마다 인접한것이 있는지를 비교해줍니다.
  4. 만약 인접해 있다면 c=1로 바꿈으로써 다음에 모양이 같더라도 num의 크기는 증가하지 않습니다.
  5. 세로도 같은 방식으로 비교를 해주면 비교가 가능합니다.
~~~

### CODE
```kt
import java.util.*

var s :Array<CharArray> = arrayOf()
var c =0
var num = 0

fun ga(a:Int,b:Int) {
    for(i in 0 until a){

        for(j in 0 until b){
            if(s[i][j] == '-'){
                if(c==0){
                    num++
                    c=1
                }
            }else{
                c=0
            }

        }
        c=0
    }
}
fun se(a:Int,b:Int) {
    for(j in 0 until a){
        for(i in 0 until b){
            if(s[i][j] == '|'){
                if(c==0){
                    c=1
                    num++
                }
            }else{
                c=0
            }
        }
        c=0
    }
}
fun main() = with(Scanner(System.`in`.bufferedReader())){
    var n = readLine()!!.split(" ").map { it.toInt() }
    s = Array(n[0]){ CharArray(n[1]) }
    for(i in 0 until n[0]){
        var str = readLine()!!.toCharArray()
        for(j in 0 until n[1]){
            s[i][j]=str[j]
        }
    }
    ga(n[0],n[1])
    se(n[1],n[0])
    println(num)
}
```
