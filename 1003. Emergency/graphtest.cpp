/*
author :LY   2016.5.31
*/
#include<iostream>
#include<fstream>
using namespace std;
#define INF 9999999

int N;     //number of city
int M;     //number of road    
int start,en;
const int MAXNUM=500;     //?????? 

int city[MAXNUM]; 
int path[MAXNUM][MAXNUM];    //?
int dist[MAXNUM];        //v0??????? 
int pathcount[MAXNUM];    //?????? 
int amount[MAXNUM];      //????????? 
bool S[MAXNUM];       //???????S??? 

void Dijs(int v0)     //??dij????????? 
{
         //?v0??S
    dist[v0]=0;
    S[v0]=true; 
    amount[v0]=city[v0]; 
     int u=v0;
    
    for(int i=0;i<N;i++)
    { 
        dist[i]=path[v0][i];    //optial
        if(dist[i]!=INF && i!=v0)
        amount[i]=amount[v0]+city[i]; 
           
       }

    
    /*
     ?v?v0?????,?v??S?? 
     */ 
    for(int i=1;i<N;i++) 
    { 
     
              //??v0?v?????,??????S?
         int min=INF;
         
         for(int j=0;j<N;j++)  //????? 
         {
             if(!S[j]&&dist[j]<min)
             {
                 u=j;
                 min=dist[j]; 
             } 
         } 
         
         S[u]=true;    //?v???S 
         
        //??v0????????
         for(int j=0 ;j<N; j++)
         {
             if(!S[j]&&dist[j]>dist[u]+path[u][j])     
             {
                 dist[j]= dist[u]+path[u][j];   //    ????
                amount[j]=amount[u]+city[j];
                pathcount[j]=pathcount[u];       
             } 
             else if(!S[j]&&dist[j]==dist[u]+path[u][j])
             {
                 pathcount[j]+=pathcount[u];
                 
                 if(amount[j]<city[j]+amount[u])
                 {
                     amount[j]=city[j]+amount[u];
                 } 
             } 
         }     
         
    }
} 
int main()
{
        ifstream in("in.txt");
   /* scanf("%d",&N);
    scanf("%d",&M);
    scanf("%d",&start);
    scanf("%d",&en);
     */
     in>>N>>M>>start>>en;
    for(int i=0;i<N;i++)
    {
        in>>city[i];
				//scanf("%d",&city[i]); 
    } 
    
    int i=0,j=0;
    //???dij??
    for(i=0;i<N;i++)
    {
        dist[i]=INF;
        pathcount[i]=1;
        S[i]=false; 
        amount[i]=city[i]; 
        for(j=0;j<N;j++)
        {
            path[i][j]=INF; 
        } 
    }
     
    int k1=0,k2=0,k3=0;
    for(int j=0;j<M;j++)
    {
    	in>>k1>>k2>>k3;
	/*    scanf("%d",&k1);
        scanf("%d",&k2);
        scanf("%d",&k3);*/
        path[k1][k2]=k3;     //the  length  of road between C1 and C2
        path[k2][k1]=k3; 
    } 
    Dijs(start); 
    printf("%d %d\n",pathcount[en],amount[en]); 
    getchar();
    return 0;
}
