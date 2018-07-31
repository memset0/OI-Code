#include <bits/stdc++.h> 
#define K 100000
using namespace std;
const int maxl = 210;
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
	a.clean((sl + 4) / 5, 0);
    for (int i = 1; i <= a.l; i++)
    	for (int j = min(i * 5, sl); j >= i * 5 - 4 && j >= 0; j--)
        	a.n[i] = a.n[i] * 10 + s[sl - j] - '0';
    return a;
}
void write(Num a) {
	printf("%d", a.n[a.l]);
    for (int i = a.l - 1; i >= 1; i--) 
        printf("%05d", a.n[i]);
    puts("");
}
Num sum(Num a, Num b) {
    Num c;
	c.clean(max(a.l, b.l), 0);
    for (int i = 1; i <= c.l; i++) {
        c.n[i] += a.n[i] + b.n[i];
        c.n[i + 1] += c.n[i] / K;
        c.n[i] %= K;
    }
    if (c.n[c.l + 1]) c.l++;
    return c;
}
int main() {
    Num a = read(), b = read();
    Num c = sum(a, b);
    write(c);
    return 0;
}
