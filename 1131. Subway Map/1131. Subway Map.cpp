#include<iostream>
using namespace std;
#define max 10000

typedef struct Arcnode{
	   struct	Arcnode  *adj;
	   int vex;
	   int line;
}Arcnode;

typedef struct{
	Arcnode *firstAdj;
}Vnode; 

typedef struct{
	int vnum,arcnum;
	Vnode V[max];
}MGraph;

void connect(){
	
	
} 

int main(){
	cout<<456;
	int N,M,K;
	int S;
	MGraph G;
	G.vnum = N;
	int t = -1; 
	int linenum;
	for(int i=0;i<N;i++){
		cin>>M;
		for(int j=0;j<M;j++){
			cin>>S;
			if(t!=-1){
				Arcnode *newnode = new Arcnode;
				
			}
			t = S;			
		} 

	}
	return 0;
}
