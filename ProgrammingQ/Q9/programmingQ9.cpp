#include<iostream>
using namespace std;
int main(){
	int A=0,B=0,C=0;
	cin >> A >> B >> C;
	if(A!=B&&A!=C)
	    cout << A;
	else if(B!=A&&B!=C)
	    cout << B;
    else 
        cout << C;
    return 0;	    
}