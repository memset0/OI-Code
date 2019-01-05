#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

void openFile() { freopen("track.in", "r", stdin); freopen("track.out", "w", stdout); }
void closeFile() { fclose(stdin); fclose(stdout); }

inline int read() {
	char c = getchar(); int n = 0;
	while (c < '0' || c > '9') { c = getchar(); }
	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
	return n;
}

typedef long long lol;

const int maxN = 100005;

int n, m, num, f[maxN];
lol ans, sum, son[maxN], g[maxN];

struct List {
	int len, fst[maxN], nxt[maxN << 1], v[maxN << 1], w[maxN << 1];
	
	List() { memset(fst, -1, sizeof(fst)); len = 0; }
	inline void insert(int u, int vv, int ww) { v[len] = vv, w[len] = ww, nxt[len] = fst[u], fst[u] = len++; }
	inline void connect(int u, int vv, int ww) { insert(u, vv, ww); insert(vv, u, ww); }
} ls;

void solve(int u, int fa, lol x) {
	for (int i = ls.fst[u]; ~i; i = ls.nxt[i]) {
		int v = ls.v[i];
		if (v != fa) { solve(v, u, x); }
	}
	f[u] = g[u] = num = 0;
	for (int i = ls.fst[u]; ~i; i = ls.nxt[i]) {
		int v = ls.v[i], w = ls.w[i];
		if (v != fa) { f[u] += f[v]; son[++num] = g[v] + w; }	
	}
	if (!num) { return; }
	std::sort(son + 1, son + num + 1);
	int tmp = f[u], res = 0;
	for (int i = 0, j = num; i < j; j--) {
		while (i < j && son[i] + son[j] < x) { i++; }
		if (i < j) { i = i ? i + 1 : 0; f[u]++; }
	}
	for (int l = 1, r = num, mid, now; l <= r; ) {
		mid = l + r >> 1; now = tmp;
		for (int i = 0, j = num; i < j; j--) {
			if (mid == j) { continue; }
			while ((i < j && son[i] + son[j] < x) || mid == i) { i++; }
			if (i < j) { i = i ? i + 1 : 0; now++; }
		}
		if (now >= f[u]) { res = mid, l = mid + 1; } else { r = mid - 1; }
	}
	g[u] = son[res];
}

int main() {
	n = read(), m = read();
	for (int i = 2; i <= n; i++) {
		int u = read(), v = read(), w = read();
		ls.connect(u, v, w); sum += w;
	}
	for (lol l = 1, r = sum, mid; l <= r; ) {
		mid = l + r >> 1; solve(1, 0, mid);
		if (f[1] >= m) { ans = mid, l = mid + 1; } else { r = mid - 1; }
	}
	printf("%lld\n", ans);
	closeFile();
	return 0;
}
