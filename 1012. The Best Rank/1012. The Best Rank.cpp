#include<iostream>
#include<cstring>
//#include<fstream>
using namespace std;
//#define cin in

//0-C,1-M,2-E,3-A
typedef struct Student{
	string ID;
	int grades[4],rank[4];
	int bestP;
	Student *ranklist[4];
}Student;

char pro[] = {'A','C','M','E',};
int main(){
	//ifstream in("in.txt");
	int N,M;
	cin>>N>>M;
	Student stu;
	Student *stuList = &stu;
	
	for(int i=0;i<4;i++){
		stuList->rank[i] = 1;
		stuList->grades[i] = 0;
		stuList->ranklist[i] = NULL; 
	}
		
//	stuList->ID = "headd";
	string query[M];
	Student *pre;
	
	for(int i=0;i<N;i++){
		
		Student *student = new Student;
		//strcpy(student->ID,"head");
	 	student->ID = "head";
		for(int k=0;k<4;k++){
			student->ranklist[k]=NULL;
			
		}
		pre = stuList;
		int cuRank = 0;
		cin>>student->ID>>student->grades[1];
		cin>>student->grades[2];
		cin>>student->grades[3];
		student->grades[0] = (student->grades[3]+student->grades[1]+student->grades[2])/3;
		
		for(int j=0;j<4;j++){
			pre = stuList;
			while(pre->ranklist[j]!=NULL&&pre->ranklist[j]->grades[j]<student->grades[j]){
			
				pre->rank[j]++;
				pre = pre->ranklist[j];
			//	cout<<"while1" <<endl;
			}
			
			student->ranklist[j] = pre->ranklist[j];
			pre->ranklist[j] = student;
			student->rank[j] = pre->rank[j];
			pre->rank[j]++;
			/*	
			if(student->ranklist[j]&&student->ranklist[j]->grades[j]==student->grades[j]){
				Student *op = stuList;
				while(op!=student){
					op->rank[j]--;
					op = op->ranklist[j];
				}
				op->rank[j]--;
			}
			*/	
		}

	}
		
	for(int i=0;i<M;i++){
		cin>>query[i];
	}
	pre = stuList;

	while(pre!=NULL){

		int bestrank = N+1;
		for(int i=0;i<4;i++){
			if(pre->rank[i]<bestrank){
				bestrank = pre->rank[i];
				pre->bestP = i;
			}
		}
		pre = pre->ranklist[0];
	}
	
	bool flag=false;
	for(int i=0;i<M;i++){
	
		pre = stuList;
		pre = pre->ranklist[0];

		while(pre!=NULL){
		//	cout<<"while3" <<endl;
			flag = false;
			if(pre->ID==query[i]){
				cout<<pre->rank[pre->bestP]<<" "<<pro[pre->bestP]<<endl; 
				flag = true;
				break;
			}
		

			pre = pre->ranklist[0];
		}
		if(!flag)
			cout<<"N/A"<<endl;
	}
	getchar();
	getchar();
	//system("pause");
	return 0;
}
