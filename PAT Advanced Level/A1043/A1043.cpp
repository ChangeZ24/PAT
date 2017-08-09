#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<iostream>
#include<algorithm>
#define MAX 1010
using namespace std;

struct BTnode{
	int data;
	struct BTnode* lchild;
    struct BTnode* rchild;
};
int n, type = 0;
int pre[MAX];
void BSTinsert(BTnode *&bt, int key) {
	int rootkey;
	if (bt == NULL) {
		bt = (BTnode*)malloc(sizeof(BTnode));
		bt->lchild = NULL;
		bt->rchild = NULL;
		bt->data = key;
	}
	else {
		rootkey = bt->data;
		if (type == 0) {
			if (key >= rootkey)
				BSTinsert(bt->rchild, key);
			else
				BSTinsert(bt->lchild, key);
		}
		else {
			if (key >= rootkey)
				BSTinsert(bt->lchild, key);
			else
				BSTinsert(bt->rchild, key);
		}
	}
}
int num = 0;
void postorder(BTnode *root) {
	if (root != NULL) {
		postorder(root->lchild);
		postorder(root->rchild);
		cout << root->data;
		num++;
		if (num < n)
			cout << " ";
	}
	else
		return;
}
void create(BTnode *&bt, int key[], int n) {
	bt = NULL;
	for (int i = 0;i < n;i++)
		BSTinsert(bt, key[i]);
}
int main() {
	bool flag = true;
	BTnode *bst;
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
		scanf("%d", &pre[i]);
	int r = pre[0];
	if (pre[1] >= r) {
		type = 1;
		for (int i = 1;i < n - 1;i++) {
			if (pre[i] < r&&pre[i + 1] >= r) {
				flag = false;
				break;
			}
		}
	}
	else {
		for (int i = 1;i < n - 1;i++) {
			if (pre[i] >= r&&pre[i + 1] < r) {
				flag = false;
				break;
			}
		}
	}
	if (flag == false)
		cout << "NO";
	else {
		cout << "YES" << endl;
		create(bst, pre, n);
		postorder(bst);
	}
	system("pause");
	return 0;
}