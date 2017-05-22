#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<cstring>

int main(){
	char str[90];
	char words[90][90];
	int len, r = 0, h = 0;;
	gets(str);
	len = strlen(str);
	for (int i = 0;i < len;i++) {
		if (str[i] != ' ') {
			words[r][h++] = str[i];
		}
		else {
			words[r][h] = '\0';
			r++;
			h = 0;
		}
	}
	for (int i = r;i >= 0;i--) {
		printf("%s", words[i]);
		if (i > 0)
			printf(" ");
	}
	return 0;
}