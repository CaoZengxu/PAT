#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define max 100001
#define sage 4
#define nobleman 3
#define foolman 2
#define smallman 1
#define other 0
 struct Stu{
	char id[10];
	int virtue;
	int talent;
	int total;
	int type;//0:sage 1:nobleman 2:fool man 3:small man
}Human[100010];

/*
void printMan(Human *mans) {
	Human *p = mans->next;
	while (p) {
		printf("%s %d %d\n", p->id, p->virtue, p->talent);
		//cout << p->id << ' ' << p->virtue << ' ' << p->talent << endl;
		p = p->next;
	}
}
*/

bool cmp(Stu a,Stu b) {
	if (a.type != b.type) return a.type > b.type;
	else if (a.total != b.total) return a.total > b.total;
	else if (a.virtue != b.virtue) return a.virtue > b.virtue;
	else return strcmp(a.id, b.id)<0;
}

int main() {
	
	int N,L,H;
	cin>> N>>L>>H;
	int totalNum = N;
	
	for (int i = 0; i < N;i++) {
		cin >> Human[i].id;//由于scanf异常 改用cin
		scanf_s("%d%d",&Human[i].virtue,&Human[i].talent);
		Human[i].total = Human[i].virtue + Human[i].talent;
		if(Human[i].virtue<L||Human[i].talent<L)
			totalNum--;
		else if (Human[i].virtue >= H&& Human[i].talent >=H) {
			Human[i].type = sage;
		}			
		else if (Human[i].virtue >= H&& Human[i].talent >= L) {
			Human[i].type = nobleman;

		}
		else if (Human[i].virtue >= Human[i].talent&&Human[i].virtue >= L && Human[i].talent >= L) {
			Human[i].type = foolman;
			
		}
		else if (Human[i].virtue >= L && Human[i].talent >= L) {
			Human[i].type = smallman;
			

		}
		else {
			Human[i].type = other;
			
		}
	}
	sort(Human, Human + N, cmp);

	printf("%d\n", totalNum);
	for (int i = 0; i < totalNum; i++) {
		printf("%s %d %d\n", Human[i].id, Human[i].virtue, Human[i].talent);
	}
	return 0;
}