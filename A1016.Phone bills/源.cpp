#include<iostream>	
#include<algorithm>
using namespace std;

typedef struct {
	char name[25];
	int month, day, hour, minutes;
	
	bool line;//0-off 1-on

}Record;
int tolls[24];
bool cmp(Record a, Record b) {
	if (strcmp(a.name, b.name) != 0) return strcmp(a.name, b.name) < 0;
	else if (a.month != b.month) return a.month < b.month;
	else if (a.day != b.day) return a.day < b.day;
	else if (a.hour != b.hour) return a.hour < b.hour;
	else return a.minutes < b.minutes;
}

void getAns(Record on, Record off, int &time, double &money) {   //计算通话时间以及话费
	Record t = on;
	while (t.day < off.day || t.hour < off.hour || t.minutes < off.minutes) {
		
		time++;
		
		money += tolls[t.hour];
		t.minutes++;

		if (t.minutes >= 60) {
			t.minutes = 0;
			t.hour++;
		}
		if (t.hour >=24) {
			t.hour = 0;
			t.day++;
		}
	}
}

int main() {
	Record records[1000];
	
	for (int i = 0; i < 24; i++) {
		cin >> tolls[i];
	}
	int N;
	cin >> N;
	char line[8];
	for (int i = 0; i < N; i++) {
		scanf_s("%s",records[i].name,25);
		scanf_s("%d:%d:%d:%d",  &records[i].month, &records[i].day, &records[i].hour, &records[i].minutes);
		scanf_s("%s", line,8);
		if (strcmp(line, "on-line") == 0)
			records[i].line = true;
		else
			records[i].line = false;
	}
	sort(records, records + N, cmp);  //排序
	int on = 0, next;
	while (on < N) {
		int needPrint = 0;
		next = on;
		while (next < N&&strcmp(records[next].name, records[on].name) == 0) {
			if (needPrint == 0 && records[next].line == true)
				needPrint = 1;
			else if (needPrint == 1 && records[next].line == false)
				needPrint = 2;
			next++;
		}
		if (needPrint < 2) {
			on = next;
			continue;
		}

			
			double totalMoney = 0;
			printf("%s %2d\n", records[on].name, records[on].month);
			for (int i = on; i < next-1; i++) {
				double money = 0;//cents  美分
				int time = 0;
				if (records[i].line == true && records[i + 1].line == false) {
					getAns(records[i], records[i + 1], time, money);
					printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",records[i].day,records[i].hour,records[i].minutes, records[i+1].day, records[i+1].hour, records[i+1].minutes,time,money/100.0);
					totalMoney += money;
				}
			}
			printf("Total amount: $%.2lf\n",totalMoney/100.0);

			on = next;
	}


	return 0;
 }