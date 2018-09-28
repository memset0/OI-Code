// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define il inline
#define re register 
#define DEBUG std::cerr << std::clock() << endl
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

namespace FastIO  {
    const size_t str = 1 << 20;
 
    struct Reader  {
        char buf[str], *s, *t;
        Reader ( ) : s( ), t( ), buf() {    }
        inline char pick ( )  {
            return (s == t) ? ( t = buf + fread ( s = buf, 1, str , stdin ), *s++ ) : ( *s++ );
        }
 
        template < class T >
        inline Reader& operator >> ( T& x )  {
            static char ch;
            static short opt;
            opt = (ch != 45);
            while ( !isdigit ( ch = pick () ) && (ch ^ -1) && ( ch ^ 45 ) );
            if ( ch == -1 )     return *this;
            if ( ch == 45 )     {   opt = 0; ch = pick ();   }
            for ( x = -48 + ch; isdigit ( ch = pick () ); ( x *= 10 ) += ch - 48 );
            opt ? 1 : x = -x;
            return *this;
        }
 
    } cin;
 
    struct Writer  {
        char buf[str], *s, *t;
        Writer () : s ( buf ), t( buf + str ), buf ( ) {    }
        ~Writer () { fwrite( buf, 1, s - buf, stdout ); }
 
        inline void echo ( char c )  {
            ( s == t ) ? ( fwrite ( s = buf, 1, str, stdout ), *s++ = c ) : ( *s++ = c );
        }
 
        inline Writer& operator << ( long long x )  {
            if( !x ) return echo( 48 ), *this;
            static int t[21], top;
            if (x < 0) x = -x, echo ( '-' );
            while ( x ) t[++top] = x % 10, x /= 10;
            while ( top ) echo(t[top--] + 48);
            return *this;
        }
        inline Writer& operator << (const char* s)  {
            while ( *s ) echo( *s++ ) ;
            return *this;
        }
    } cout;
    const char *endl = "\n";
} 

using FastIO::cin;
using FastIO::cout;
using FastIO::endl;

const int N = 200010, M = 500010, E = N * 30;

int n, m, p, u, v, w, t, x, k, tn, cnt, pos, ord, lastans;
int b[N], fa[N], id[N], wid[N], val[N], siz[N];
int f[N][20], g[N][20];
int lc[E], rc[E], sum[E], root[N];
bool vis[N];

struct edge {
	int u, v, w;
} e[M];
bool operator < (const edge &a, const edge &b) {
	return a.w < b.w;
}

int tot = 2, hed[N], nxt[N << 1], to[N << 1];
il void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
//	printf("add edge %d %d\n", u, v);
}

il int find(int u) {
	if (fa[u] == u) return u;
	return fa[u] = find(fa[u]);
}

void dfs(int u) {
	siz[u] = 1, id[u] = ++pos, wid[id[u]] = u, vis[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v ^ f[u][0]) {
			f[v][0] = u;
			g[v][0] = (u <= n ? 0 : val[u]);
			dfs(v);
			siz[u] += siz[v];
		}
}

void build(int &u, int v, int l, int r, int k) {
	u = ++ord, lc[u] = lc[v], rc[u] = rc[v], sum[u] = sum[v] + 1;
//	printf("build(%d %d %d %d %d %d)\n", u, v, l, r, sum[u], k);
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (k <= mid) build(lc[u], lc[v], l, mid, k);
	else build(rc[u], rc[v], mid + 1, r, k);
}

int query(int u, int v, int l, int r, int k) {
	if (l == r) return (k <= (sum[v] - sum[u]) ? b[l] : -1);
	if (l == r) return l;
	int mid = (l + r) >> 1, tmp;
//	printf("query(%d %d %d %d %d %d %d)\n", u, v, l, r, k, sum[rc[v]] - sum[rc[u]]);
	tmp = sum[rc[v]] - sum[rc[u]];
	if (k <= tmp)
		return query(rc[u], rc[v], mid + 1, r, k);
	else
		return query(lc[u], lc[v], l, mid, k - tmp);
}

int main() {
//	freopen("C:\\Users\\surface\\Desktop\\Temp\\data\\data\\1.in", "r", stdin);
//	freopen("C:\\Users\\surface\\Desktop\\Temp\\data\\data\\5.ans", "w", stdout);
//	freopen("INPUT", "r", stdin);

	cin >> n >> m >> p;
	for (re int i = 1; i <= n; i++)
		cin >> val[i];
	for (re int i = 1; i <= m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	
	std::sort(e + 1, e + m + 1);
	for (re int i = 1; i <= (n << 1); i++)
		fa[i] = i;
	cnt = n;
	
	for (re int i = 1; i <= n; i++)
		b[i] = val[i];
	std::sort(b + 1, b + n + 1);
	tn = std::unique(b + 1, b + n + 1) - b - 1;
	for (re int i = 1; i <= n; i++)
		val[i] = std::lower_bound(b + 1, b + tn + 1, val[i]) - b;
	
	for (re int i = 1; i <= m; i++) {
		u = e[i].u, v = e[i].v, w = e[i].w;
		if  (find(u) ^ find(v)) {
			t = ++cnt;
			u = find(u), v = find(v);
//			printf("== %d %d %d ==\n", u, v, w);
			fa[u] = fa[v] = t;
			add_edge(u, t);
			add_edge(v, t);
			val[t] = w;
		}
	}

	val[++cnt] = 1e9;
	for (re int i = 1; i < cnt; i++)
		if (find(i) != find(cnt)) {
			add_edge(find(i), cnt);
			fa[find(i)] = find(cnt);
		}
		
	dfs(cnt);
	for (re int i = 1; i <= cnt; i++)
		if (wid[i] <= n)
			build(root[i], root[i - 1], 1, tn, val[wid[i]]);
		else
			root[i] = root[i - 1];
			
	for (re int i = 1; i <= 19; i++)
		for (re int j = 1; j <= cnt; j++) {
			f[j][i] = f[f[j][i - 1]][i - 1];
			g[j][i] = std::max(g[j][i - 1], g[f[j][i - 1]][i - 1]);
		}

//	DEBUG;
	for (re int i = 1; i <= p; i++) {
		cin >> u >> x >> k;
		if (~lastans) {
			u ^= lastans;
			x ^= lastans;
			k ^= lastans;
		}
//		printf("%d %d %d\n", u, x, k);
		for (re int i = 19; i >= 0; i--)
			if (x >= g[u][i] && f[u][i]) {
//				printf("%d -> %d %d\n", u, f[u][i], g[u][i]);
				u = f[u][i];
			}
//		printf("=> %d %d %d\n", u, val[u], x);
		cout << (lastans = query(root[id[u] - 1], root[id[u] + siz[u] - 1], 1, tn, k)) << endl;
	}
//	DEBUG;
//	
//	for (int i = 1; i < (n << 1); i++) print(id[i]); putc('\n');
//	for (int i = 1; i < (n << 1); i++) print(id[i] + siz[i] - 1); putc('\n');
//	std::cerr << pos << " " << cnt << " " << ord << endl;

	return 0;
}
