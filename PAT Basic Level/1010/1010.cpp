#include<cstdio>
#include<cstdlib>
#include<cstring>
/*��ƺ�����һԪ����ʽ�ĵ�������ע��xn��nΪ��������һ�׵���Ϊn*xn-1����
�����ʽ����ָ���ݽ���ʽ�������ʽ������ϵ����ָ��������ֵ��Ϊ������1000�������������ּ��Կո�ָ���
�����ʽ������������ͬ�ĸ�ʽ�����������ʽ�������ϵ����ָ�������ּ��Կո�ָ�������β�����ж���ո�
ע�⡰�����ʽ����ָ����ϵ������0�����Ǳ�ʾΪ��0 0����
����������
3 4 -5 2 6 1 -2 0
���������
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
		printf("0 0");//�����ʽ
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
