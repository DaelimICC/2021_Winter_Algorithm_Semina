#include <iostream>
#include <vector>

using namespace std;

// Node ����
struct node {
	vector<int> arr;
	struct node* nxt[10];
};

// ��� ������ ���� �Լ�
struct node* new_node(void)
{
	struct node* tempNode = new node;

	for (int i = 0; i < 10; i++) {
		tempNode->nxt[i] = NULL;
	}

	// ������ ��� ��ȯ
	return tempNode;
}

// MSD ������
void msd_sort(struct node* root, int exp,
	vector<int>& sorted_arr)
{
	if (exp <= 0) {
		return;
	}

	int j;

	// ��Ŷ �迭 ����
	for (int i = 0;
		i < root->arr.size();
		i++) {

		// �ֻ��� ���� �� ���
		j = (root->arr[i] / exp) % 10;

		// j�ε����� �ش��ϴ� �迭�� ���� ���, ����
		if (root->nxt[j] == NULL) {
			root->nxt[j] = new_node();
		}

		root->nxt[j]->arr.push_back(
			root->arr[i]);
	}

	// �ڽ� ��忡 ���� ����
	for (int i = 0; i < 10; i++) {

		if (root->nxt[i] != NULL) {

			if (root->nxt[i]->arr.size()
	> 1) {
				// ���� �ݺ�
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

// MSD ������ ���� �ִ� ���� ��ȯ
int get_max_exp(vector<int> arr)
{
	// �ִ� ���� ���� Ȯ��
	int mx = arr[0];

	// �ִ� ã��
	for (int index = 1; index < arr.size(); index++) {
		if (arr[index] > mx) {
			mx = arr[index];
		}
	}

	// �ִ� ������ ���� ���� Ȯ��
	int exp = 1;

	while (mx > 10) {
		mx /= 10;
		exp *= 10;
	}

	// �ִ� ������ ��ȯ
	return exp;
}

// �迭 ���
void print(vector<int> arr)
{
	for (int index = 0; index < arr.size(); index++)
		cout << arr[index] << " ";

	cout << endl;
}

// ���� �ڵ��
int main()
{
	// ��Ʈ ��� ����
	struct node* root = new_node();

	// ���ĵ��� ���� �迭 ����
	root->arr.insert(root->arr.end(),
		{ 888, 222, 333, 444, 555, 111, 999, 1203, 32, 9 });

	cout << "������ �迭 >> ";

	// ���� �� �迭 ���
	print(root->arr);

	// ���� ���� ����
	int exp = get_max_exp(root->arr);

	// ������ �迭 ����
	vector<int> sorted_arr;

	// ����
	msd_sort(root, exp, sorted_arr);

	cout << "���� �迭 >> ";

	// ���ĵ� �迭 ���
	print(sorted_arr);

	return 0;
}
