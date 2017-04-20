#include<iostream>
using namespace std;
int main(){
	int start=0,goes=0,min=0; 
	int now_min=0,now_hour=0;
	cin >> start >> goes;
    min=start/1000*600+start%1000/100*60+start%100;
    //if(goes>=0){
    	min += goes;
    	now_hour=min/60;
    	now_min=min%60;
    	if(now_min==0){
	    	cout << now_hour << now_min << now_min;
	    }
	    else{
    		cout<< now_hour << now_min;
    	}
    //}
    //else{
    //	min += goes;
    	
    //}
    return 0;
} 