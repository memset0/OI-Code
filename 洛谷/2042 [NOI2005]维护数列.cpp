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

	void read_opt(int &x) {
		register char ch;
		while (ch = cin.pick(), !isupper(ch));
		if (ch == 'I') x = 1;
		else if (ch == 'D') x = 2;
		else if (ch == 'R') x = 4;
		else if (ch == 'G') x = 5;
		else {
			cin.pick(), ch = cin.pick();
			if (ch == 'K') x = 3;
			else x = 6;
		}
		while (ch = cin.pick(), ch != '\n' && ch != ' ');
	}
} 

using FastIO::cin;
using FastIO::cout;
using FastIO::endl;
using FastIO::read_opt;

const int maxn = 500010;

#define inf (1000000000)
#define max2(a,b) std::max(a,b)
#define max3(a,b,c) std::max(a,std::max(b,c))

int n, m, x, y, z, k, l, v, rt, cnt, opt, top;
int a[maxn], stk[maxn];
int siz[maxn], val[maxn], rnd[maxn], ch[maxn][2];
int sum[maxn], lmax[maxn], rmax[maxn], smax[maxn];
int tag[maxn], rev[maxn];

inline int newnode(int v) {
	int u = top ? stk[top--] : ++cnt;
	siz[u] = 1, val[u] = v, rnd[v] = rand();
	lmax[u] = rmax[u] = smax[u] = v;
	ch[u][0] = ch[u][1] = 0;
	rev[u] = 0, tag[u] = inf;
	return u;
}

inline void pushup_tag(int u, int v) {
	if (!u) return;
	tag[u] = val[u] = v, rev[u] = 0;
	sum[u] = v * siz[u];
	lmax[u] = rmax[u] = smax[u] = std::max(val[u], sum[u]);
}

inline void pushup_rev(int u) {
	if (!u) return;
	rev[u] ^= 1;
	std::swap(ch[u][0], ch[u][1]);
	std::swap(lmax[u], rmax[u]);
}

inline void pushdown(int u) {
	if (tag[u] ^ inf) {
//		printf("pushdown tag %d(%d)\n", u, val[u]);
		pushup_tag(ch[u][0], tag[u]);
		pushup_tag(ch[u][1], tag[u]);
		tag[u] = inf;
	}
	if (rev[u]) {
//		printf("pushdown rev %d(%d)\n", u, val[u]);
		pushup_rev(ch[u][0]);
		pushup_rev(ch[u][1]);
		rev[u] = 0;
	}
}

inline void update(int u) {
	pushdown(u);
	siz[u] = siz[ch[u][0]] + siz[ch[u][1]] + 1;
	sum[u] = sum[ch[u][0]] + sum[ch[u][1]] + val[u];
	lmax[u] = max2(lmax[ch[u][0]], sum[ch[u][0]] + val[u] + std::max(lmax[ch[u][1]], 0));
	rmax[u] = max2(rmax[ch[u][1]], sum[ch[u][1]] + val[u] + std::max(rmax[ch[u][0]], 0));
	smax[u] = max3(smax[ch[u][0]], smax[ch[u][1]], max2(rmax[ch[u][0]], 0) + val[u] + max2(lmax[ch[u][1]], 0));
}

int build(int l, int r) {
	if (l > r) return 0;
	int mid = (l + r) >> 1;
	int u = newnode(a[mid]);
	ch[u][0] = build(l, mid - 1);
	ch[u][1] = build(mid + 1, r);
	return update(u), u;
}

int merge(int x, int y) {
	if (!x || !y) return x | y;
	if (rnd[x] < rnd[y]) {
		pushdown(x);
		ch[x][1] = merge(ch[x][1], y);
		return update(x), x;
	} else {
		pushdown(y);
		ch[y][0] = merge(x, ch[y][0]);
		return update(y), y;
	}
}

void split(int u, int v, int &x, int &y) {
	if (!u) return (void)(x = y = 0);
	pushdown(u);
	if (v > siz[ch[u][0]]) {
		x = u, split(ch[x][1], v - siz[ch[u][0]] - 1, ch[x][1], y);
	} else {
		y = u, split(ch[y][0], v, x, ch[y][0]);
	}
	update(u);
}

void dfs(int u) {
	pushdown(u);
//	update(u);
	if (ch[u][0]) dfs(ch[u][0]);
//	printf("%d : %d %d %d\n", u, val[u], sum[u], siz[u]);
//	cout << val[u];
	if (ch[u][1]) dfs(ch[u][1]);
}

void dfs_ryc(int u) {
	if (ch[u][0]) dfs_ryc(ch[u][0]);
	stk[++top] = u;
	if (ch[u][1]) dfs_ryc(ch[u][1]);
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
	srand(20040725);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	rt = build(1, n);
	lmax[0] = rmax[0] = smax[0] = -inf;
	for (int i = 1; i <= m; i++) {
		read_opt(opt);
		switch (opt) {
			case 1:
				cin >> k >> n;
				for (int i = 1; i <= n; i++)
					cin >> a[i];
				split(rt, k, x, z);
				y = build(1, n);
				rt = merge(x, merge(y, z));
				break;
			case 2:
				cin >> k >> v;
				split(rt, k - 1, x, y);
				split(y, v, y, z);
				if (y) dfs_ryc(y);
				rt = merge(x, z);
				break;
			case 3:
				cin >> k >> l >> v;
				split(rt, k - 1, x, y);
				split(y, l, y, z);
				pushup_tag(y, v);
				rt = merge(x, merge(y, z));
				break;
			case 4:  
				cin >> k >> l;
				split(rt, k - 1, x, y);
				split(y, l, y, z);
				pushup_rev(y);
				rt = merge(x, merge(y, z));
				break;
			case 5:
				cin >> k >> l;
				split(rt, k - 1, x, y);
				split(y, l, y, z);
				cout << sum[y] << endl;
				rt = merge(x, merge(y, z));
				break;
			case 6:
				cout << smax[rt] << endl;
				break;
		}
//		dfs(rt), putc('\n');
//		printf("%d %d %d\n", lmax[0], rmax[0], smax[0]);
	}

	return 0;
}
