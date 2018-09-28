// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
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

const int maxn = 50010;

#define lc e[u].ch[0]
#define rc e[u].ch[1]

int n, m, a, b, c, x, y, z, rt, top, cnt, FG;
int stk[maxn];

struct point {
	int a[2], v;
	point () {}
	point (int x, int y, int z) {
		a[0] = x, a[1] = y, v = z;
	}
} p[maxn];
bool operator < (const point &a, const point &b) {
	return a.a[FG] < b.a[FG];
}

struct node {
	int min[2], max[2], ch[2], cnt;
	ll sum; point x;
} e[maxn];

void update(int u) {
	for (int i = 0; i ^ 2; i++) {
		e[u].min[i] = e[u].max[i] = e[u].x.a[i];
		if (lc) e[u].min[i] = std::min(e[u].min[i], e[lc].min[i]);
		if (rc) e[u].min[i] = std::min(e[u].min[i], e[rc].min[i]);
		if (lc) e[u].max[i] = std::max(e[u].max[i], e[lc].max[i]);
		if (rc) e[u].max[i] = std::max(e[u].max[i], e[rc].max[i]);
	}
	e[u].sum = e[lc].sum + e[rc].sum + e[u].x.v;
	e[u].cnt = e[lc].cnt + e[rc].cnt + 1;
}

int newnode(const point &x) {
	int u = top ? stk[top--] : ++cnt;
	lc = rc = 0, e[u].x = x;
	return update(u), u;
}

void pia(int u, int k) {
	if (lc) pia(lc, k);
	p[k + e[lc].cnt] = e[u].x, stk[++top] = u;
	if (rc) pia(rc, e[lc].cnt + k + 1);
}

int build(int l, int r, int flag) {
	if (l > r) return 0;
	int mid = (l + r) >> 1;
	FG = flag, std::nth_element(p + l, p + mid, p + r + 1);
	int u = newnode(p[mid]);
	lc = build(l, mid - 1, flag ^ 1);
	rc = build(mid + 1, r, flag ^ 1);
	return update(u), u;
}

void check(int &u, int flag) {
	static int ratio = 3;
	if (e[lc].cnt * ratio < e[rc].cnt || e[rc].cnt * ratio < e[u].cnt)
		pia(u, 1), u = build(1, e[u].cnt, flag);
}

void insert(int &u, const point &x, int flag) {
	if (!u) { u = newnode(x); return; }
	insert(e[u].ch[e[u].x.a[flag] <= x.a[flag] ? 0 : 1], x, flag ^ 1);
	update(u), check(u, flag);
}

bool in(ll a, ll b, ll c, int x, int y, int p, int q) {
	return (a * x + b * y < c) && (a * p + b * q < c) &&
		(a * x + b * q < c) && (a * p + b * y < c);
}

bool out(ll a, ll b, ll c, int x, int y, int p, int q) {
	return (a * x + b * y >= c) && (a * p + b * q >= c) &&
		(a * x + b * q >= c) && (a * p + b * y >= c);
}

ll query(int u, ll a, ll b, ll c) {
	if (!u) return 0;
//	std::cerr << e[lc].cnt << ' ' << e[rc].cnt << endl;
//	printf("query %d %d %d %d %d %d %d %d\n", u, a, b, c, e[u].min[0], e[u].min[1], e[u].max[0], e[u].max[1]);
	if (in(a, b, c, e[u].min[0], e[u].min[1], e[u].max[0], e[u].max[1])) return e[u].sum;
	if (out(a, b, c, e[u].min[0], e[u].min[1], e[u].max[0], e[u].max[1])) return 0;
	return (a * e[u].x.a[0] + b * e[u].x.a[1] < c ? e[u].x.v : 0) +
		query(lc, a, b, c) + query(rc, a, b, c);
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);

	cin >> n >> m;
//	std::cerr << std::clock() << endl;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y >> z;
		p[i] = point(x, y, z);
	}
	rt = build(1, n, 0);
//	for (int i = 1; i <= n; i++) {
//		read(x), read(y), read(z);
//		insert(rt, point(x, y, z), 0);
//	}
//	std::cerr << std::clock() << endl;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c; 
//		query(rt, a, b, c);
		cout << query(rt, a, b, c) << endl;
	}
//	std::cerr << std::clock() << endl;

	return 0;
}
