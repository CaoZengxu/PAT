#include<iostream>
#include<fstream>
using namespace std;
typedef struct {
	int childnum;
	int level;
	int firstChild;
	int bro;
}TreeNode;
int numlevel = 1;
void addbro(TreeNode T[],int lbro,int rbro){
//	cout<<"addbro ";
	if(T[lbro].bro == -1){
		T[lbro].bro = rbro;
	}else{	
		addbro(T,T[lbro].bro,rbro);
	}
}

void addSon(TreeNode T[],int p,int son){
	
	if(T[p].firstChild == -1){
		T[p].firstChild = son;
	}else{	
		
		addbro(T,T[p].firstChild,son);
	}
}
void addlevel(TreeNode T[],int p,int s){
	T[s].level = T[p].level + 1;
	int t = T[s].firstChild ;
	if(t != -1){
		addlevel(T,s,t);
		if(T[t].bro != -1)
			addlevel(T,s,T[t].bro);
	}
		
	if(numlevel<T[s].level)
		numlevel = T[s].level;
}
int main(){
	
	ifstream in("in.txt");
	
	int N,M;
	int ID,k;
	int IDK;
	TreeNode T[120];
	for(int i=0;i<120;i++){
		T[i].childnum = 0;
		T[i].level = 1;
		T[i].firstChild = -1;
		T[i].bro = -1;
	}
	
	in>>N>>M;
	
	
	for(int i=0;i<M;i++){
		in>>ID>>k;
			
		T[ID].childnum += k;
		
		for(int j=0;j<k;j++){
			
			in>>IDK;
			addSon(T,ID,IDK);	
			addlevel(T,ID,IDK);
		w
		}
	
	}
	int answer[120];
	
	for(int i=0;i<120;i++)
		answer[i] = 0;
	
	for(int i=1;i<=N;i++){
		if(T[i].childnum == 0)
			answer[T[i].level]++;
	}
	
	for(int i=1;i<numlevel;i++)
		cout<<answer[i]<<" ";
	cout<<answer[numlevel];
	return 0;
}
