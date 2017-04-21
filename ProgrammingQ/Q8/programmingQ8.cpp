#include<iostream>
using namespace std;
int main(){
	int speed=0;
	cin >> speed;
	if(speed>=0&&speed<501){
		if(speed > 60)
		    cout << "Speed: " << speed << " - Speeding" ;
        else
            cout << "Speed: " << speed << " - OK"; 
	}
	return 0;
}