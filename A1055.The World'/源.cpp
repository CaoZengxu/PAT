#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef struct {
	char name[10];
	int age, worth;
}P;


bool cmp(P a,P b) {
	if (a.worth != b.worth) return a.worth > b.worth;
	else if (a.age != b.age) return a.age < b.age;
	else 
		return strcmp(a.name,b.name)<0;
}

int main() {
	P p[100];

	int N, K;//N样本数量 K 查询次数

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		scanf_s("%s %d %d", p[i].name,10, &p[i].age, &p[i].worth);

	}
	sort(p, p + N, cmp);
	int num, Amin, Amax;
	for (int i = 0; i < K; i++) {
		scanf_s("%d %d %d", &num, &Amin, &Amax);
		int l = 0;
		int y = 0;
		printf("Case #%d:\n", i + 1);
		while (l < N&&y<num) {
			if (p[l].age >= Amin&&p[l].age <= Amax) {
				printf("%s %d %d\n", p[l].name, p[l].age, p[l].worth);
				y++;
			}
			l++;
		}
		if (y == 0)
			printf("None\n");

	}
	
	
	return 0;
}