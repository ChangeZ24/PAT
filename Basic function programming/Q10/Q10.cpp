#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

/* 你的代码将被嵌在这里 */
void swap(ElementType *a,ElementType *b){
	ElementType x=*a;
	*a=*b;
	*b=x;
}
ElementType searchP(ElementType A[],int left,int right){
	int middle=(left+right)/2;
	if(A[left]>A[middle])
	    swap(&A[left],&A[middle]);
    if(A[left]>A[right])
        swap(&A[left],&A[right]);
    if(A[right]<A[middle])
        swap(&A[middle],&A[right]);
    swap(&A[middle],&A[right-1]);
    return A[right-1];
}
void quicksort(ElementType A[],int left,int right){
	if(left>=right) 
		return ;
	ElementType p=searchP(A,left,right);
	int i=left,j=right-1;
	while(1){
		while(A[++i]<p){}
		while(A[--j]>p){}
		if(i<j)
		    swap(&A[i],&A[j]);
        else
            break;
	}
	swap(&A[i],&A[right-1]);
	quicksort(A,left,i-1);
	quicksort(A,i+1,right);
}
ElementType Median( ElementType A[], int N ){
	quicksort(A,0,N-1);
	return A[N/2];	
} 
