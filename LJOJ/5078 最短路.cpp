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

const int maxn = 100010;
const int p1 = 1000000007;
const int p2 = 20040301;

int n, m, u, v, w;
ll full_dis, old_full_dis, new_full_dis;

struct hash_item {
	int a, b;
	inline hash_item operator + (const hash_item &other) {
		return hash_item{(a + other.a) % p1, (b + other.b) % p2};
	}
	inline hash_item operator * (const hash_item &other) {
		return hash_item{1ll * a * other.a % p1, 1ll * b * other.b % p2};
	}
	inline bool operator == (const hash_item &other) {
		return a == other.a && b == other.b;
	}
	inline void operator = (const int &other) {
		a = b = other;
	}
} full_sum;

ll dis1[maxn]; hash_item sum1[maxn]; bool tag1[maxn];
ll dis2[maxn]; hash_item sum2[maxn]; bool tag2[maxn];
int tot1 = 2, hed1[maxn], to1[maxn], val1[maxn], nxt1[maxn];
int tot2 = 2, hed2[maxn], to2[maxn], val2[maxn], nxt2[maxn];

inline void add_edge(int u, int v, int w) {
	nxt1[tot1] = hed1[u], to1[tot1] = v, val1[tot1] = w, hed1[u] = tot1++;
}

inline void add_reverse_edge(int u, int v, int w) {
	nxt2[tot2] = hed2[u], to2[tot2] = v, val2[tot2] = w, hed2[u] = tot2++;
}

struct status {
	int s;
	ll v;
};
inline bool operator < (const status &a, const status &b) {
	return a.v > b.v;
}
std::priority_queue < status > q;

struct edge {
	int u, v, w;
};
std::vector < edge > e;


void spfa(int s, ll dis[], hash_item sum[], bool tag[], int hed[], int to[], int val[], int nxt[]) {
	dis[s] = 0, sum[s] = 1;
	q.push(status{s, 0});
	while (q.size()) {
		u = q.top().s, q.pop();
		if (tag[u]) continue;
		tag[u] = true;
//		printf(">>> %d %d %d\n", u, dis[u], sum[u]);
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
//			printf("%d -> %d : %d\n", u, v, dis[v]);
			if (dis[u] + val[i] < dis[v] || !~dis[v]) {
				dis[v] = dis[u] + val[i];
				sum[v] = sum[u];
				q.push(status{v, dis[v]});
			} else if (dis[u] + val[i] == dis[v]) {
				sum[v] = sum[v] + sum[u];
			}
		}
	}
//	printf("dis[] = "); for (int i = 1; i <= n; i++) print(dis[i]); putc('\n');
//	printf("sum[] = "); for (int i = 1; i <= n; i++) print(sum[i].a); putc('\n');
}

int re_calc(int u, int v, int w) {
	old_full_dis = dis1[u] + w + dis2[v];
	new_full_dis = dis1[v] + w + dis2[u];
	if (new_full_dis < full_dis)
		return -1;
	if (new_full_dis == full_dis)
		return 0;
	if (old_full_dis > full_dis)
		return 0;
	// ? old_full_dis == full_dis && new_full_dis > full_dis ?
	if (sum1[u] * sum2[v] == full_sum)
		return 1;
	return 0;
}

int main() {
	// freopen("route.in", "r", stdin);
	// freopen("route.out", "w", stdout);
//	freopen("3.txt", "r", stdin);
//	freopen("1.txt", "w", stdout);
	
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(u), read(v), read(w);
		add_edge(u, v, w);
		add_reverse_edge(v, u, w);
		e.push_back(edge{u, v, w});
	}
	for (int i = 1; i <= n; i++)
		dis1[i] = dis2[i] = 100000000000000000ll;
	spfa(1, dis1, sum1, tag1, hed1, to1, val1, nxt1);
	spfa(2, dis2, sum2, tag2, hed2, to2, val2, nxt2);
	full_dis = dis1[2];
	full_sum = sum1[2];
//	std::cerr << full_dis << std::endl;
	for (std::vector < edge > ::iterator it = e.begin(); it != e.end(); it++) {
		print(re_calc(it->u, it->v, it->w), '\n');
	}
	
	return 0;
}
