#include<iostream>
//#include<stdlib>   
#include<cmath>
#include<iomanip>
//#include<fstream>
using namespace std;
#define max 10000

#define in cin
typedef struct{
	int e;
	double a;
}exponent;
typedef long long LL;
double round(double number, unsigned int bits) {
    double integerPart = (double)floor(number);
    number -= integerPart;
    for (unsigned int i = 0; i < bits; ++i)
        number *= 10;
   // cout<<"number:"<<number+0.5<<endl;
    number = number + 0.5;
   // number = (int)(number);
    //cout<<"number:"<<number<<endl;
    for (unsigned int i = 0; i < bits; ++i)
        number /= 10;
    //cout<<"number:"<<number<<endl;
    //cout<<"integer:"<<integerPart<<endl;
    //cout<<(integerPart + number)<<endl;
    return (double)integerPart +(double) number;
}

int main(){
/*	double io =  977087.45;
	double p=round(io,1);
	cout<<fixed<<setprecision(1); 
	 cout<<p<<endl;
	 */
//	ifstream in("in.txt");
	int K1,K2;
	int N;
	double a;
	int N1[max],N2[max];
	for(int i=0;i<max;i++){
		N1[i] = 0;
		N2[i] = 0;;
	}
	double result[max];
	int count = 0; 
	for(int i=0;i<max;i++){
		result[i] = -9999;
	}
	exponent a1[10],a2[10];
	in>>K1;
	for(int i=1;i<=K1;i++){
		in>>N;
		in>>a;
		N1[N] = a;
		a1[i].a = a;
		a1[i].e = N;
	}
	in>>K2;
	for(int i=1;i<=K2;i++){
		in>>N;
		in>>a;
		N2[N] = a;
		a2[i].a = a;
		a2[i].e = N;
	}
	for(int i=1;i<=K1;i++){
		for(int j=1;j<=K2;j++){
			N = a1[i].e+a2[j].e;
			a = a1[i].a*a2[j].a;
		//	cout<<"a:"<<a<<endl;
		//	cout<<"(int)a:"<<(int)a<<endl; 
		/*	while(fabs((a-(int)a))>0.001){
				
		//		cout<<"fabs((a-(int)a)):"<<fabs((a-(int)a))<<endl; 
		//		cout<<"po"<<endl;
				a *= 10;
				N -= 1;
			}
			
			while((a-(int)a)==0&&a!=0){
				a /= 10;
				N += 1;
			//	cout<<"op"<<endl;
			}*/ 
			
			if(result[N]==-9999){
				result[N] = 0;
				count++;
			}
		//	cout<<"N:"<<N<<endl; 
		//	cout<<"final a:"<<a<<endl;
			result[N] += a;
		}
	}
	cout<<count;

	for(int i=max -1;i>=0;i--){
		if(result[i]!=-9999){
			 result[i]=round(result[i],1);
			cout<<fixed<<setprecision(1);  
			cout<<" "<<i<<" "<<result[i];
		}
	}
//	system("pause");
	return 0;
}
