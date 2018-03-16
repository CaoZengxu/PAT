#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;

typedef struct {
	int id;
	char name[8];
	int grade;
}Student;

bool cmp1(Student a, Student b) {
	return a.id < b.id;
}

bool cmp2(Student a,Student b) {
	if(strcmp(a.name,b.name)!=0) return strcmp(a.name, b.name)<0;
	else return a.id < b.id;
}

bool cmp3(Student a, Student b) {
	if (a.grade != b.grade) return a.grade < b.grade;
	else return a.id < b.id;
}

int main() {
	int N, C;
	Student s[100010];
	cin >> N>>C;
	for (int i = 0; i < N; i++)
	{
		//cin >>  >> >> s[i].grade;
		scanf_s("%d %s %d", &s[i].id,s[i].name,8, &s[i].grade);

	}
	switch (C) {
	case 1:
		sort(s, s + N, cmp1);
		break;
	case 2:
		sort(s, s + N, cmp2);
		break;
	case 3:
		sort(s, s + N, cmp3);
		break;

	}
	for (int i = 0; i < N; i++)
	{
		printf("%06d %s %d\n", s[i].id, s[i].name, s[i].grade);
	}
	return 0;

}