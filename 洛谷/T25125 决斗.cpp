#include <bits/stdc++.h> 
#define isNum(c) ('0'<=c&&c<='9')
using namespace std;
int t, a1, a2, h1, h2, x1, x2;
double t1, t2;
char chr; int ret;
int read() {
	chr = getchar(), ret = 0;
	while (!isNum(chr)) chr = getchar();
	while (isNum(chr)) {
		ret = ret * 10 + chr - '0';
		chr = getchar();
	}
	return ret;
}
int main() {
	t = read();
	while (t--) {
		h1 = read(), a1 = read(), scanf("%f", &t1);
		h2 = read(), a2 = read(), scanf("%f", &t2);
		if (a1 == 0) {
			if (a2 == 0) printf("0\n");
			else printf("2\n");
			continue;
		} else if (a2 == 0) {
			printf("1\n");
			continue;
		}
		x1 = (h2 + a1 - 1) / a1;
		x2 = (h1 + a2 - 1) / a2;
		t1 *= x1;
		t2 *= t2;
		if (t1 == t2) printf("0\n");
		else if (t1 < t2) printf("1\n");
		else printf("2\n");
	}
}
