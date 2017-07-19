#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAX 1002
using namespace std;
struct Time {
	int hour;
	int min;
	int sec;
};
struct student {
	char no[16];
	Time in_time;
	Time out_time;
};
bool cmp(Time a, Time b);
int main() {
	int N, in_min = 0, out_max = 0;
	student s[MAX];
	student in, out;
	in.in_time.hour = 24;
	in.in_time.min = 60;
	in.in_time.sec = 60;
	out.out_time.hour = 0;
	out.out_time.min = 0;
	out.out_time.sec = 0;
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%s%d:%d:%d%d:%d:%d", s[i].no, &s[i].in_time.hour, &s[i].in_time.min, &s[i].in_time.sec, &s[i].out_time.hour, &s[i].out_time.min, &s[i].out_time.sec);
	}
	for (int i = 0;i < N;i++) {
		if (cmp(s[i].in_time, in.in_time) == false)
			in = s[i];
		if (cmp(s[i].out_time, out.out_time) == true)
			out = s[i];
	}
	printf("%s %s", in.no, out.no);
	system("pause");
	return 0;
}
bool cmp(Time a, Time b) {
	if (a.hour != b.hour)
		return a.hour > b.hour;
	if (a.min != b.min)
		return a.min > b.min;
	return a.sec > b.sec;

}