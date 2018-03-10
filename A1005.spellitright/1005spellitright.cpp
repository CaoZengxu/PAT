#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main(){
	char N[101];
	int flag = 1;
	
	//cin>>N;
	scanf("%s",&N);
	int len = strlen(N);
//	cout<<"len:"<<len<<endl;
//	cout<<N;
	string c[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

	int sum = 0; 
	for(int i=0;i<len;i++)
		sum += N[i] - '0';
//	cout<<"sum:"<<sum<<endl; 
	
	int sumc = sum;
	
	while(sumc>=10){

		sumc = sumc/10;	
		flag++;
	}
//	cout<<"flag:"<<flag<<endl;
	sumc = 1;
	while(flag>1){
		sumc = sumc*10;
	//	cout<<"sumc:"<<sumc<<endl;
		flag--;
	}
	int t;
//	cout<<"sumc:"<<sumc<<endl;
	while(sum>=0&&sumc>0){
		//cout<<"sum:"<<sum<<" sumc:"<<sumc<<endl;
		if(sumc>0){
			t = sum/sumc;
			cout<<c[t];	
			sum = sum%sumc;
		}
		
		
	//	cout<<"t:"<<t<<endl;
		sumc = sumc/10;
		
		
		if(sumc>0)
			cout<<" ";	
	}
//	system("pause");
	return 0;
}
