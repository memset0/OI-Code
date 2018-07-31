#include <bits/stdc++.h> 
#define K 100000
using namespace std;
const int maxl = 210;
struct Num {
    int n[maxl];
    int l, mark = 0;
    int clean(int len, int k) {
        memset(n, 0, sizeof(n));
        l = len, n[1] = k;
        mark = 0;
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
	if (a.mark) putchar('-');
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
bool cmp(Num a, Num b) {
	if (a.l == b.l) {
		for (int i = a.l; i > 0; i--)
			if (a.n[i] != b.n[i]) return a.n[i] > b.n[i];
	} else return a.l > b.l;
}
Num sub(Num a, Num b) {
	Num c;
	c.clean(max(a.l, b.l), 0);
	if (!cmp(a, b)) {
		c.mark = 1;
		swap(a, b);
	}
    for (int i = 1; i <= c.l; i++) {
        c.n[i] += a.n[i] - b.n[i];
        if (c.n[i] < 0) {
        	c.n[i + 1] -= 1;
        	c.n[i] += K;
		}
    }
    while (!c.n[c.l] && c.l) c.l--;
    return c;	
}
int main() {
    Num a = read(), b = read();
    Num c = sub(a, b);
    write(c);
    return 0;
}
