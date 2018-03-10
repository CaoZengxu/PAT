#include<iostream>
#include<cstring>
using namespace std;
typedef struct {
	char name[100];
	char pw[100];
}User;
int main() {
	int n;
	User in[1005];
	cin >>n;
	int nt = n;
	User t;
	int len = 0;
	bool flag;
	while (n--) {
		flag = false;
		cin >> t.name >>t.pw;
		for (int i = 0; i<strlen(t.pw); i++) {
			if (t.pw[i] == '1') {
				flag = true;
				t.pw[i] = '@';
			}
				
			if (t.pw[i] == '0') {
				flag = true;
				t.pw[i] = '%';
			}
				

			if (t.pw[i] == 'l'){
				flag = true;
				t.pw[i] = 'L';
			}
				
			if (t.pw[i] == 'O') {
				flag = true;
				t.pw[i] = 'o';
			}
			
		}
		if (flag) {
			in[len++] = t;
		}
	}
	if (len > 0) {
		cout << len << endl;
		for (int i = 0; i < len; i++) {
			cout << in[i].name << " " << in[i].pw << endl;
		}
	}else {
		if(nt==1)
			printf("There is 1 account and no account is modified",nt);
		else
			printf("There are %d accounts and no account is modified", nt);
	}
	
	return 0;
}