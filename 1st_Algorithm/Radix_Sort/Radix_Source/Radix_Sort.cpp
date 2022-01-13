#include <iostream>
#include <vector>

using namespace std;

// Node 구조
struct node {
	vector<int> arr;
	struct node* nxt[10];
};

// 노드 생성에 관한 함수
struct node* new_node(void)
{
	struct node* tempNode = new node;

	for (int i = 0; i < 10; i++) {
		tempNode->nxt[i] = NULL;
	}

	// 생성된 노드 반환
	return tempNode;
}

// MSD 구현부
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

// MSD 연산을 위한 최대 지수 반환
int get_max_exp(vector<int> arr)
{
	// 최댓값 저장 공간 확보
	int mx = arr[0];

	// 최댓값 찾기
	for (int index = 1; index < arr.size(); index++) {
		if (arr[index] > mx) {
			mx = arr[index];
		}
	}

	// 최대 지수값 저장 공간 확보
	int exp = 1;

	while (mx > 10) {
		mx /= 10;
		exp *= 10;
	}

	// 최대 지수값 반환
	return exp;
}

// 배열 출력
void print(vector<int> arr)
{
	for (int index = 0; index < arr.size(); index++)
		cout << arr[index] << " ";

	cout << endl;
}

// 메인 코드부
int main()
{
	// 루트 노드 생성
	struct node* root = new_node();

	// 정렬되지 않은 배열 저장
	root->arr.insert(root->arr.end(),
		{ 888, 222, 333, 444, 555, 111, 999, 1203, 32, 9 });

	cout << "비정렬 배열 >> ";

	// 정렬 전 배열 출력
	print(root->arr);

	// 최장 지수 저장
	int exp = get_max_exp(root->arr);

	// 정렬할 배열 선언
	vector<int> sorted_arr;

	// 정렬
	msd_sort(root, exp, sorted_arr);

	cout << "정렬 배열 >> ";

	// 정렬된 배열 출력
	print(sorted_arr);

	return 0;
}
