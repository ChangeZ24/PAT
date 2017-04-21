#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int i=0;
	double d1=0,d2=0;
	char c;
	cin >> d1 >> i >> c >> d2;
	cout << c << " " << i << " " ;
	cout << setiosflags(ios::fixed)<< setprecision(2)<< d1 << " " << d2;
	return 0;
}