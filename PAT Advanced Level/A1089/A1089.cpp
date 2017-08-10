#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<iostream>
#include<algorithm>
#define MAX 104
using namespace std;
int num;

bool issame(int A[], int B[]) {
	for (int i = 0;i < num;i++) {
		if (A[i] != B[i])
			return false;
	} 
	return true;
}
void mergesort(int A[], int B[]) {
	bool flag1 = false;
	for (int step = 2;(step / 2) <= num;step *= 2) {
		if (step != 2 && issame(A, B)) 
			flag1 = true;
		for (int i = 0;i < num;i += step)
			sort(A + i, A + min(i + step, num));
		if (flag1 == true) {
			for (int i = 0;i < num;i++) {
				printf("%d", A[i]);
				if (i < num - 1)
					cout << " ";
			}
			return;
		}
	}
}
int main() {
    int temp;
	bool flag = true;
	int N[MAX],M[MAX];
	scanf("%d", &num);
	for (int i = 0;i < num;i++)
		scanf("%d", &N[i]);
	for (int i = 0;i < num;i++) 
		scanf("%d", &M[i]);
	for (int i = 1;i < num;i++) {
		if (M[i] < M[i - 1]) {
			temp = i;
			break;
		}
	}
	for (int i = temp;i < num;i++) {
		if (M[i] != N[i]) {
			flag = false;//¹é²¢
			break;
		}
	}
	if (flag == true) {
		printf("Insertion Sort\n");
		sort(N, N + temp + 1);
		for (int i = 0;i < num;i++) {
			printf("%d", N[i]);
			if (i < num - 1)
				cout << " ";
		}	
	}
	else {
		printf("Merge Sort\n");
		int C[MAX];
		for (int i = 0;i < num;i++)
			C[i] = N[i];
		mergesort(C, M);

	}
	system("pause");
	return 0;
}