## 퀵정렬(quick_sort) 코틀린 코드?

~~~Kotlin
import java.util.*
var data = arrayOf<Int>(3,2,1,4,6,7,8,10,9,5)

fun qucik_sort(data: Array<Int>, start: Int, end: Int){
    if(start >= end){
        return
    }
    var pivot = start
    var leftdepart = pivot +1
    var rightdepart = end
    var temp = 0

    while (leftdepart <= rightdepart){
        while (leftdepart <= end && data[leftdepart] <= data[pivot]){
            leftdepart++
        }
        while (rightdepart > start && data[rightdepart] >= data[pivot]){
            rightdepart--
        }

        if(leftdepart > rightdepart){
            temp = data[rightdepart]
            data[rightdepart] =data[pivot]
            data[pivot] =temp
        }
        else{
            temp =data[leftdepart];
            data[leftdepart] = data[rightdepart]
            data[rightdepart] =temp
        }
    }
    qucik_sort(data,start,rightdepart-1)
    qucik_sort(data,rightdepart+1,end)
}

fun main(){
    qucik_sort(data,0,9)
    println(Arrays.toString(data))
}
~~~
