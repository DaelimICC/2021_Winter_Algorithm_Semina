import java.util.*

var n = 0 // 사람의 개수
var a = 0 // 서로 다른 두 사람
var b = 0 // 서로 다른 두 사람
var m = 0 // 관계의 개수
var count = 0 // 촌수
lateinit var q : Queue<Int>

var graph = Array(101) {Array<Int>(101) {0}} // 관계 2차원 배열로 표현
var visit = Array(101){0} // 방문 여부 표시

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    n = nextInt()
    a = nextInt()
    b = nextInt()
    m = nextInt()
    q = LinkedList()

    for (i in 0 until m) {
        var j = nextInt()
        var q = nextInt()
        graph[j][q] = 1
        graph[q][j] = 1
    } // 관계 표시해줌

    BFS(a)
}

fun BFS(x : Int){
    var tmp = x
    q.add(tmp) // 자기자신 큐에 삽입
    visit[tmp] = 1;

    while(!q.isEmpty()){
        for(i in 1..q.size){
            tmp = q.poll()

            if (b == tmp) {
                return println(count)
            } // 관계를 찾는 상대방을 마주치게 되면, 종료

            for(j in 1..n){
                if(visit[j] == 0 && graph[tmp][j] == 1) {
                    q.add(j)
                    visit[j] = 1
                } // 방문하지 않았고, 연결되있다면 큐에 삽입, 방문 처리
            }
        }
        count++ // bfs 레벨파악을 위해 q의 사이즈만큼 반복하여 종료될 때 마다 count
    }
    println(-1) // 관계가 성립되지 않음
}
// https://hanyeop.tistory.com/116
