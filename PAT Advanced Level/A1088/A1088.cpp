#include<cstdio>
#include<cstdlib>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>
#define MAX 100004
#define MINF 1000000000;
using namespace std;

typedef struct {
	long long numerator;
	long long denominator;
}ratnum;
long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a%b);
}
ratnum simpy(ratnum result) {
	if (result.denominator<0) {
		result.numerator *= -1;
		result.denominator *= -1;
	}
	if (result.numerator == 0)
		result.denominator = 1;
	else {
		long long g = gcd(abs(result.denominator), abs(result.numerator));
		result.denominator /= g;
		result.numerator /= g;
	}
	return result;
}
void show(ratnum result) {
	result = simpy(result);
	if (result.numerator < 0)
		cout << "(";
	if (result.denominator == 1)
		cout << result.numerator;
	else {
		if (abs(result.numerator) > result.denominator)
			cout << result.numerator / result.denominator << " " << abs(result.numerator) % result.denominator << "/" << result.denominator;
		else
			cout << result.numerator << "/" << result.denominator;
	}
	if (result.numerator < 0)
		cout << ")";
}
void add(ratnum a, ratnum b) {
	ratnum result;
	result.denominator = a.denominator*b.denominator;
	result.numerator = a.numerator*b.denominator + b.numerator*a.denominator;
	simpy(result);
	show(a);
	cout << " + ";
	show(b);
	cout << " = ";
	show(result);
	cout << endl;
}
void sub(ratnum a, ratnum b) {
	ratnum result;
	result.denominator = a.denominator*b.denominator;
	result.numerator = a.numerator*b.denominator - b.numerator*a.denominator;
	simpy(result);
	show(a);
	cout << " - ";
	show(b);
	cout << " = ";
	show(result);
	cout << endl;
}
void mul(ratnum a, ratnum b) {
	ratnum result;
	result.denominator = a.denominator*b.denominator;
	result.numerator = a.numerator*b.numerator;
	simpy(result);
	show(a);
	cout << " * ";
	show(b);
	cout << " = ";
	show(result);
	cout << endl;
}
void div(ratnum a, ratnum b) {
	ratnum result;
	result.denominator = a.denominator*b.numerator;
	result.numerator = a.numerator*b.denominator;
	simpy(result);
	show(a);
	cout << " / ";
	show(b);
	cout << " = ";
	if (b.numerator == 0)
		cout << "Inf";
	else
		show(result);
	cout << endl;
}
int main() {
	ratnum a, b;
	scanf("%lld/%lld %lld/%lld", &a.numerator, &a.denominator, &b.numerator, &b.denominator);
	add(a, b);
	sub(a, b);
	mul(a, b);
	div(a, b);
	//cout << a.numerator << "/" << a.denominator << endl;
	//cout << b.numerator << "/" << b.denominator << endl;
	system("pause");
	return 0;
}