#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAX 1002
using namespace std;
typedef struct {
	double w;
	double t;
	double l;
}odds;
typedef struct {
	char result;
	double odd;
}output;
int main() {
	odds o[3];
	output out[3];
	double profit = 0.0;
	double m = 0.0;//max
	for (int i = 0;i < 3;i++)
		scanf("%lf%lf%lf", &o[i].w, &o[i].t, &o[i].l);
	for (int i = 0;i < 3;i++) {
		m = max(o[i].w, o[i].t);
		if (m < o[i].l)
			m = o[i].l;
		out[i].odd = m;
		if (out[i].odd == o[i].w)
			out[i].result = 'W';
		else if (out[i].odd == o[i].t)
			out[i].result = 'T';
		else
			out[i].result = 'L';
	}
	profit = (out[0].odd*out[1].odd*out[2].odd*0.65 - 1) * 2;
	printf("%c %c %c %.2lf", out[0].result, out[1].result, out[2].result, profit);
	return 0;
}

