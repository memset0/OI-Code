#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, m, l, r;
char d;
long long a[maxn], s[maxn], c, ans;
struct Node {
    int l, r, mid;
    long long val, dt;
} p[maxn * 8];
void build (int u, int l, int r) {
    p[u].l = l, p[u].r = r, p[u].mid = (l + r) / 2, p[u].dt = 0;
    p[u].val = s[r] - s[l - 1];
    if (l == r) return ;
    build(u << 1, l, p[u].mid);
    build((u << 1) + 1, p[u].mid + 1, r);
}
void update(int u, int l, int r, long long c) {
    if (l == p[u].l && r == p[u].r) {
        p[u].dt += c;
        return ;
    } else p[u].val += c * (r - l + 1);
//	printf(">> %d %d => [%d %d %d, %d %d]\n", l, r, u, p[u].l, p[u].r, p[u].val, p[u].dt);
    if (r <= p[u].mid) update(u << 1, l, r, c);
    else if (l > p[u].mid) update((u << 1) + 1, l, r, c);
    else {
        update(u << 1, l, p[u].mid, c);
        update((u << 1) + 1, p[u].mid + 1, r, c);
    }
}
void query(int u, int l, int r) {
    if (p[u].dt) {
        p[u].val += p[u].dt * (p[u].r - p[u].l + 1);
        p[u << 1].dt += p[u].dt;
        p[(u << 1) + 1].dt += p[u].dt;
        p[u].dt = 0;
    }
//	printf(">> %d %d => [%d %d %d, %d]\n", l, r, u, p[u].l, p[u].r, p[u].val);
    if (l == p[u].l && r == p[u].r) {
        ans += p[u].val;
        return ;
    }
    if (r <= p[u].mid) query(u << 1, l, r);
    else if (l > p[u].mid) query((u << 1) + 1, l, r);
    else {
        query(u << 1, l, p[u].mid);
        query((u << 1) + 1, p[u].mid + 1, r);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
    	scanf("%lld", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &d);
        if (d == 1) {
            scanf("%d%d%d", &l, &r, &c);
            update(1, l, r, c);
        } else {
            scanf("%d%d", &l, &r);
            ans = 0;
            query(1, l, r);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
