//#include <iostream>
//using namespace std;
#include <stdio.h> 
int main(){
	int a,b;
	int sum,t; // sum:½á¹û t:ÔÝ´æ 
	char d[20],k[20];
	char g;
	bool flag = false;
	int i = 0;

	while(scanf("%d %d",&a,&b)!=EOF){
		flag = false;
		int count = 0;
		i = 0;
		sum = a+b;
		if (sum==0){
			printf("0");
			
		}
			
		if(sum<0) {
			flag = true;
			sum=-sum; 
		}
		
		while(sum!=0){
			
			if(count==3){
				d[i] = ',';
				i++;
				count=0;
			}
			t=sum%10;
			sprintf(&g,"%d",t); 
			d[i] = g; 
			i++;
			sum=sum/10;
			count++;
		}
		int length = i--;
		for(int l=0;l<=length;i--,l++)
			k[l] = d[i];
		if(flag) printf("-");
		for(int j=0;j<length;j++) {
			
			printf("%c",k[j]);
			
		}

	} 
	return 0;
}
