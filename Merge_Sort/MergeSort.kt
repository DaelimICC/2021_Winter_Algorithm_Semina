import java.util.*

var array = arrayOf(4,5,2,3,1,7,8,6)
var assistant = arrayOf(0,0,0,0,0,0,0,0)

fun merge(list : Array<Int>, left :Int, mid :Int, right :Int ){
    var leftlist = left
    var rightlist = mid +1
    var sortlist = left

    do {
        if(list[leftlist]<=list[rightlist])
            assistant[sortlist++] = list[leftlist++]
        else
            assistant[sortlist++] = list[rightlist++]
    }
    while(leftlist<=mid && rightlist<=right)

    if(leftlist>mid){
        for(loop in rightlist..right)
            assistant[sortlist++] = list[loop]
    }

    else{
        for(loop in leftlist..mid)
            assistant[sortlist++] = list[loop]
    }

    for(loop in left..right){
        list[loop] = assistant[loop]
    }
}
fun merge_sort(list : Array<Int>, left :Int,right :Int){
    if(left<right){
        var mid = (left+right)/2
        merge_sort(list, left, mid)
        merge_sort(list, mid+1, right)
        merge(list, left, mid, right)
    }
}
fun main(){
    merge_sort(array, 0, 7)
    println(Arrays.toString(array))
}
