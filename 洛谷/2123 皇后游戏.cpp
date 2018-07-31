#include <bits/stdc++.h>
#define isnum(x) ('0' <= x && x <= '9')
#define read(x) do { \
	x = 0, rr::c = getchar(), rr::m = 0; \
	while (!isnum(rr::c) && rr::c != '-') rr::c = getchar(); \
	if (rr::c == '-') rr::m = 1; \
	while (isnum(rr::c)) x = x * 10 + rr::c - '0', rr::c = getchar(); \
	if (rr::m) x = -x; \
} while (false)
namespace rr { char c; bool m; }
using namespace std;

const int maxn = 50010;
long long t, n, f[maxn], sum;
struct Node{
    long long a, b;
} a[maxn];
bool cmp(Node x, Node y){
    return min(x.a, y.b) < min(y.a, x.b);
}

int main() {
	
    read(t);
    while (t--) {
        read(n);
        for(int i = 1; i <= n; i++) {
        	read(a[i].a);
        	read(a[i].b);
		}
        sort(a + 1, a + n + 1, cmp);
        sum = f[0] = 0;
        for(int i = 1; i <= n; i++){
            sum += a[i].a;
            f[i] = max(f[i - 1], sum) + a[i].b;
        }
        printf("%lld\n", f[n]);
    }
    return 0;
}
