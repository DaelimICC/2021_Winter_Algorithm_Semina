# Radix Sort(SuffixArray)


## 접미사 배열
~~~
컴퓨터 과학에서 접미사 배열이란 어떤 문자열의 접미사를 사전식 순서대로 나열한 배열을 말한다. 
문자열 검색이나 전문 검사 등에 쓰인다. 영어로는 suffix array인데, 
이를 번역하지 않고 서픽스 배열이나 서픽스 어레이라고 부르기도 한다.
~~~

## 예시
<img src= "https://user-images.githubusercontent.com/89181586/149147881-877d66d3-62cf-4357-9ba5-4f28d3b64c5e.jpg" width="800" height="300"/>

##

~~~kotlin
fun main(args: Array<String>) {
        val text = "banana"
        val suffixes = makeSuffixArray(text) // 배열생성하고 바나나를 넣어준다.
        printSuffixes(text, suffixes) // 출력합니다.
    }

fun makeSuffixArray(text: String): ArrayList<Int> {
        val len = text.length

        val suffixes = ArrayList<Int>() //접미사 내용 저장할 배열 생성
        for (i in 0 until len) {
            suffixes.add(i) 
        }
        
        val comp: Comparator<Int> = Comparator { o1, o2 ->
            val a = text.substring(o1!!)
            val b = text.substring(o2!!)
            a.compareTo(b) // in 연산자 이며 a에 b가 있는가?를 구분할수 있다!
        }
        Collections.sort(suffixes, comp)//호출로 문자열을 비교
        return suffixes
    }
    
    // print하는 용도의 함수
    fun printSuffixes(text: String, suffixes: ArrayList<Int>) {
        for (i in suffixes) {
            print("$i, ")
        }
        println()

        // 정렬된 접미사 출력
        for (i in suffixes) {
            print(text.substring(i) + ", ")
        }
        println()
    }
}
~~~

##

[접미사 배열](https://www.crocus.co.kr/613)
[코드](https://hongjw1938.tistory.com/44)
