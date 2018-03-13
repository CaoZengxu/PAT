#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string unit[] = { "Qian","ge","Shi","Bai","Qian","Wan","Yi" };
string number[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
string levelchan[] = { "ling","Ge","Wan","Yi" };
int main() {
	char s[10];
	int start = 0;
	bool negative = false;
	cin >> s;
	int length = strlen(s);
	if (s[0] == '-') {
		negative = true;
		start++;
	}
	int level;
	if (negative)
		cout << "Fu";
	bool ling = false;
	level = (length - 1 - start + 4) / 4;
	int levelt = level;
	for (int i = start; i<length; i++) {
		level = (length-i+ 3) / 4;
		levelt = (length - i + 2) / 4;

		if (!ling&&(s[i] - '0')==0) {
			ling = true;
		}
		else if((s[i] - '0') != 0){
			if (ling) {
				cout << " ling";
				
				ling = false;
			}
			if (i > start||negative)
				cout << " ";
			cout<<number[s[i] - '0'];
			
			if (((length - i) % 4) != 1) {
				cout << " "<<unit[(length - i) % 4];
				
			}
			 
			
		}
		if (level!=levelt) {
			if (level > 1) {
				cout <<" "<<levelchan[level];
				
			}
				
		}	
	}
	int n = 0;
	for (int i = start; i < length; i++) {
		n += s[i] - '0';
	}

	if (n == 0) {
		if (negative)
			cout <<" ";
		cout << "ling";
	}
		
	cout << endl;
	return 0;
}