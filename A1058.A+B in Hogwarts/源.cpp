#include<iostream>
using namespace std;
int main() {
	int Galleon = 0, Sickle = 0, Knut = 0;
	
	int a, b, c;
	int i = 2;
	while (i--) {
		scanf_s("%d.%d.%d", &a, &b, &c);
		Galleon += a;
		Sickle += b;
		Knut += c;
	}
	Sickle += Knut / 29;
	Knut %= 29;
	Galleon += Sickle / 17;
	Sickle %= 17;
	printf("%d.%d.%d\n", Galleon, Sickle, Knut);
	return 0;
}