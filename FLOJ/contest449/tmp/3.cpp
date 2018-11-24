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

const int maxn = 20, maxN = 1010;
int n, cnt3, cnt4, cnt5, tf[maxn], tp[maxn], seq[maxn], cnt[maxn];
bool flag, flag1, flag2, findans, vis[maxn];

std::set < int > set;
std::vector < int > p[maxn], f[maxN], G[maxn];

bool cmp1(int x, int y) {
#define a f[x]
#define b f[y]
	if (a.size() != b.size()) return a.size() < b.size();
	for (int i = 0; i < (int)a.size(); i++)
		if (a[i] != b[i]) return a[i] < b[i];
	return 0;
#undef a
#undef b
}

bool cmp2(int x, int y) {
	// printf("cmp2 %d %d\n", x, y);
#define a p[x]
#define b p[y]
	if (a.size() != b.size()) return a.size() < b.size();
	for (int i = 0; i < (int)a.size(); i++)
		if (a[i] != b[i]) return a[i] < b[i];
	return 0;
#undef a
#undef b
}

il void clear() {
	set.clear(), memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) p[i].clear(), G[i].clear();
}

void calc(int u, int last, int from) {
	if (vis[u]) return;
	p[from].push_back(u), vis[u] = 1;
//	printf("%d --> %d\n", from, u);
	if (!last) return;
	for (auto v : G[u]) calc(v, last - 1, from);
}

void solve() {
	clear();
//	puts("===========");
//	for (int i = 1; i <= n - 2; i++) print(seq[i]), putc(i == n - 2 ? '\n' : ' ');
	for (int i = 1; i <= n - 2; i++) ++cnt[seq[i]];
	for (int i = 1; i <= n; i++) if (!cnt[i]) set.insert(i);
//	for (int i = 1; i <= n; i++) print(cnt[i]), putc(i == n ? '\n' : ' ');
	for (int i = 1, u; i <= n - 2; i++) {
		while (vis[*set.begin()] || cnt[*set.begin()]) set.erase(set.begin());
		vis[u = *set.begin()] = 1;
		G[u].push_back(seq[i]);
		G[seq[i]].push_back(u);
//		printf("%d <-> %d\n", u, seq[i]);
		set.insert(seq[i]), --cnt[seq[i]];
	}
	for (int i = 1, u = 0, v = 0; i <= n; i++) {
		if (!vis[i]) (u ? v : u) = i;
		if (i == n) {
//			printf("%d <-> %d\n", u, v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		calc(i, 2, i);
		std::sort(p[i].begin(), p[i].end());
	}
	for (int i = 1; i <= n; i++) tp[i] = i;
	std::sort(tp + 1, tp + n + 1, cmp2);
	flag = true;
	for (int i = 1; i <= n; i++)
		if (p[tp[i]] != f[tf[i]]) { flag = false; break; }
//	printf("> %d\n", flag);
//	for (int i = 1; i <= n; i++) print(tp[i]), putc(i == n ? '\n' : ' ');
//	for (int i = 1; i <= n; i++) {
//		printf("%d : ", p[tp[i]].size());
//		for (auto it : p[tp[i]]) print(it), putc(' ');
//		putc('\n');
//	}
	if (!flag) return;
	for (int u = 1; u <= n; u++) for (auto v : G[u])
		if (u < v) printf("%d %d\n", u, v);
	findans = 1;
}

void dfs(int k) {
	if (k > n - 2) { solve(); return; }
	for (int i = 1; i <= n && !findans; i++)
		seq[k] = i, dfs(k + 1);
}

void solve1() {
	for (int i = 2; i <= n; i++)
		printf("1 %d\n", i);
}

void solve2() {
	for (int i = 1; i <= n; i++)
			
}

void main() {
	read(n);
	for (int i = 1, m, x; i <= n; i++) {
		for (read(m); m--; )
			read(x), f[i].push_back(x);
		std::sort(f[i].begin(), f[i].end());
	}
	flag1 = true;
	for (int i = 1; i <= n; i++) {
		if ((int)f[i].size() != n) flag1 = false;
		switch ((int)f[i].size()) {
			case 3: ++cnt3; break;
			case 4: ++cnt4; break;
			case 5: ++cnt5; break;
		}
	}
	flag2 = cnt3 == 2 && cnt4 == 2 && cnt5 == (n - 4) && n > 8;
	if (flag1) { solve1(); return; }
	if (flag2) { solve2(); return; }
	for (int i = 1; i <= n; i++) tf[i] = i;
	std::sort(tf + 1, tf + n + 1, cmp1);
//	for (int i = 1; i <= n; i++) {
//		printf("%d : ", f[tf[i]].size());
//		for (auto it : f[tf[i]]) print(it), putc(' ');
//		putc('\n');
//	}
	dfs(1);
}

} int main() { return ringo::main(), 0; }
