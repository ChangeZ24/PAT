/*   选择排序
步骤：
a、在未排序序列中找到最小（大）元素，存放到排序序列的起始位置。
b、再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
c、以此类推，直到所有元素均排序完毕。 
时间复杂度：O（n2） 
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
