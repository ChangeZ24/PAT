#include <stdio.h>

#define MAXN 10

double f( int n, double a[], double x );

int main()
{
    int n, i;
    double a[MAXN], x;
				
    scanf("%d %lf", &n, &x);
    for ( i=0; i<=n; i++ )
        scanf("%lf", &a[i]);
    printf("%.1f\n", f(n, a, x));
    return 0;
}
// º¯Êý
/*
double f(int n, double a[], double x){
	double sum=0,square=0;
	for(int i=0;i<=n;i++){
		square=1.0;
		for(int j=i;j>0;j--)
		    square=square*x;
        sum=sum+a[i]*square;
	}
	return sum;
} 
*/
double f(int n, double a[], double x){
	double sum=a[0],square=1.0;
	for(int i=1;i<=n;i++){
	    square=square*x;
        sum=sum+a[i]*square;
	}
	return sum;
} 