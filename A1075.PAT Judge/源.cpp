#include<iostream>
#include<algorithm>

using namespace std;

typedef struct {
	int part_s[6] = { -2 ,-2,-2,-2,-2,-2};
	int sum= 0;
	int perfectNum = 0;
	int id=-1;
	bool valid_flag = false;
}P;

bool cmp(P a, P b) {
	if (a.sum != b.sum) return a.sum > b.sum;
	else if (a.perfectNum != b.perfectNum) return a.perfectNum > b.perfectNum;
	else return a.id < b.id;
}

bool cmp1(P a, P b) {
	return a.id < b.id;
	return 0;
}

int main() {
	int N, K, M;
	P p[100];
	P pp[100];
	int point[6];
	cin >> N >> K >> M;
	for (int i = 1; i <=K; i++) {
		cin>>point[i];
	}

	int id, pro_s, cpoint;

	for (int i = 0; i < M; i++) {
		cin >> id >> pro_s>>cpoint;
		p[id].id = id;
		if (cpoint > p[id].part_s[pro_s]) {
			//if(p[id].part_s[pro_s])
			//p[id].sum += cpoint;
			p[id].part_s[pro_s] = cpoint;
		}
			
		
		if (cpoint > -1)
			p[i].valid_flag = true;
		if (cpoint == point[pro_s])
			p[id].perfectNum++;
	}

	int j = 0;
	for (int i = 0; i <= N;i++) {
		if (p[i].id != -1&&p[i].sum>0) {
			pp[j].id = p[i].id;
			
			pp[j].perfectNum = p[i].perfectNum;
			for (int l = 0; l <= K; l++) {
				pp[j].part_s[l] = p[i].part_s[l];
			}
				
			j++;
		}
	}
	sort(pp, pp + j+1, cmp);
	for (int i = 0; i <j; i++) {
		
		printf("%d %05d %d", i+1,pp[i].id, pp[i].sum);
		for (int l = 1; l <= K; l++) {
			if (pp[i].part_s[l] > -1)
				printf(" %d", pp[i].part_s[l]);
			else if(pp[i].part_s[l]==-2)
				printf(" -");
			else 
				printf(" %d",0);
		}
		cout << endl;
	}
	return 0;
}