#include<iostream>
//#include<fstream>
using namespace std;
typedef struct {
	string ID;
	int time;
}person;
int calculateT(char time[]){
	int t = 0;
	t = ((time[0] - '0')*10+time[1] - '0')*60*60+((time[3] - '0')*10+time[4] - '0')*60+(time[6]-'0')*10 + time[7] - '0';
	return t;
}
int main(){
//	ifstream in("in.txt");
	person unlock,lock;
	string ID;
	char inTime[8],outTime[8];
	int N;
	int pintime,pouttime;
	cin>>N;
	//scanf("%s",&ID,&inTime,&outTime);
	cin>>ID>>inTime>>outTime;
	unlock.ID = lock.ID = ID;
	unlock.time = calculateT(inTime);
	lock.time = calculateT(outTime);
	for(int i=0;i<N-1;i++){
		//scanf("%s",&ID,&inTime,&outTime);
		cin>>ID>>inTime>>outTime;
		pintime = calculateT(inTime);
		pouttime = calculateT(outTime);
		if(unlock.time>pintime){
			unlock.ID = ID;
			unlock.time = pintime; 
		}
		if(lock.time<pouttime){
			lock.ID = ID;
			lock.time = pouttime;
		}		
	}
	cout<<unlock.ID<<" "<<lock.ID;
	//system("pause");
	return 0;
} 
