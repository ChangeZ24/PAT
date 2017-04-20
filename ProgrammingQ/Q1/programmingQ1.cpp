#include<iostream>
#include<math.h>
using namespace std;
 
int main(){
    int cm=0;
	double foot=0,inch=0;
	cin >> cm;
	foot=cm/100.0/0.3048;
	inch=(foot-floor(foot))*12;
	cout << (int)foot << " " << (int)inch; 	
	return 0;
}