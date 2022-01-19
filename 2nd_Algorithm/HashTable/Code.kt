fun main(){
    print("")
    var a = readLine()
    var n = a?.split("")
    print("")
    var b = readLine()
    var m = b?.split("")
    var c=0
    for(i in 1..a!!.length){
        c=0
        for(j in 1..b!!.length){
            if(m?.get(i).equals(n?.get(j))){
                c=1
                println(1)
            }
        }
        if(c == 0)println(0)
    }
}
