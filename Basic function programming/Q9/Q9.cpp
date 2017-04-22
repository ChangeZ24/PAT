#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
    int N;
				
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

void Print_Factorial ( const int N ){
	int fac[2568]={0};
	int temp=0,n=0,k=1;
	fac[0]=1;
	for(int i=2;i<=N;i++){
		for(int j=0;j<k;j++){
		temp=fac[j]*i+n;
		fac[j]=temp%10;
		n=temp/10;
		if(n&&j==k-1)
		    k++;
			}
	}
    for(int i=k-1;i>=0;i--){
    	if(N>=0&&N<=1000)
    	    printf("%d",fac[i]);
	    else
	        printf("Invaild input");

	}	
} 
