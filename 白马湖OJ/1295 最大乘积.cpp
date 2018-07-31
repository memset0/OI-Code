#include <bits/stdc++.h> 
#define K 10000
using namespace std;
const int maxn = 10010;
const int maxl = 1010;
struct Num {
    int n[maxl];
    int l, mark;
    int clean(int len, int k) {
        memset(n, 0, sizeof(n));
        l = len, n[1] = k;
        mark = 0;
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
	if (a.mark) putchar('-');
	printf("%d", a.n[a.l]);
    for (int i = a.l - 1; i >= 1; i--) 
        printf("%04d", a.n[i]);
    puts("");
}
bool cmp(Num a, Num b) {
	if (a.l == b.l) {
		for (int i = a.l; i > 0; i--)
			if (a.n[i] != b.n[i]) return a.n[i] > b.n[i];
	} else return a.l > b.l;
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
Num low_sum(Num a, int b) {
	a.n[1] += b;
	for (int i = 1; a.n[i] / K; i++) {
		a.n[i + 1] += a.n[i] / K;
		a.n[i] %= K;
	}
	while (a.n[a.l + 1]) a.l++;
	return a;
}
Num low_mul(Num a, int b) {
	for (int i = a.l; i >= 1; i--) {
		a.n[i] *= b;
		a.n[i + 1] += a.n[i] / K;
		a.n[i] = a.n[i] % K;
	}
	a.l += 5;
	while (!a.n[a.l] && a.l) a.l--;
	return a;
}
int n, m, s = 0, l = 0, a[maxn], dis[maxn];
int main() {
	cin >> n;
	int i, sum;
	for (i = 2, sum = 0; sum + i <= n; sum += i, i++) {
		a[++l] = i;
	}
	for (int i = 1; i <= n - sum; i++)
		a[l - i + 1]++;
	Num s; s.clean(1, 1);
	for (int i = 1; i <= l; i++)
		printf("%d ", a[i]), s = low_mul(s, a[i]);
	puts("");
	write(s);
    return 0;
}
