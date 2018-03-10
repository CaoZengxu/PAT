#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

const int maxn = 10000+10;
vector<int> map[maxn];

int line[maxn][maxn];

vector<int> tempPath;//搜索过程中的路径
vector<int> path; //最优路线
int minstep = maxn;
int minline = maxn;//最小路径换乘线路数
bool visited[maxn];
int cntLine(vector<int> p){
	int preline = 0;
	int count = 0;
	for(int i=0;i<p.size() - 1;i++){
		if(line[p[i]][p[i+1]]!=preline)
			count++;
		preline = line[p[i]][p[i+1]];
	}
	return count;
}

void dfs(int cnode,int end,int step){
	if(cnode==end){//找到目标
		if(step<minstep||(step==minstep&&cntLine(tempPath) < minline)){
			path = tempPath;
			minstep = step;
			minline = cntLine(tempPath);
		}
	}else{//访问cnode相邻节点
		for(int i=0;i<map[cnode].size();i++){
			if(!visited[map[cnode][i]]){
				visited[map[cnode][i]] = true;
				tempPath.push_back(map[cnode][i]);
				dfs(map[cnode][i],end,step+1);
				visited[map[cnode][i]] = false;  //回溯
				tempPath.pop_back();//回溯
			}
		}
	}
}

int main(){
	int N;

	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int m,prestate,state;
		scanf("%d",&m);
		scanf("%d",&prestate);//第一站
		for(int j=0;j<m-1;j++){  //后面m-1站
			scanf("%d",&state);
			map[prestate].push_back(state);//插入邻接表
			map[state].push_back(prestate);//插入邻接表
			line[state][prestate] = line[prestate][state] = i+1; //记录线路号
			prestate = state;
		}
	}

	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int start,end;
		scanf("%d %d",&start,&end);
		memset(visited,false,sizeof(visited));
		minstep = maxn;
		minline = maxn;
		tempPath.clear();
		tempPath.push_back(start);
		visited[start] = true;
		dfs(start,end,0);
		printf("%d\n", minstep);
		
		int preLine = line[path[0]][path[1]];
		int linestart = start;

		for(int j = 0;j<path.size() - 1;j++){
			if(line[path[j]][path[j+1]] != preLine){
				printf("Take Line#%d from %04d to %04d.\n",preLine,linestart,path[j]);
				preLine = line[path[j]][path[j+1]];
				linestart = path[j];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n",preLine,linestart,end);
		
	}
	return 0;
}