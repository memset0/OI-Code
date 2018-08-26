#include <bits/stdc++.h>
#define ll long long
//typedef int INT;
//#define int long long
using namespace std;
ll read(void) {
    ll x = 0;
    char c = getchar();
    bool m = 0;
    while (!isdigit(c) && c != '-')
        c = getchar();
    if (c == '-') {
        c = getchar();
        m = true;
    }
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    if (m) return -x;
    else return x;
}
const int maxn = 100010;
int n, m, opt, x, y;
ll k, Mod, a[maxn], s[maxn];
struct Node {
    int l, r, mid;
    ll ans, mul, sum;
} p[maxn << 3];
void print() {
//	printf("val[] = ");
//	for (int i = 1; i <= n; i++)
//		printf("%d ", query(1, i, i));
//	puts("");
    for (int i = 1; i <= (n << 3); i++)
        if (p[i].mid)
            printf("p[%d]=%d-%d %lld %lld %lld\n", i, p[i].l, p[i].r, p[i].ans, p[i].mul, p[i].sum);
}
void pushup(int u, ll mul, ll sum) {
//	cout << "[" << u << " " << mul << " " << sum << " " << p[u].ans << " " << p[u].mul << " " << p[u].sum << "]";
    p[u].ans = ((p[u].ans * mul) % Mod + sum * (p[u].r - p[u].l + 1)) % Mod;
    p[u].mul = (p[u].mul * mul) % Mod;
    p[u].sum = ((p[u].sum * mul) % Mod + sum) % Mod;
//	cout << "[" << u << " " << mul << " " << sum << " " << p[u].ans << " " << p[u].mul << " " << p[u].sum << "]\n";
}
void pushdown(int u) {
    if (p[u].mul != 1 || p[u].sum != 0) {
        pushup(u << 1, p[u].mul, p[u].sum);
        pushup(u << 1 | 1, p[u].mul, p[u].sum);
        p[u].mul = 1, p[u].sum = 0;
//		print();
    }
}
void build(int u, int l, int r) {
//	cout << "Build " << u << " " << l << " " << r << endl;
    p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
    p[u].ans = (s[r] - s[l - 1] + Mod) % Mod, p[u].sum = 0, p[u].mul = 1;
    if (p[u].l == p[u].r) return ;
    build(u << 1, l, p[u].mid);
    build(u << 1 | 1, p[u].mid + 1, r);
}
void update(int u, int l, int r, ll mul, ll sum) {
//	cout << "Update " << u << "(" << p[u].l << "," << p[u].r << ") " << l << " " << r << " " << mul << " " << sum << endl;
    pushdown(u);
    if (l == p[u].l && r == p[u].r) {
        pushup(u, mul, sum);
        return;
    }
    if (r <= p[u].mid) update(u << 1, l, r, mul, sum);
    else if (l > p[u].mid) update(u << 1 | 1, l, r, mul, sum);
    else {
        update(u << 1, l, p[u].mid, mul, sum);
        update(u << 1 | 1, p[u].mid + 1, r, mul, sum);
    }
    p[u].ans = (p[u << 1].ans + p[u << 1 | 1].ans) % Mod;
}
ll query(int u, int l, int r) {
    pushdown(u);
//	cout << "Query " << u << " " << p[u].ans << " " << p[u].l << " " << p[u].r << " " << l << " " << r << endl;
    if (l == p[u].l && r == p[u].r)
        return p[u].ans;
    if (r <= p[u].mid) return query(u << 1, l, r);
    else if (l > p[u].mid) return query(u << 1 | 1, l, r);
    else return (query(u << 1, l, p[u].mid) + query(u << 1 | 1, p[u].mid + 1, r)) % Mod;
}
int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("TESTDATA2.in", "r", stdin); 
    n = read(), Mod = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), s[i] = (s[i - 1] + a[i]) % Mod; 
    build(1, 1, n);
    m = read();
//	print();
    for (int i = 1; i <= m; i++) {
        opt = read();
        if (opt == 1) {
            x = read(), y = read(), k = read();
//			cout << ">> " << opt << " " << x << " " << y << " " << k << endl;
            update(1, x, y, k % Mod, 0);
        } else if (opt == 2) {
            x = read(), y = read(), k = read();
//			cout << ">> " << opt << " " << x << " " << y << " " << k << endl;
            update(1, x, y, 1, k % Mod);
        } else {
            x = read(), y = read();
//			cout << ">> " << opt << " " << x << " " << y << endl;
            printf("%lld\n"	, query(1, x, y));
        }
//		print();
    }
    return 0;
}