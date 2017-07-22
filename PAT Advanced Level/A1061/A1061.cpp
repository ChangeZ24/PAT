#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAX 62
using namespace std;
typedef struct{
	char ch[MAX];
	int length;
}str;
int main() {
	str s1,s2,s3,s4;
	char day,hour,min,temp=0;
	char week[7][5]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	gets(s1.ch);
	gets(s2.ch);
	gets(s3.ch);
	gets(s4.ch);
	s1.length=strlen(s1.ch);
	s2.length=strlen(s2.ch);
	s3.length=strlen(s3.ch);
	s4.length=strlen(s4.ch);
	for(int i=0;i<s1.length&&i<s2.length;i++){
		if((s1.ch[i]>='A'&&s1.ch[i]<='G')&&(s1.ch[i]==s2.ch[i])){
			day=s1.ch[i];
			temp=i;
			printf("%s ",week[day-65]);
			break;
		}
	}
	for(int i=temp+1;i<s1.length&&i<s2.length;i++){
		if(s1.ch[i]==s2.ch[i]){
			hour=s1.ch[i];
			if(s1.ch[i]>='0'&&s1.ch[i]<='9'){
				printf("%02d:",hour-48);
				break;
			}
		    else if(s1.ch[i]>='A'&&s1.ch[i]<='N'){
		    	printf("%02d:",hour-65+10);
		        break;
			}
		}
	}
	for(int i=0;i<s3.length&&i<s4.length;i++){
		if((s3.ch[i]>='a'&&s3.ch[i]<='z')||(s3.ch[i]>='A'&&s3.ch[i]<='Z')){
			if(s3.ch[i]==s4.ch[i]){
				if(i>60)
				    i=i-60;
			    printf("%02d",i);
			    break;
			}
		}
	}
	system("pause");
	return 0;
}
