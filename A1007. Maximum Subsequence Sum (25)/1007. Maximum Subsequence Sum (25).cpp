#include<iostream>
//#include<fstream>
using namespace std;
typedef struct {
	int low,high,sum;
}midse;
midse find_cross_sequence(int S[],int low,int mid,int high){
	midse result;
	result.low = mid;
	result.high = mid;
	result.sum = 0;
	int hsum = 0,lsum = 0,sum = 0;
	for(int i=mid;i<=high;i++){
		sum+=S[i];
		if(sum>hsum){
			hsum = sum;
			result.high = i;
		}
	}
	sum = 0;
	for(int i=mid-1;i>=low;i--){
		sum+=S[i];
		if(sum>lsum){
			lsum = sum;
			result.low = i;
		}
	}
	result.sum = lsum+hsum;
	return result;
}

 midse findmaxsubse(int S[],int low,int high){  
	 midse lmax,hmax,mmax;
	midse result;
	lmax.low = low;
	lmax.high = high;
	lmax.sum = S[low];
	hmax.low = low;
	hmax.high = high; 
	hmax.sum = S[low];
	result.high = high;
	result.low = low;
	result.sum = S[low];
//	cout<<"get"<<endl;
	if(low==high)
		return result;
	int mid = (low+high)/2;
//	cout<<"mid:"<<mid<<endl;
//	cout<<"low:"<<low<<endl;
	if(low<mid){
//		cout<<"low:"<<low<<" mid:"<<mid<<endl;
		lmax = findmaxsubse(S,low,mid);
		cout<<""; 
	//	cout<<"lmax:";
	//	cout<<lmax.sum<<" "<<lmax.low<<" "<<lmax.high;
	}
	if(high>mid){
//		cout<<"mid:"<<mid<<" high:"<<high<<endl;
		hmax = findmaxsubse(S,mid+1,high);
	}
		 
	mmax = find_cross_sequence(S,low,mid,high);
//	cout<<"mmax:"<<mmax.low<<" "<<mmax.high<<" "<<mmax.sum<<endl;
	if(lmax.sum>=hmax.sum&&lmax.sum>=mmax.sum){
//		cout<<"lmax:";
//		cout<<lmax.sum<<" "<<lmax.low<<" "<<lmax.high;
		return lmax;
	}
		
	if(mmax.sum>=lmax.sum&&mmax.sum>=hmax.sum){
//		cout<<"mmax:";
//		cout<<mmax.sum<<" "<<mmax.low<<" "<<mmax.high;
		return mmax;
	}
		
	if(hmax.sum>mmax.sum&&hmax.sum>lmax.sum){
//		cout<<"hmax:";
//		cout<<hmax.sum<<" "<<hmax.low<<" "<<hmax.high;
		return hmax;
	}
		
}
int main(){
	int k;
//	ifstream in("in.txt");
	int low =0;
	cin>>k;
	int high = k-1;
	if(k<=0){
		cout<<0;
		return 0;
	}
		
	int sequence[10000];
	
	for(int i=0;i<k;i++)
		cin>>sequence[i];
	midse result = findmaxsubse(sequence,low,high);
	if(result.sum<0)
		cout<<0<<" "<<sequence[0]<<" "<<sequence[k-1];
	else
		cout<<result.sum<<" "<<result.low<<" "<<result.high;
	//system("pause");
	return 0;
}
