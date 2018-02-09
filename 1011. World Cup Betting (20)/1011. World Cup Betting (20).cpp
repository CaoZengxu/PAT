#include<iostream>
#include<iomanip> 
using namespace std;
int main(){
	double m1[3],m2[3],m3[3];
	char buy[] = {'W','T','L'};
	char result[3];
	double profit,t = 0;
	int b1 = 0,b2 = 0,b3 = 0;
	for(int i=0;i<3;i++){
		cin>>m1[i];
		if(m1[i]>t){
			b1 = i;
			t = m1[i];
		}
	}
	t = 0;
	for(int i=0;i<3;i++){
		cin>>m2[i]; 
		if(m2[i]>t){
			b2 = i;
			t = m2[i];
		}
	}
	t = 0;
	for(int i=0;i<3;i++){
		cin>>m3[i];
		if(m3[i]>t){
			b3 = i;
			t = m3[i];
		}
	}
	cout<<fixed<<setprecision(2);
	cout<<buy[b1]<<" "<<buy[b2]<<" "<<buy[b3]<<" "<<(m1[b1]*m2[b2]*m3[b3]*0.65-1)*2+0.0005;
	system("pause");
	return 0;
}
