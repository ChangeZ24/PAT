#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<iostream>
#include<algorithm>
#define MAX 55
using namespace std;

struct BTnode{
	int data;
	struct BTnode* lchild;
    struct BTnode* rchild;
};
int n;
BTnode* create(int post[], int in[], int pl, int pr, int il, int ir) {
	if (pl > pr)
		return NULL;
	BTnode *root = (BTnode *)malloc(sizeof(BTnode));
	root->lchild = NULL;
	root->rchild = NULL;
	root->data = post[pr];
	int a;
	for (a = il;a < ir + 1;a++)
		if (post[pr] == in[a]) 
			break;
	int num = a - il;
	root->lchild = create(post,in,pl, pl + num - 1, il, a - 1);
	root->rchild = create(post, in, pl + num, pr - 1, a + 1, ir);
	//int num = a - il;
	//cout << num;
	//root->lchild = create(pl + 1, pl + num, il, a - 1);
	//root->rchild = create(pl + num + 1, pr, a + 1, ir);
	//cout << "YYY";
	return root;
}
/*void preorder(BTnode *root) {
	if (root != NULL) {
		cout << root->data << "->";
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
*/
void levelorder(BTnode *root) {
	int count = 0;
	int front, rear;
	BTnode *que[33];
	front = rear = 0;
	BTnode *p;
	if (root != NULL) {
		rear = (rear + 1) % 33;
		que[rear] = root;
		while (rear != front) {
			front = (front + 1) % 33;
			p = que[front];
			cout << p->data;
			count++;
			if (count < n)
				cout << " ";
			if (p->lchild != NULL) {
				rear = (rear + 1) % 33;
				que[rear] = p->lchild;
			}
			if (p->rchild != NULL) {
				rear = (rear + 1) % 33;
				que[rear] = p->rchild;
			}
		}
	}
}
int main() {
	int post[MAX], in[MAX];
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
		scanf("%d", &post[i]);
	for (int i = 0;i < n;i++)
		scanf("%d", &in[i]);
	BTnode *r;
	r = create(post, in, 0, n - 1, 0, n - 1);
	//preorder(r);
	//cout << endl;
	levelorder(r);
	system("pause");
	return 0;
}