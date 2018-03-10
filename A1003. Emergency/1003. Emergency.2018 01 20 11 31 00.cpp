#include<iostream>

using namespace std;
#define max 501
#define INFINITY 65535
typedef struct {
	int adj;
}AdjMatrix;
 
typedef struct {
	int vex[max];
	AdjMatrix arcs[max][max];
	int vnum,arcnum;		
}MGraph;

bool final[max]; // already got v's shortest path whill final[v] == true
void ShortestPath_DIJ(MGraph *G,int v0,bool p[][max],int D[]) {
	int min;
	for(int v=0;v<G->vnum;v++){
		final[v]=false;
		D[v]=G->arcs[v0][v].adj;
		for(int w=0;w<G->vnum;w++) p[v][w]=false;
		if(D[v]< INFINITY){
			p[v][v0]=true;p[v][v]=true;
		}
	}
	D[v0]=0;final[v0]=true;
	int v;
	for(int i=0;i<G->vnum;i++){
		min = INFINITY;
		for (int w=0;w<G->vnum;w++){
			if(!final[w])
				if(D[w]<min) {
					v = w;min = D[w];
				}
		}
		final[v]=true;
		for(int w=0;w<G->vnum;w++){
			if(!final[w]&&min+G->arcs[v][w].adj<D[w])
				D[w] = min+G->arcs[v][w].adj;
				p[w][v] = p[v][w] = true;
				p[w][w] = true;
		}
	}
	
	
}


int main(){

	int N,M,C1,C2;
	int c1,c2,t;
	bool p[max][max];
	int D[max];
	MGraph g;
	for(int i=0;i<max;i++){
		for(int j=0;j<max;j++){
			g.arcs[i][j].adj = g.arcs[j][i].adj = INFINITY;
			p[max][max] = false;
		}
		D[i] = INFINITY;
		g.vex[i] = 0;
	}
		
		

	cin>>N>>M>>C1>>C2;
	

	g.vnum = N;g.arcnum = M;
	for(int j=0;j<N;j++){
		final[j] = false;
		cin>>g.vex[j];
	}
	for(int i=0;i<M;i++){
		cin>>c1>>c2>>t;
		g.arcs[c1][c2].adj = g.arcs[c2][c1].adj = t; 
	}		
	ShortestPath_DIJ(&g,C1,p,D);
	
	for(int i=0;i<g.vnum;i++)
		cout<<D[i]<<" ";
	cout<<endl;
	for(int j=0;j<g.vnum;j++){
		for(int i=0;i<g.vnum;i++){
			cout<<p[j][i]<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
} 
