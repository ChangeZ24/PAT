/*   ѡ������
���裺
a����δ�����������ҵ���С����Ԫ�أ���ŵ��������е���ʼλ�á�
b���ٴ�ʣ��δ����Ԫ���м���Ѱ����С����Ԫ�أ�Ȼ��ŵ����������е�ĩβ��
c���Դ����ƣ�ֱ������Ԫ�ؾ�������ϡ� 
ʱ�临�Ӷȣ�O��n2�� 
*/
#include<stdio.h>
#define MAX 10

void select(int a[],int n);

int main(){
	int a[MAX];
	int n=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	    scanf("%d",&a[i]);
    select(a,n);
    for(int i=0;i<n;i++)
        printf("%d",a[i]);
    return 0;
}

void swap(int *a,int *b){
	int temp=*a;
    *a=*b;
    *b=temp;
}
void select(int a[],int n){
	int min=0;
	for(int i=0;i<n;i++){
		min=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min])
			    min=j;
		}
		swap(&a[min],&a[i]);
	}	    
}
