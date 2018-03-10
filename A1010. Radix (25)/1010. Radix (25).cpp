#include<iostream>
#include<cstring>
using namespace std;
int main(){
	
	char N1[11],N2[11];
	char *NN1,*NN2;
	NN1 = N1;
	NN2 = N2;
	long long Nnum = 0,othernum = 0;
	int length,otherlength;
	int tag;
	long long radix;
	cin>>N1;
	cin>>N2;
	cin>>tag>>radix;
	long long temp;
	
	if(tag==2){
		NN1 = N2;
		NN2 = N1;
	}
	if (strcmp(NN1, NN2) == 0){
        cout << radix << endl;
        return 0;
    }
	
	//cout<<NN1[1];
	length = strlen(NN1);
	for(int i=length-1;i>=0;i--){
		if(NN1[i]>='a'){
			temp = NN1[i] - 'a' + 10;
			for(int j = 0;j<length-1-i;j++)
				temp *= radix;
			Nnum += temp;
		}else{
			temp = NN1[i] - '0';
			for(int j = 0;j<length-1-i;j++)
				temp *= radix;
			Nnum += temp;
		}
	}
	otherlength = strlen(NN2);
	
	long long maxDigit = 0;
	
    int n2[otherlength];
	for(int i=0;i<otherlength;i++){
		if(NN2[i]>='a'){
			n2[i] = NN2[i] - 'a' + 10;
				
		}else{
			n2[i] = NN2[i] - '0';
		}
		if(n2[i]>maxDigit)
			maxDigit = n2[i];
	}
	
	long long minResRadixDL = maxDigit + 1;
	long long l = minResRadixDL;
    long long h = Nnum > l ? Nnum : l;//进制数必然小于等于Nnum   

	while(h>=l){
		long long	otherradix = (h+l)/2;
		
		othernum = 0;

		for(int i=0;i<otherlength;i++){
			othernum = othernum*otherradix + n2[i];
			
			if(othernum>Nnum){ //otherradix is too big
				h = otherradix - 1;
				break;
			}else if(othernum<0){
				cout<<"Impossible"<<endl;

				return 0;
			}
		}
		
		if(othernum == Nnum){

			cout<<otherradix<<endl;

			return 0;
		} 
		if(othernum<Nnum){  //otherradix is ts9jix hj 1 36s9jix hj 1 36oo small
			l = otherradix +1;
		}

	}

	cout<<"Impossible"<<endl;	


//	system("pause");
	return 0;
}
