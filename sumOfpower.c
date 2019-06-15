#include <stdio.h>

int powerFun(int b, int p) {
	if(p == 1) return b;
	else return b*powerFun(b,p-1);
}

int main() {
	int base = 2;
	int power = 1000;

	int koncna = powerFun(base, power);

	int sum = 0;
	while(koncna > 0) {
		sum += koncna %10;
		koncna /= 10;
	}

	printf("%d\n",sum);

}