/*   ð������
ð�������㷨���������£�
a���Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������
b����ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԡ��ⲽ���������Ԫ�ػ�����������
c��������е�Ԫ���ظ����ϵĲ��裬�������һ����
d������ÿ�ζ�Խ��Խ�ٵ�Ԫ���ظ�����Ĳ��裬ֱ��û���κ�һ��������Ҫ�Ƚϡ� 

ʱ�临�Ӷ�ΪO��n2�� 

���⣺
��������ʱ��ֵ����
eg��void swap(int a,int b){
	int temp=a;
    a=b;
    b=temp;
} 
int main(){
    int x=2,y=3;
	swap(x,y);
	return 0; 
}
��ʱ����main��swap��˵�����й���Ϊ��
a=x,b=y;
swap(a,b);
ֻ�ǽ�x,y��ֵ���뺯��swap������x,yû���κθı䡣 
�ʶ���main�����е�x,y��û���κν����� 

�����ô������ַ�������Ƕ�x,y���޸ġ�ֻ�����ֶ����β�a,b���޸Ĳ�ͬ�� 
*/
#include<stdio.h>
#define MAX 10
void bubble(int a[],int n);

int main(){
	int a[MAX];
	int n=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	    scanf("%d",&a[i]);
    bubble(a,n);
    for(int i=0;i<n;i++)
        printf("%d",a[i]);
    return 0;
}

void swap(int *a,int *b){
	int temp=*a;
    *a=*b;
    *b=temp;
}
void bubble(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int k=1;k<n-i;k++){
    		if(a[k-1]>a[k])
			    swap(&a[k-1],&a[k]);
    	}
	}    
}