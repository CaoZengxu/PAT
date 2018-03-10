#include<iostream>
#include<fstream>
using namespace std;
#define max 600 
#define INFINITY 9999999
typedef struct {
	int adj;
}AdjMatrix;
 
typedef struct {
	int vex[max];
	AdjMatrix arcs[max][max];
	int vnum,arcnum;		
}MGraph;

bool final[max]; // already got v's shortest path while final[v] == true
void ShortestPath_DIJ(MGraph *G,int v0,int p[],int D[]) { 

	int min;
	for(int v=0;v<G->vnum;v++){
		final[v]=false;
		D[v]=G->arcs[v0][v].adj;
		if(D[v]<INFINITY)
			p[v] = v0;
	}

	D[v0]=0;final[v0]=true;
	int v;
	for(int i=0;i<G->vnum;i++){
		min = INFINITY;
		for (int w=0;w<G->vnum;w++){//??????v0???:V 
			if(!final[w])
				if(D[w]<min) {
					v = w;min = D[w];
				}
		}
		final[v]=true;//??final 
		for(int w=0;w<G->vnum;w++){//??D?? ???p 
			
			if(!final[w]){
					
				if(min+G->arcs[v][w].adj<D[w]){
					D[w] = min+G->arcs[v][w].adj;
					p[w] = v;
				}
					
			
			}	
		}
		
	}
	p[v0] = -1;
}


int main(){
	ifstream in("in.txt");
	int N,M,C1,C2;
	int c1,c2,t;
	int p[max];
	int D[max];
	MGraph g;
	
	for(int i=0;i<max;i++){
		for(int j=0;j<max;j++){
			g.arcs[i][j].adj = g.arcs[j][i].adj = INFINITY;
			
		}
		p[i] = -1;
		D[i] = INFINITY;
		g.vex[i] = 0;
		final[i] = false;
	}
		
	
	in>>N>>M>>C1>>C2; //N??? M?? ]

	g.vnum = N;g.arcnum = M;
	
	for(int j=0;j<N;j++){ 
		
		in>>g.vex[j];
	}
	for(int i=0;i<M;i++){ 
		in>>c1>>c2>>t;
		g.arcs[c1][c2].adj = g.arcs[c2][c1].adj = t; 
		g.arcs[i][i].adj = 0;
	}	

	ShortestPath_DIJ(&g,C1,p,D);
//	for(int i=0;i<N;i++)
//		cout<<p[i]<<" ";
//	cout<<endl;
	int shortest = D[C2]; 
	int shortestb=shortest;
	int count = 0;
	int NUMofEMS = 0;
	int maxv=0;
	bool flag[max];//???????? 
	for(int i=0;i<max;i++)
		flag[i] = false; 
//	cout<<shortest<<endl;
	while(shortest!=INFINITY&&shortest==shortestb){

		int v = p[C2];
		int l = C2;;
		do{
		//	if(!flag[l]){
				NUMofEMS += g.vex[l];	
		//		flag[l] = true;
		//	}
			l = p[l];
		}while(l>-1);
		if(maxv<NUMofEMS)
			maxv = NUMofEMS;
		NUMofEMS = 0;
		count++;
		g.arcs[v][C2].adj = g.arcs[C2][v].adj = INFINITY; 	
		for(int j=0;j<N;j++) {
				final[j] = false;
				p[j]= -1;
				D[j] = INFINITY;	
		}               
		ShortestPath_DIJ(&g,C1,p,D);
		shortest = D[C2]; 
		
	}
//	cout<<count<<" "<<NUMofEMS<<endl;
	printf("%d %d\n",count,maxv);
  	return 0;
} 
