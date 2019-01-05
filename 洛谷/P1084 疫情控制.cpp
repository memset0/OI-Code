// luogu-judger-enable-o2
// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

template <typename T> inline void read(T &x) {
	x = 0; register char ch; register bool fl = 0;
	while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
	while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}
template <typename T> inline void readc(T &x) {
	while (x = getc(), !islower(x) && !isupper(x));
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

#define int long long

const int maxn = 50010, maxm = 100010;
const ll inf = 4000000000000000000;

int n, m, u, v, w, cnt;
int a[maxn], id[maxn], lef[maxn], col[maxn], nod[maxn], mink[maxn], minv[maxn];
int f[maxn][20];
ll l, r, min, mid, ans, lst, g[maxn][20];
bool tag[maxn], used[maxn];

std::vector < ll > vet[maxn];
std::vector < std::pair < ll, int > > ned, set;

int tot = 2, hed[maxn], to[maxm], val[maxm], nxt[maxm];

void dfs(int u) {
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != f[u][0]) {
			f[v][0] = u;
			g[v][0] = val[i];
			dfs(v);
		}
}

void color(int u, int c) {
	col[u] = c;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != f[u][0])
			color(v, c);
}

bool is_full(int u) {
	if (tag[u]) return true;
	bool flag = false;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != f[u][0]) {
			flag = true;
			if (!is_full(v))
				return false;
		}
	return flag;
}

bool check(ll x) {
	// printf("\n=== check %d ===\n", x);
	memset(tag, 0, sizeof(tag));
	for (int i = 1; i <= n; i++)
		vet[i].clear();
	set.clear();
	ned.clear();
	for (int i = 1; i <= m; i++) {
		u = a[i], lst = x;
		for (int i = 19; i >= 0; i--)
			if (lst >= g[u][i]) {
				lst -= g[u][i];
				u = f[u][i];
			}
		if (u == 0) vet[col[a[i]]].push_back(lst);
		else tag[u] = 1;
	}
	for (int i = 1; i <= cnt; i++)
		if (is_full(nod[i])) {
			for (std::vector < ll > ::iterator it = vet[i].begin(); it != vet[i].end(); it++)
				set.push_back(std::make_pair(*it, i));
		} else {
			for (std::vector < ll > ::iterator it = vet[i].begin(); it != vet[i].end(); it++)
				set.push_back(std::make_pair(*it, i));
			ned.push_back(std::make_pair(lef[i], i));
		}
	std::sort(ned.rbegin(), ned.rend());
	std::sort(set.rbegin(), set.rend());
	memset(minv, 63, sizeof(minv));
	memset(used, 0, sizeof(used));
	for (int i = 0; i < (int)set.size(); i++)
		if (set[i].first < minv[set[i].second]) {
			minv[set[i].second] = set[i].first;
			mink[set[i].second] = i;
		}
	// printf("%d %d\n", set.size(), ned.size());
	// for (int i = 0; i < (int)ned.size(); i++)
	// 	printf("(%d %d) ", ned[i].first, ned[i].second);
	// putc('\n');
	// for (int i = 0; i < (int)set.size(); i++)
	// 	printf("(%d %d %d) ", set[i].first, set[i].second, minv[set[i].second]);
	// putc('\n');
	for (int i = 0, j = 0; i < (int)ned.size(); i++) {
		// printf(">>> %d %d\n", i, j);
		if (minv[ned[i].second] != minv[0] && !used[mink[ned[i].second]]) {
			// printf("flag\n");
			used[mink[ned[i].second]] = true;
			continue;
		}
		while ((used[j] || set[j].first < ned[i].first) && j < (int)set.size()) j++;
		if (j == (int)set.size())
			return false;
		used[j++] = true;
	}
	return true;
}

signed main() {
	read(n);
	for (int i = 1; i < n; i++) {
		read(u), read(v), read(w);
		nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, val[tot] = w, hed[v] = tot++;
	}
	read(m);
	for (int i = 1; i <= m; i++)
		read(a[i]);
	// std::sort(a + 1, a + m + 1);
	// for (int i = 1; i <= m; i++)
	// 	print(a[i]);
	// putc('\n');
	dfs(1);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++) {
			f[j][i] = f[f[j][i - 1]][i - 1];
			g[j][i] = g[f[j][i - 1]][i - 1] + g[j][i - 1];
		}
	cnt = 0;
	for (int i = hed[1], v = to[i]; i; i = nxt[i], v = to[i]) {
		color(v, ++cnt);
		lef[cnt] = val[i];
		nod[cnt] = v;
		id[v] = cnt;
		// printf("%d %d %d\n", cnt, v, val[i]);
	}
	// print(check(4), '\n');
	ans = -1, l = 0, r = 1e9;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1;
			ans = mid;
		} else {
			l = mid + 1;
		}
	}
	print(ans, '\n');
	return 0;
}