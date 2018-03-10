#include <stdio.h>
#include <iostream>
#include<iomanip>
using namespace std;
#define max 10001

//≤‚ ‘
int main(){
	int k1,k2,N;
	int count = 0;
	double a[max],aN;
	for(int j=0;j<max;j++){
		a[j]=0;
	}
	//scanf("%d",&k1);
	cin>>k1;
	for(int i=0;i<k1;i++){
		//scanf("%d %lf",&N,&aN);
		cin>>N>>aN;
		a[N] = aN;
	}	
	scanf("%d",&k2);
	for(int i=0;i<k2;i++){
		//scanf("%d %lf",&N,&aN);
		cin>>N>>aN;
		//if(a[N]==-1){
		//	a[N]++;	
	//	}
		a[N] += aN ;
	}	
	for (int i=max-1;i>=0;i--){
		if(a[i]!=0)
			count++;
	}
	//printf("%d",count);
	cout<<count;
//	if(count==0)
	//	printf(" 0 0");
	for (int i=max-1;i>=0;i--){
		if(a[i]!=0){
			cout<<fixed<<setprecision(1);  
			cout<<" "<<i<<" "<<a[i];
			/*printf(" ");
			printf("%d",i);
			printf(" ");
			printf("%0.1lf",a[i]);*/
		}
				
	}
	printf("\n");
	return 0;
}
