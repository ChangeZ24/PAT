#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;
				
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

/* 你的代码将被嵌在这里 */
int IsTheNumber ( const int N ){
	int m=sqrt(N),n=N,i=0;
	int a[10]={0};
	if(m*m==N){
		while(n!=0){
			i=n%10;
		    n=n/10;
		    a[i]++;
		}
		for(i=0;i<=10;i++){
			if(a[i]>=2){
				return 1;
				break;
			}
		}
		return 0;	
	}
	else
	    return 0;
}
