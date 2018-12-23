// mwh & xay & wyl
#include <bits/stdc++.h>
#define int long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; i++)
namespace ringo {
typedef long long ll;
 
template <class T> void read(T &x) {
    x = 0; register char c = getc(); register bool f = 0;
    while (!isdigit(c)) f ^= c == '-', c = getc();
    while (isdigit(c)) x = x * 10 + c - '0', c = getc();
    if (f) x = -x;
}
template <class T> void print(T x) {
    if (x < 0) putc('-'), x = -x;
    if (x > 9) print(x / 10);
    putc('0' + x % 10);
}
template <class T> void print(T x, char c) { print(x), putc(c); }
template <class T> void maxd(T &a, const T &b) { if (b > a) a = b; }
template <class T> void mind(T &a, const T &b) { if (b < a) a = b; }
 
const int N = 5e4 + 10;
int n, m, tn;
int b[N], ans[N];
 
struct info {
    int op, x, y, z, id;
} q[N];
std::vector <info> v;
 
struct BIT{
    ll tr[N];
    void update(int i,ll x){
        for (;i<=n;i+=i&-i) tr[i]+=x;
    }
    ll query(int i){
        ll res=0;
        for (;i;i&=i-1) res+=tr[i];
        return res;
    }
} t0,t1;
 
ll t[N];
 
void modify(int l,int r,ll x){
//  printf("modify %d %d %d\n", l, r, x);
    t0.update(l,x),t0.update(r+1,-x);
    t1.update(l,x*l),t1.update(r+1,-x*(r+1));
}
 
ll query(int l,int r){
    return (t0.query(r)*(r+1)-t0.query(l-1)*l)-(t1.query(r)-t1.query(l-1));
}
 
void solve(int l, int r, std::vector <info> v) {
    if (l > r) return;
    int mid = (l + r) >> 1;
    std::vector <info> vl, vr;
//  printf(">> %d %d %d\n", l, r, mid);
//  for (auto it : v)
//      printf("> %d %d %d %d %d\n", it.op, it.x, it.y, it.z, it.id);
    for (auto it : v)
        if (it.op == 1) {
            if (it.z > mid) {
                vr.push_back(it);
            } else if (it.z < mid) {
                vl.push_back(it);
            }
            if (it.z < mid) continue;
            modify(it.x, it.y, 1);
        } else {
            ll t = query(it.x, it.y);
//          printf("query %d %d %d\n", it.x, it.y, t);
            if (t >= it.z) {
                ans[it.id] = std::max(ans[it.id], mid);
                vr.push_back(it);
            } else {
                it.z -= t;
                vl.push_back(it);
                it.z += t;
            }
        }
    for (auto it : v)
        if (it.op == 1) {
            if (it.z < mid) continue;
            modify(it.x, it.y, -1);
        }
//  for (int i = 1; i <= n; i++)
//      print(query(i, i), " \n"[i == n]);
    solve(l, mid - 1, vl);
    solve(mid + 1, r, vr);
    vl.clear(), vr.clear();
}
 
void main() {
//  freopen("1.txt", "r", stdin);
    read(n), read(m);
    for (int i = 1, op, x, y, z; i <= m; i++) {
        read(op), read(x), read(y), read(z);
        q[i] = (info){op, x, y, z, i};
        if (op == 1) b[++tn] = z;
    }
    std::sort(b + 1, b + tn + 1);
    tn = std::unique(b + 1, b + tn + 1) - b - 1;
    for (int i = 1; i <= m; i++)
        if (q[i].op == 1)
            q[i].z = std::lower_bound(b + 1, b + tn + 1, q[i].z) - b;
    for (int i = 1; i <= m; i++)
        v.push_back(q[i]);
//  for (int i = 1; i <= m; i++)
//      printf("%d %d %d %d %d\n", q[i].op, q[i].x, q[i].y, q[i].z, q[i].id);
    solve(1, tn, v);
    for (int i = 1; i <= m; i++)
        if (q[i].op == 2)
            print(b[ans[i]], '\n');
}
 
} signed main() { return ringo::main(), 0; }
