#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define CLK_TCK 100
int main(){
	int C1, C2;
	int time;
	scanf("%d%d", &C1, &C2);
	if (C1 > C2) {
		int temp = C1;
		C1 = C2;
		C2 = temp;
	}
	time = (C2 - C1) / CLK_TCK;
	if ((C2 - C1) % CLK_TCK >= 50)
		time++;
	printf("%02d:%02d:%02d", time / 3600, time % 3600 / 60, time % 60);
	system("pause");
	return 0;
}