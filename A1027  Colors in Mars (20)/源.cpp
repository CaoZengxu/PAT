#include<iostream>
using namespace std;
char l[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D' };
int main() {
	int color[3];
	char s[8];
	s[0] = '#';
	for(int i = 0; i < 3; i++){
		cin >> color[i];
	}

		s[ 2] = l[color[0] % 13];
		s[1] = l[color[0]/13];
		s[4] = l[color[1] % 13];
		s[3] = l[color[1] / 13];
		s[6] = l[color[2] % 13];
		s[5] = l[color[2] / 13];

		for (int i = 0; i <= 6; i++)
			cout << s[i];
		cout<< endl;
	return 0;
}