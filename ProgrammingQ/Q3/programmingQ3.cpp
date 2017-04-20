#include<iostream>
using namespace std;

int main(){
	int num=0,out=0;
	cin >> num;
	if(num%10!=0){
		out=num%10*100+(num%100-num%10)+num/100;
		cout << out;
	}
	else{
		out=num%100+num/100;
		cout << out;
	}
	return 0;	
} 