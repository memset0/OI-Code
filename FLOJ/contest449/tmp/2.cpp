#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T > il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}

template < class T > il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}

const int maxn = 1e4 + 10, maxm = 40, p1 = 19260817, p2 = 20040301;
int n, m, ans;
int a[maxm], b[maxm], c[maxm], cnt[maxn], prime[maxn];
bool vis[maxn], map1[p1], map2[p2];

struct pair { int a, b; } t[maxn];
bool operator < (const pair &a, const pair &b) { return (a.a == b.a) ? (a.b > b.b) : (a.a > b.a); }

int hash(int *a, int p) {
	int ret = 0;
	for (int i = 1; i <= m; i++)
		ret = ((ll)ret * 373777 + a[i]) % p;
	return ret;
}

int pow(int a, int b) {
	int s = 1;
	while (b) {
		if (b & 1) s = s * a;
		a = a * a, b >>= 1;
	}
	return s;
}

void dfs(int u, int k, int l) {
// 	printf("dfs %d %d %d\n", u, k, l);
	if (u > prime[0]) {
		for (int i = 1; i <= m; i++) c[i] = b[i];
		std::sort(c + 1, c + m + 1);
		for (int i = 2; i <= m; i++) if (c[i] == c[i - 1]) return;
		for (int i = 1; i <= m; i++) t[i] = (pair){a[i], b[i]};
		std::sort(t + 1, t + m + 1);
		for (int i = 1; i <= m; i++) c[i] = t[i].b;
		int val1 = hash(c, p1), val2 = hash(c, p2);
		if (map1[val1] && map2[val2]) return;
		// for (int i = 1; i <= m; i++) print(c[i]), putc(i == m ? '\n' : ' ');
		int tmp = 1;
		for (int i = 1; i <= m; i++) tmp = tmp * c[i];
		map1[val1] = map2[val2] = 1;
		++ans; return;
	}
	if (!l) dfs(u + 1, 1, cnt[u + 1]);
	if (k > m) return;
	for (int i = 0; i * a[k] <= l; i++) {
		b[k] *= pow(prime[u], i);
		dfs(u, k + 1, l - i * a[k]);
		b[k] /= pow(prime[u], i);
	}
}

void main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) read(a[i]);
	std::sort(a + 1, a + m + 1);
	std::reverse(a + 1, a + m + 1);
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0] && i * prime[j] <= n; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
	for (int i = 1, u; i <= n; i++) {
		u = i;
		for (int j = 1; j <= prime[0]; j++)
			while (u % prime[j] == 0)
				++cnt[j], u /= prime[j];
	}
//	for (int i = 1; i <= prime[0]; i++)
//		printf("%d : %d\n", prime[i], cnt[i]);
	for (int i = 1; i <= m; i++)
		b[i] = 1;
	dfs(1, 1, cnt[1]);
	print(ans), putc('\n');
}

} int main() { return ringo::main(), 0; }
