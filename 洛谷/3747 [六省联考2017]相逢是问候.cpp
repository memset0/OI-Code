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

int n, m, c, p, l, r, opt, maxp;
bool flag;

int a[maxn], phi[50];

struct node {
    int l, r, mid;
    int min, sum;
} e[maxn << 2]; 

int pow(int a, int b, int p) { // p => phi[p]
    int cnt;
	ll y = 1;
    while (b) {
        if (b & 1) {
            y = y * val[p][cnt];
            if (y > p) {
                flag = 1;
                y %= p;
            }
        }
        ++cnt;
        flag |= tag[p][cnt];
        b >>= 1;
    }
    return y;
}

int calc(int x, int k) {
//	printf("calc %d %d %d\n", x, k, phi[k]);
    if (x > phi[k + 1]) x = x % phi[k + 1] + phi[k + 1]; 
    for (int i = 1; i <= k; i++) {
        flag = 0;
        x = pow(c, x, k + 1 - i);
        if (flag) x += phi[k + 1 - i];
    }
//	printf("=> %d\n", x);
    return x % p;
}

void build(int u, int l, int r) {
    e[u].l = l, e[u].r = r, e[u].mid = (l + r) >> 1;
    if (l == r) { e[u].sum = a[l] % p; return; }
    build(u << 1, l, e[u].mid);
    build(u << 1 | 1, e[u].mid + 1, r);
    e[u].sum = (e[u << 1].sum + e[u << 1 | 1].sum) % p;
}

void modify(int u, int l, int r) {
    if (e[u].min >= maxp) return;
    if (e[u].l == e[u].r) {
        e[u].min++;
        e[u].sum = calc(a[l], e[u].min);
        return;
    }
    if (r <= e[u].mid) modify(u << 1, l, r);
    else if (l > e[u].mid) modify(u << 1 | 1, l, r);
    else {
        modify(u << 1, l, e[u].mid);
        modify(u << 1 | 1, e[u].mid + 1, r);
    }
    e[u].sum = (e[u << 1].sum + e[u << 1 | 1].sum) % p;
    e[u].min = std::min(e[u << 1].min, e[u << 1 | 1].min);
}

int query(int u, int l, int r) {
    if (e[u].l == l && e[u].r == r)
        return e[u].sum;
    if (r <= e[u].mid) return query(u << 1, l, r);
    else if (l > e[u].mid) return query(u << 1 | 1, l, r);
    else return (query(u << 1, l, e[u].mid) +
        query(u << 1 | 1, e[u].mid + 1, r)) % p;
}

int calc_phi(int x) {
    if (x == 1) return 1;
    int t = x;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) {
            t = t / i * (i - 1);
            while (x % i == 0)
                x /= i;
        }
    if (x ^ 1)
        t = t / x * (x - 1);
    return t;
}

void init() {
    phi[++maxp] = p;
    while (phi[maxp] ^ 1)
        phi[maxp + 1] = calc_phi(phi[maxp]), ++maxp;
    phi[++maxp] = 1;
    phi[maxp + 1] = 1;
    build(1, 1, n);
    for (int i = 1; i <= maxp; i++) {
    	int b = phi[i] << 1, cnt = 0;
    	val[i][1] = 1;
    	while (b) {
    		b
		}
	}
}

int main() {
    cin >> n >> m >> p >> c;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init();
    for (int i = 1; i <= m; i++) {
        cin >> opt >> l >> r;
        if (opt) {
            cout << query(1, l, r) << endl;
        } else {
            modify(1, l, r);
        }
    }
    return 0;
}
