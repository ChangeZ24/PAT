#include<cstdio>
#include<cstdlib>
#include<cstring>
/*设计函数求一元多项式的导数。（注：xn（n为整数）的一阶导数为n*xn-1。）
输入格式：以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。
输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。
注意“零多项式”的指数和系数都是0，但是表示为“0 0”。
输入样例：
3 4 -5 2 6 1 -2 0
输出样例：
12 3 -10 1 6 0*/
int main(){
	int count = 0, n, a;
	int num[1010] = { 0 };
	while (scanf("%d%d", &a, &n) != EOF) {
		num[n] = a;
	}
	num[0] = 0;
	for (int i = 1;i < 1001;i++) {
		num[i - 1] = num[i] * i;
		num[i] = 0;
		if (num[i - 1] != 0)
			count++;
	}
	if (count == 0)
		printf("0 0");//零多项式
	else {
		for (int i = 1000;i >= 0;i--) {
			if(num[i]!=0){
				printf("%d %d", num[i], i);
			    count--;
			    if (count != 0)
				    printf(" ");
			}	
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
