public class Merge_Sort {

    private static void mergeSort(int[] arr){ // mergeSort 함수에 정렬할 배열을 인자로 받는다
        int[] tmp = new int[arr.length]; // 배열의 크기만큼 임시 저장공간을 만든다
        mergeSort(arr, tmp, 0, arr.length-1); //재귀함수 호출
    }
    private static void mergeSort(int[] arr, int[] tmp, int start, int end){ //정렬할 배열, 정렬 임시 저장소, 시작 인덱스, 끝 인덱스를 인자로 받음
        if(start < end){ // 시작 인덱스가 끝 인덱스보다 작을때까지
            int mid = (start + end)/2; // 시작 인덱스 + 끝 인덱스 / 2를 하여 가운데 인덱스 추출
            mergeSort(arr, tmp, start, mid); // 배열 앞부분 range 재귀 호출
            mergeSort(arr, tmp, mid+1, end); // 배열 뒷부분 range 재귀 호출
            merge(arr, tmp, start, mid, end); // 정렬 함수 호출
        }
    }
    private static void merge(int[] arr, int[] tmp, int start, int mid, int end){ // 배열 포인터, 임시 저장소, 시작 인덱스, 중간 인덱스, 끝 인덱스를 인자로 받음
        for(int i=start; i<=end; i++){
            tmp[i] = arr[i]; // 임시 저장소에 정렬이 된 배열을 필요한 만큼 복사
        }
        //두 배열(배열 앞, 뒤)의 시작점
        int part1 = start;
        int part2 = mid+1;
        //결과 배열의 시작점
        int index = start;

        while(part1 <= mid && part2 <= end){ // 첫 번째 배열이 끝까지 가거나 두 번째 배열이 끝까지 갈때까지 반복
            if(tmp[part1] <= tmp[part2]){ // 첫 번째 배열이 더 작은 경우
                arr[index] = tmp[part1]; // 첫 번째 배열을 옮긴다
                part1++; //포인터를 뒤로 이동
            }else{// 위 조건 반대
                arr[index] = tmp[part2];
                part2++;
            }
            index++; // 어느쪽 배열을 옮였던지 간에 인덱스는 하나 늘려줘야함
        }
        //뒤쪽 배열은 비었고 앞쪽 배열에 남아 있는 경우
        //앞쪽 포인터가 배열의 끝에서 남은 만큼까지를 넣어줌
        for(int i=0; i < mid-part1; i++){
            arr[index+i] = tmp[part1+i];
        }
        //뒤쪽 배열이 남아 있는 경우, 최종 배열에 이미 데이터가 남아 있기 때문에 신경쓰지 않아도 된다.
    }
    private static void printArray(int[] arr){ //결과 확인을 위한 프린트 함수
        for(int data : arr){
            System.out.print(data + ", ");
        }
        System.out.println();
    }
    public static void main(String[] args){
        int[] arr = {3, 9, 4, 7, 5, 0, 1, 6, 8, 2};
        printArray(arr);
        mergeSort(arr);
        printArray(arr);
    }
}