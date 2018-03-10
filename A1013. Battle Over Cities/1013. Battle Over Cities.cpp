#include<iostream>
using namespace std;
#define max 1500

 typedef struct{
 	int vex[max];
 	bool arcs[max][max];
 	int vnum,arcnum;
 }MGraph;
 
 bool visited[max];   //标记访问 
 void DFS(MGraph &g,int v0){
 /*	cout<<"DFS:"<<endl;
 	for(int i=1;i<=g.vnum;i++){
	 	for(int j=1;j<=g.vnum;j++)
	 		cout<<g.arcs[i][j]<<" ";
	 	cout<<endl;
	 }*/
 	for(int i=1;i<=g.vnum;i++){
 		if(g.arcs[v0][i]&&!visited[i]){
 		//	cout<<"DFS i:"<<i<<endl;
 			visited[i] = true;
 			DFS(g,i);
		 }
 			
	 }
 }
 int getRepairNum(MGraph &g,int v0){
 	int count = 0;
 	int backup[g.vnum+1];
 	for(int i=0;i<=g.vnum;i++){
 		backup[i] = g.arcs[v0][i];
	 }
 	for(int i=0;i<=g.vnum;i++){
 		g.arcs[i][v0] = g.arcs[v0][i] = false;
	 }
	 /*
	 cout<<"进入"<<endl; 
	 for(int i=1;i<=g.vnum;i++){
	 	for(int j=1;j<=g.vnum;j++)
	 		cout<<g.arcs[i][j]<<" ";
	 	cout<<endl;
	 }
	 */
 	visited[v0] = true;
 	for(int i=1;i<=g.vnum;i++){
 		if(!visited[i]){
 		/*	cout<<"i:"<<i<<endl;
 			for(int k=1;k<=g.vnum;k++){
 				cout<<visited[k]<<" "; 
			 }
			cout<<endl; 
			*/
 			count++;
 			visited[i] = true;
 			DFS(g,i);
		 }
	 }
	 
	 for(int i=0;i<=g.vnum;i++){
 		g.arcs[i][v0] = g.arcs[v0][i] = backup[i];
	 }
	 for(int i=0;i<max;i++)
 		visited[i] = false;
 	//cout<<"count:"<<count<<endl;
 	return count-1>= 0?count-1:0;
 }
 int main(){
 	int N,M,K;
 	MGraph g;
 	cin>>N>>M>>K;
 	for(int i=0;i<max;i++)
 		visited[i] = false;
 	g.arcnum = M;
 	g.vnum = N;
 	for(int i=0;i<=N;i++)
 		for(int j=0;j<=N;j++)
 			g.arcs[i][j] = g.arcs[j][i] = false;
 	int v1,v2;
 	for(int i=0;i<M;i++){
 		cin>>v1>>v2;
 		g.arcs[v1][v2] = g.arcs[v2][v1] = true;
	 }
	/*
	 for(int i=1;i<=g.vnum;i++){
	 	for(int j=1;j<=g.vnum;j++)
	 		cout<<g.arcs[i][j]<<" ";
	 	cout<<endl;
	 }
	 	*/
 	int query[K];
 	for(int i=0;i<K;i++)
 		cin>>query[i];
 	for(int i=0;i<K;i++)
 		cout<<getRepairNum(g,query[i])<<endl;
 	getchar();
 	getchar();
 	return 0;
 }
