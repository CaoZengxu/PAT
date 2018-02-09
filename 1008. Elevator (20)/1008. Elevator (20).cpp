#include<iostream>
using namespace std;
int main(){
	int N,currentfloor = 0,nextfloor,time = 0;
	int change = 0;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>nextfloor;
		change = nextfloor - currentfloor;
		if(change>0){
			time += change*6 + 5;
		}else{
			time += -change*4 + 5;
		}
		currentfloor = nextfloor;
	}
	cout<<time;
	//system("pause");
	return 0;
} 
