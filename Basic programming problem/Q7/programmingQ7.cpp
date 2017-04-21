#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main(){
	string time;
	int hour=0;
	cin >> time;
	hour=atoi(time.substr(0,2).c_str());
	if(hour >= 12&& hour <= 24){
		if(hour == 12)
		    cout << hour << time.substr(2,3) << " PM";
		else
		    cout << hour-12 << time.substr(2,3) << " PM";   
	}
	    
    else{
    	if(hour < 10)
    	    cout << hour << time.substr(1,3) << " AM";
	    else
	        cout << hour << time.substr(2,3) << " AM";
    }
        
	return 0;
}