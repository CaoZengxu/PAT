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
	Vnode v[max];
}MGraph;

class QueryResult
{
	public:
		int roadNum,stationNum;
		int stations[stationNum];
		QueryResult(int rnum,int stationNum);
		~QueryResult();
	
};

QueryResult::QueryResult(int rnum){
	this.roadNum = rnum;
}

int connect(MGraph &G,int vex1,int vex2,int line){

	G.arcnum++;
	if(G.v[vex1].firstAdj==NULL){
		G.vnum++;
		Arcnode *newnode = new Arcnode;
		newnode->adj = NULL;
		newnode->vex = vex2;
		newnode->line = line;
		G.v[vex1].firstAdj = newnode;
	}else{
		Arcnode *i=G.v[vex1].firstAdj;
		while(i->adj!=NULL){
			i = i->adj;
		}
		Arcnode *newnode = new Arcnode;
		newnode->adj = NULL;
		newnode->vex = vex2;
		newnode->line = line;
		i->adj = newnode;
	}

	if(G.v[vex2].firstAdj==NULL){
		G.vnum++;
		Arcnode *newnode = new Arcnode;
		newnode->adj = NULL;
		newnode->vex = vex1;
		newnode->line = line;
		G.v[vex1].firstAdj = newnode;
	}else{
		Arcnode *i=G.v[vex2].firstAdj;
		while(i->adj!=NULL){
			i = i->adj;
		}
		Arcnode *newnode = new Arcnode;
		newnode->adj = NULL;
		newnode->vex = vex1;
		newnode->line = line;
		i->adj = newnode;
	}

return 0;
} 

void InitGraph(MGraph &G){
	for(int i=0;i<max;i++){
		G.v[i].firstAdj = NULL;
	}
	G.vnum = 0;
	G.arcnum = 0;
}



int main(){

	//------------输入部分------------------///
	int N,M,K;
	int S;
	MGraph G;
	InitGraph(G);
	cin>>N;
	G.vnum = N;
	int t = -1; 
	int lineQuantity = 1;


	for(int i=0;i<N;i++){
		cin>>M;
		for(int j=0;j<M;j++){
			cin>>S;
			if(t!=-1){
				connect(G,t,S,linenum++);
			}
			t = S;			
		} 

	}

	//------------输出部分------------------///


	int queryNum;
	cin>>queryNum;
	int start[queryNum],end[queryNum];

	for(int i=0;i<queryNum;i++){
		cin>>start[i];
		cin>>end[i];
	}

	for(int i=0;i<queryNum;i++){
		QueryResult re =  query(start[i],end[i]);
		int lineNum = -1;
		bool LineFlag = false;
		int firststa,secondsta;
		int lk = 1;
		int head = re.stations[0];
		int rear = re.stations[lk];
		int temp;
		for(int j=0;j<re.roadNum;j++){

			Arcnode *k = G.v[head].adj;
			while(k!=NULL&&k->vex!=rear)//找到两节点之间的边
				k = k->adj;

			if(k==NULL)
				cout<<"寻找邻接节点异常"<<endl;
			
			temp = k->line;

			if(k->line!=lineNum){
				rear = head;
			}
		}
	}


	return 0;
}
