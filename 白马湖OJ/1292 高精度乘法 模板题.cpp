#include <bits/stdc++.h> 
#define K 10000
using namespace std;
const int maxl = 1010;
struct Num {
    int n[maxl];
    int l;
    int clean(int len, int k) {
        memset(n, 0, sizeof(n));
        l = len, n[1] = k;
    }
};
Num read() {
    char s[maxl]; Num a; int sl;
	scanf("%s", s), sl = strlen(s);
	a.clean((sl + 3) / 4, 0);
    for (int i = 1; i <= a.l; i++)
    	for (int j = min(i * 4, sl); j >= i * 4 - 3 && j >= 0; j--)
        	a.n[i] = a.n[i] * 10 + s[sl - j] - '0';
    return a;
}
void write(Num a) {
	printf("%d", a.n[a.l]);
    for (int i = a.l - 1; i >= 1; i--) 
        printf("%04d", a.n[i]);
    puts("");
}
Num mul(Num a, Num b) {
	Num c;
	c.clean(a.l * b.l + 1, 0);
	for (int i = 1; i <= a.l; i++)
		for (int j = 1; j <= b.l; j++) {
			c.n[i + j - 1] += a.n[i] * b.n[j];
			c.n[i + j] += c.n[i + j - 1] / K;
			c.n[i + j - 1] %= K;
		}
	while (!c.n[c.l] && c.l) c.l--;
	return c;
}
int main() {
    Num a = read(), b = read();
    Num c = mul(a, b);
    write(c);
    return 0;
}
