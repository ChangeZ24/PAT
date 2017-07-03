#include<cstdio>
int main(){
	int a[54]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,
	           31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54};
	int b[54],n[54];
	char c[5]={'S','H','C','D','J'};
	int num,x=0;
	scanf("%d",&num);
	for(int i=0;i<54;i++){
		scanf("%d",&b[i]);
	}
	while(num>0){
		for(int i=0;i<54;i++){
			x=b[i];
			n[--x]=a[i];
		} 
		for(int i=0;i<54;i++)
		    a[i]=n[i];
		num--;
	}
	for(int i=0;i<53;i++){
		if(n[i]/13==0&&n[i]%13!=0)
			printf("S%d ",n[i]%13);
		else if(n[i]/13==1&&n[i]%13==0)
		    printf("S13 ");
		else if(n[i]/13==1&&n[i]%13!=0)
		    printf("H%d ",n[i]%13);
		else if(n[i]/13==2&&n[i]%13==0)
		    printf("H13 ");
		else if(n[i]/13==2&&n[i]%13!=0)
		    printf("C%d ",n[i]%13);
		else if(n[i]/13==3&&n[i]%13==0)
		    printf("C13 ");
		else if(n[i]/13==3&&n[i]%13!=0)
		    printf("D%d ",n[i]%13);
		else if(n[i]/13==4&&n[i]%13==0)
		    printf("D13 ");
		else if(n[i]/13==4&&n[i]%13!=0)
		    printf("J%d ",n[i]%13);
		else
		    printf("error");
	}
	x=n[53]/13;
	if(n[53]%13==0)
	    printf("%c13",c[--x]);
	else
	    printf("%c%d",c[x],n[53]%13);
	return 0;
} 

