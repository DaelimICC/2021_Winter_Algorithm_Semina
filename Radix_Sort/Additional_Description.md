# Radix Sort (Additional Description)  
## 유효 숫자 (Significant Figures)
간단하게 이야기하면, 수의 정확도에 영향을 주는 숫자이다.  
우선, 측정값에 한하여, 0이 아닌 숫자로 시작하는 자리부터 유효숫자로 간주한다.  

## MSD

숫자의 정확도가 높은 순으로 정렬하여, 중간에 정렬을 마치도록 하고자 하는것이 MSD의 주 목적이다.  
MSD 정렬은 코드 구현이 복잡하지만, 중간에 정렬이 될 수 있다는 장점이 있다.  

```cpp
void msd_sort(struct node* root, int exp,
    vector<int>& sorted_arr)
{
    if (exp <= 0) {
        return;
    }

    int j;

    // 버킷 배열 생성
    for (int i = 0;
        i < root->arr.size();
        i++) {

        // 최상위 지수 값 출력
        j = (root->arr[i] / exp) % 10;

        // j인덱스에 해당하는 배열이 없는 경우, 생성
        if (root->nxt[j] == NULL) {
            root->nxt[j] = new_node();
        }

        root->nxt[j]->arr.push_back(
            root->arr[i]);
    }

    // 자식 노드에 대한 정렬
    for (int i = 0; i < 10; i++) {

        if (root->nxt[i] != NULL) {

            if (root->nxt[i]->arr.size()
    > 1) {
                // 정렬 반복
                msd_sort(root->nxt[i],
                    exp / 10,
                    sorted_arr);
            }
            else {
                sorted_arr.push_back(
                    root->nxt[i]->arr[0]);
            }
        }
    }
}
```
