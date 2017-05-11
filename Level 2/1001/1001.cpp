#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
int count = 0;
int guess(int n);
int main(){
	int n,num=0;
	scanf("%d", &n);
	if (n > 0 && n < 1001) {
		num = guess(n);
		printf("%d", num);
	}
	system("pause");
	return 0;
}
int guess(int n) {
	if (n == 1)
		return count;
	else if (n % 2 == 0) {
		count++;
		//n = n / 2;
		return guess(n/2);
	}
	else {
		count++;
		//n = (3 * n + 1) / 2;
		return guess((3 * n + 1) / 2);
	}		
}