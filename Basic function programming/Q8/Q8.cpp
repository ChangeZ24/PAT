#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
				
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */

int Count_Digit ( const int N, const int D ){
	int n,times=0;
	n=N;
	if(n<0)
	    n=-n;
    if(n==0&&D==0)
        return 1;
	else{
		while(n!=0){
		if(n%10==D){
			times++;
			n=n/10;
		}
		else
		    n=n/10;
	    }
	    return times;
	}	
} 