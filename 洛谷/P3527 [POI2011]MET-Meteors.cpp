// luogu-judger-enable-o2
#include <bits/stdc++.h>
#define il inline
#define rg register
#define int long long
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

const int N = 3e5 + 10;
int n, m, x, p, s[N], pl[N], pr[N], pv[N], ned[N], ans[N];
std::vector < int > vet, bel[N];

void modify(int k, int v) { for (; k <= m; k += k & -k) s[k] += v; }
int query(int k) { int r = 0; for (; k; k -= k & -k) r += s[k]; return r; }

void modify(int l, int r, int v) {
	if (l <= r) modify(l, v), modify(r + 1, -v);
	else modify(1, v), modify(r + 1, -v), modify(l, v);
}

void solve(int l, int r, std::vector < int > &vet) {
	if (l > r) return;
//	printf("solve %d %d\n", l, r);
	int sum, flag, mid = (l + r) >> 1;
	std::vector < int > lvet, rvet;
	for (int i = l; i <= mid; i++)
		modify(pl[i], pr[i], pv[i]);
	for (auto i : vet) {
		sum = flag = 0;
		for (auto j : bel[i]) {
			sum += query(j);
			if (sum >= ned[i]) {
				ans[i] = mid, flag = 1;
				lvet.push_back(i);
				break;
			}
		}
		if (!flag) ned[i] -= sum, rvet.push_back(i);
	}
	for (int i = l; i <= mid; i++)
		modify(pl[i], pr[i], -pv[i]);
	if (lvet.size()) solve(l, mid - 1, lvet);
	if (rvet.size()) solve(mid + 1, r, rvet);
	lvet.clear(), rvet.clear();
}

void main() {
	memset(ans, -1, sizeof(ans));
	read(n), read(m);
	for (int i = 1; i <= m; i++)
		bel[read(x), x].push_back(i);
	for (int i = 1; i <= n; i++)
		read(ned[i]);
	read(p);
	for (int i = 1; i <= p; i++)
		read(pl[i]), read(pr[i]), read(pv[i]);
	for (int i = 1; i <= n; i++)
		if (!ned[i]) ans[i] = 0;
		else vet.push_back(i);
	solve(1, p, vet);
	for (int i = 1; i <= n; i++)
		if (~ans[i]) print(ans[i]), putc('\n');
		else puts("NIE");
}

} signed main() { return ringo::main(), 0; }
