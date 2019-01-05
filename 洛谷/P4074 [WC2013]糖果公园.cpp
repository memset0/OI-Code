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

const int maxn = 200010;

int n, m, u, v, l, r, k, t, p, tp, ql, qr, qt, opt, sqn, tim;
int val[maxn], w[maxn], c[maxn], pos[maxn], in[maxn], out[maxn], bln[maxn], dep[maxn], f[maxn][20];
int tmp[maxn], id[maxn], bef[maxn], aft[maxn], cnt[maxn], flag[maxn], tag[maxn];
int tot = 2, hed[maxn], to[maxn], nxt[maxn];
ll now, ans[maxn];

struct query {
	int i, l, r, t, lca;
} q[maxn];
inline bool operator < (const query &a, const query &b) {
	// if (a.t != b.t) return a.t < b.t;

	if (bln[a.l] != bln[b.l]) return a.l < b.l;
	if (bln[a.r] != bln[b.r]) return a.r < b.r;
	return a.t < b.t;
}

void dfs(int u) {
	// printf("dfs %d\n", u);
	pos[++tim] = u, in[u] = tim;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != f[u][0]) {
			f[v][0] = u;
			dep[v] = dep[u] + 1;
			dfs(v);
		}
	pos[++tim] = u, out[u] = tim;
}

int lca(int u, int v) {
	if (dep[u] > dep[v])
		std::swap(u, v);
	for (int i = 19; i >= 0; i--)
		if (dep[f[v][i]] >= dep[u])
			v = f[v][i];
	if (u == v)
		return u;
	for (int i = 19; i >= 0; i--)
		if (f[u][i] != f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}

inline void add_c(int x) {
	// printf("add c %d : %d\n", x, c[x]);
	tag[x] = 1;
	++cnt[c[x]];
	now += 1ll * val[c[x]] * w[cnt[c[x]]];
}

inline void dec_c(int x) {
	// printf("dec c %d : %d\n", x, c[x]);
	now -= 1ll * val[c[x]] * w[cnt[c[x]]];
	--cnt[c[x]];
	tag[x] = 0;
}

inline void add_t(int x) {
	// printf("add t %d\n", x);
	// printf("%lld -> ", now);
	int flag = tag[id[x]];
	// for (int i = 1; i <= n; i++)
	// 	print(cnt[i]);
	// putc('\n');
	if (flag) dec_c(id[x]);
	c[id[x]] = aft[x];
	if (flag) add_c(id[x]);
	// for (int i = 1; i <= n; i++)
	// 	print(cnt[i]);
	// putc('\n');
	// printf("%lld\n", now);
}

inline void dec_t(int x) {
	// printf("dec t %d : %d %d %d\n", x, c[id[x]], bef[x], aft[x]);
	// printf("%lld -> ", now);
	int flag = tag[id[x]];
	// for (int i = 1; i <= n; i++)
	// 	print(cnt[i]);
	// putc('\n');
	if (flag) dec_c(id[x]);
	c[id[x]] = bef[x];
	if (flag) add_c(id[x]);
	// for (int i = 1; i <= n; i++)
	// 	print(cnt[i]);
	// putc('\n');
	// printf("%lld\n", now);
}

inline void add(int x) {
	// printf("add %d\n", x);
	if (flag[pos[x]]) {
		dec_c(pos[x]);
	} else {
		add_c(pos[x]);
	}
	flag[pos[x]] ^= 1;
}

inline void dec(int x) {
	// printf("dec %d\n", x);
	if (flag[pos[x]]) {
		dec_c(pos[x]);
	} else {
		add_c(pos[x]);
	}
	flag[pos[x]] ^= 1;
}

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	read(n), read(m), read(p);
	for (int i = 1; i <= m;	i++)
		read(val[i]);
	for (int i = 1; i <= n; i++)
		read(w[i]);
	for (int i = 1; i < n; i++) {
		read(u), read(v);
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}
	for (int i = 1; i <= n; i++)
		read(c[i]), tmp[i] = c[i];

	dep[1] = 1, dfs(1);	
	for (int i = 1; i <= 19; i++)
		for (int j = 1; j <= n; j++)
			f[j][i] = f[f[j][i - 1]][i - 1];
	
	tim = 0, sqn = pow(n << 1, 2.0 / 3);
	// for (int i = 1; i <= (n << 1); i++)
	// 	print(pos[i]);
	// putc('\n');
	for (int i = 1; i <= (n << 1); i++)
		bln[i] = i / sqn;
	for (int i = 1; i <= p; i++) {
		read(opt);
		if (opt) {
			read(u), read(v);
			++tp, q[tp].i = tp, q[tp].t = tim;
			q[tp].lca = t = lca(u, v);
			if (u == t || v == t) {
				q[tp].l = in[u == t ? v : u] + 1;
				q[tp].r = out[t] - 1;
			} else {
				if (out[u] > out[v])
					std::swap(u, v);
				// printf("%d : %d => %d %d | %d %d\n", u, v, in[u], out[u], in[v], out[v]);
				q[tp].l = in[u] + 1;
				q[tp].r = out[v] - 1;
			}
		} else {
			read(k), read(v);
			id[++tim] = k;
			bef[tim] = tmp[k];
			aft[tim] = tmp[k] = v;
			// for (int i = 1; i <= n; i++)
			// 	print(tmp[i]);
			// putc('\n');
		}
	}

	std::sort(q + 1, q + tp + 1);
	// for (int i = 1; i <= tim; i++)
	// 	printf(">> %d %d %d\n", id[i], bef[i], aft[i]);
	// for (int i = 1; i <= tp; i++)
	// 	printf("%d : %d %d %d\n", q[i].t, q[i].l, q[i].r, q[i].lca);

	ql = 1, qr = 0, qt = 0;
	for (int i = 1; i <= tp; i++) {
		l = q[i].l, r = q[i].r, t = q[i].t;
		// printf("=== %d %d %d ===\n", l, r, t);
		while (ql > l) add(--ql);
		while (qr < r) add(++qr);
		while (ql < l) dec(ql++);
		while (qr > r) dec(qr--);
		while (qt < t) add_t(++qt);
		while (qt > t) dec_t(qt--);
		// for (int i = 1; i <= n; i++)
		// 	print(cnt[i]);
		// putc('\n');
		// for (int i = 1; i <= n; i++)
		// 	print(c[i]);
		// putc('\n');
		// printf("%d %d %d\n", ql, qr, qt);
		add_c(q[i].lca);
		ans[q[i].i] = now;
		dec_c(q[i].lca);
		// printf("--- %lld ---\n", now);
	}
	for (int i = 1; i <= tp; i++)
		print(ans[i], '\n');

	return 0;
}