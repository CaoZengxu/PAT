#include<iostream>
#include<cstring>
using namespace std;
int main() {
	int n;
	char s[300];
	char st[300];
	bool flag = false;
	int sameNum = 300;
	cin >> n;
	cin.ignore();
	while (n--) {
		int ts = 0;
		gets_s(s);
		if (flag) {
			int slength = strlen(s), stlength = strlen(st);
		
			int i = slength - 1;
			int j = stlength - 1;

			while (i >= 0 && j >= 0 && s[i] == st[j]) {
				i--;
				j--;
				ts++;
			}
			
			if (ts < sameNum)
				sameNum = ts;
		}
		
		
		strcpy_s(st, s);
		//if(flag)
		// cout << st << endl;
		flag = true;
	}
	int length = strlen(s);
	if (sameNum < 300&&sameNum>0) {
		for (unsigned int i = length - sameNum; i < length; i++) {
			cout << s[i];
		}
		cout << endl;
	}
	else
		cout << "nai" <<endl;

	return 0;
}