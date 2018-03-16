#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

typedef struct {
	char id[15];
	int local_num;
	int score;
	int local_rank;
	int total_rank;
}P;
bool cmp(P a, P b) {
	if(a.score!=b.score) return a.score > b.score;
	else return strcmp(a.id, b.id) < 0;
}

int main() {
	int N;
	int numofp;
	P p[30000];
	P op[300];
	cin >> N;
	int start = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> numofp;//当前考场人数
		for (int j = 0; j < numofp; j++)
		{
//			cin >> op[j].id;
				scanf_s("%s", op[j].id,20);
			cin>> op[j].score;
			op[j].local_num = i + 1;//考场号
		}
		sort(op, op + numofp, cmp);
		op[0].local_rank = 1;
		for (int j = 1; j < numofp; j++)
		{
			if (op[j].score == op[j - 1].score)
				op[j].local_rank = op[j - 1].local_rank;
			else
				op[j].local_rank = j + 1;
			
		}


		for (int j = 0; j < numofp; j++) {
			p[j + start] = op[j];
		}
		start += numofp;

	}

	sort(p, p + start, cmp);
	p[0].total_rank = 1;
	for (int i = 1; i < start; i++)
	{
		if (p[i].score == p[i - 1].score)
			p[i].total_rank = p[i - 1].total_rank;
		else
			p[i].total_rank = i + 1;
		
	}
	cout << start << endl;
	for(int i=0;i<start;i++)
		printf("%s %d %d %d\n",p[i].id,p[i].total_rank,p[i].local_num,p[i].local_rank);
	return 0;
}