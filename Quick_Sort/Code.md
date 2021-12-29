## 퀵정렬(quick_sort) 코틀린 코드?

~~~Kotlin
import java.util.*
var data = arrayOf<Int>(3,2,1,4,6,10,8,7,9,5)

fun qucik_sort(data: Array<Int>, start: Int, end: Int){
    if(start >= end){
        return
    }
    var pivot = start
    var leftdepart = pivot
    var rightdepart = end +1
    var temp=0

    while (leftdepart <= rightdepart){
        do{
            leftdepart++
        } while (leftdepart < end && data[leftdepart] < data[pivot])
        do{
            rightdepart--
        } while (rightdepart > start && data[rightdepart] > data[pivot])

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
Copyright (c) 2021 DaelimCollege_JumpStudy
