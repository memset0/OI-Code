#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll read() {
	ll x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}
const int maxn = 1010, Mod = 10000;
ll n, x, y, sum;
double ans;
struct Node {
	ll a, b, times;
} a[maxn];
bool cmp(Node a, Node b) {
	// if (a.times == b.times) return a.b > b.b;
	return a.times < b.times;
}
struct Bignum {
	int len, a[maxn];
};
void print(Bignum x) {
	for (int i = x.len; i > 0; i--)
		if (i == x.len) printf("%d", x.a[i]);
		else printf("%04d", x.a[i]);
	putchar('\n');
}
Bignum times(Bignum a, int x) {
	Bignum b;
	b.len = a.len, memset(b.a, 0, sizeof(b.a));
	// printf("%d * ", x);
	// print(a);
	for (int i = 1; i <= a.len; i++) {
		b.a[i] += a.a[i] * x;
		b.a[i + 1] += b.a[i] / Mod;
		b.a[i] %= Mod;
	}
	while (b.a[b.len + 1]) {
		b.len++;
		b.a[b.len + 1] += b.a[b.len] / Mod;
		b.a[b.len] %= Mod;
	}
	// print(b);
	return b;
}
Bignum divition(Bignum a, int x) {
	Bignum b;
	b.len = a.len, memset(b.a, 0, sizeof(b.a));
	int left = 0;
	for (int i = a.len; i > 0; i--) {
		a.a[i] += left * Mod;
		b.a[i] = a.a[i] / x;
		left = a.a[i] % x;
	}
	while (!b.a[b.len])
		b.len--;
	return b;
}
bool compare(Bignum a, Bignum b) {
	if (a.len > b.len) return 1;
	if (a.len < b.len) return 0;
	for (int i = a.len; i > 0; --i) {
		if (a.a[i] > b.a[i]) return 1;
		if (a.a[i] < b.a[i]) return 0;
	}
	return 0;
}
int main() {
	// freopen("INPUT", "r", stdin);
	n = read(), x = read(), y = read();
	for (int i = 1; i <= n; i++)
		a[i].a = read(), a[i].b = read(), a[i].times = a[i].a * a[i].b;
	sort(a + 1, a + n + 1, cmp);
	Bignum sum, ans, tmp;
	sum.len = sum.a[1] = ans.len = 1, a[0].a = x, ans.a[1] = 0;
	for (int i = 1; i <= n; i++) {
		// printf(">>> a = %lld b = %lld\n", a[i].a, a[i].b);
		sum = times(sum, a[i - 1].a);
		// print(sum);
		tmp = divition(sum, a[i].b);
		// print(tmp);
		if (compare(tmp, ans)) {
			ans = tmp;
		}
		// ans = max(ans, sum / (double)a[i].b);
	}
	// printf("====ans====\n");
	print(ans);
	return 0;
}