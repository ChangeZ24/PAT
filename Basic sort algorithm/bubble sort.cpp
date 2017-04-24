/*   冒泡排序
冒泡排序算法的运作如下：
a、比较相邻的元素。如果第一个比第二个大，就交换他们两个。
b、对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
c、针对所有的元素重复以上的步骤，除了最后一个。
d、持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。 

时间复杂度为O（n2） 

问题：
函数传参时，值传参
eg：void swap(int a,int b){
	int temp=a;
    a=b;
    b=temp;
} 
int main(){
    int x=2,y=3;
	swap(x,y);
	return 0; 
}
此时对于main中swap来说，进行过程为：
a=x,b=y;
swap(a,b);
只是将x,y的值传入函数swap，对于x,y没有任何改变。 
故对于main函数中的x,y并没有任何交换。 

而引用传参与地址传递则是对x,y的修改。只是两种对于形参a,b的修改不同。 
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