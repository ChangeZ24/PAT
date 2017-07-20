#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAX 1002
using namespace std;

struct student {
	char no[11];
	char name[11];
	char gender;
	int grade;
};
int main() {
	int N = 0;
	student s[MAX];
	student boy,girl;
	boy.grade = 100;
	girl.grade = 0;
	int temp1 = 0, temp2 = 0;
	bool b = false, g = false;
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%s%s%s%d", &s[i].name, &s[i].gender, &s[i].no, &s[i].grade);
		if (s[i].gender == 'M') {
			b = true;
			temp1 = s[i].grade;
			if (temp1 < boy.grade)
				boy = s[i];
		}
		if (s[i].gender == 'F') {
			g = true;
			temp2 = s[i].grade;
			if (temp2 > girl.grade)
				girl = s[i];
		}	
	}
	if (g == false)
		printf("Absent\n");
	else
		printf("%s %s\n", girl.name, girl.no);
	if (b == false) 
		printf("Absent\n");
	else
		printf("%s %s\n", boy.name, boy.no);
	if (b == false || g == false) 
		printf("NA\n");
	else 
		printf("%d\n", girl.grade - boy.grade);
	system("pause");
	return 0;
}