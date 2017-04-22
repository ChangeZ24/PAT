#include <stdio.h>

int Factorial( const int N );

int main()
{
    int N, NF;
				
    scanf("%d", &N);
    NF = Factorial(N);
    if (NF)  printf("%d! = %d\n", N, NF);
    else printf("Invalid input\n");

    return 0;
}

/* 你的代码将被嵌在这里 */

int Factorial( const int N ){
	int fac=1;
	if(N>=0&&N<=12){
		for(int j=N;j>0;j--)
			fac=fac*j;
		return fac;
	}
	else
	    return 0;
} 