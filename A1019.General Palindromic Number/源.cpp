#include<iostream>
using namespace std;
int main() {
	int n;
	int b;
	int len = 0;
	int s[10000];
	bool flag = true;;
	cin >> n;
	cin >> b;
	//Ҫ��do-while  �ǿ��ǵ���n = 0��ʱ������

do{
		s[len++] = n % b;
		n /= b;
} while (n);

	for (int j = 0; j <=len / 2; j++) {
		if (s[j] != s[len - j - 1]) {
			flag = false;
			break;
		}
	}

	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for (int i = len - 1; i >= 0; i--) {
		printf("%d", s[i]);
		if (i != 0)
			printf(" ");
	}
	//cout << endl;
	return 0;
}