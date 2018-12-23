// mwh & xay & wyl
#include <bits/stdc++.h>
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; i++)
namespace ringo {
 
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
 
const int N = 1e6 + 10;
int G[N];
inline int ts(int u) {int cnt=1; while(u>3) cnt++,u=u/3; return cnt; }
int g(int x) {
    if (~G[x]) return G[x];
    if(x<=3) return G[x]=2;
    int aa=std::max(ts(x/3),g(x-(x/3)*2));
    int bb=std::max(ts(x/3+1),g(x-(x/3+1)*2));
// 
    return G[x]=std::min(aa,bb)+1;
}
int f(int x) {
    if (x <= 2) return 1e9 + 7;
    if (x == 3) return 2;
    if (4 <= x && x <= 7) return 3;
    int aa=std::max(ts(x/3),g(x-(x/3)*2));
    int bb=std::max(ts(x/3+1)+1,g(x-(x/3+1)*2));
//  printf("%d %d ccc",aa,bb);
    return std::min(aa,bb)+1;
}
 
void main() {
    memset(G, -1, sizeof(G));
    int x, y;
//  cout<<f(8)<<endl;
//  f(8);
//  for (int i = 1; i <= 30; i++)
//      printf("%d %d\n", i, f(i));
    while (~scanf("%d%d", &x, &y)) {
        int ans = f(x);
//      std::cout << ans << std::endl;
        if (ans <= y) printf("Yes\n");
        else printf("No\n");
    }
}
 
} signed main() { return ringo::main(), 0; }
