// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)


char readc() {
    char c;
    while (scanf("%c", &c), c != 'Q' && c != 'C');
    if (c == 'Q') return 0;
    return 1;
}

const int maxn = 10010, maxm = maxn * 400;

#define lowbit(x) ((x)&(-(x)))

int n, m, tn, pos;
int a[maxn], b[maxn << 1], que[2][100];

int val[maxm], lc[maxm], rc[maxm], root[maxn];

struct query {
    int opt;
    int l, r, x;
} q[maxn];

void seg_modify(int &u, int l, int r, int k, int x) {
    if (!u) u = ++pos;
    val[u] += x;
//	printf("val[%d] += %d\n", u, x);
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (k <= mid) seg_modify(lc[u], l, mid, k, x);
    else seg_modify(rc[u], mid + 1, r, k, x);
}

int seg_query(int u[10][100], int l, int r, int k) {
    if (l == r) return l;
    int mid = (l + r) >> 1, sum = 0;
    for (int i = 1; i <= u[0][0]; i++)
        sum -= val[lc[u[0][i]]];
    for (int i = 1; i <= u[1][0]; i++)
        sum += val[lc[u[1][i]]];
//	printf("%d ~ %d ~ %d : sum == %d\n", l, r, k, sum);
    if (k <= sum) {
        for (int i = 1; i <= u[0][0]; i++)
            u[0][i] = lc[u[0][i]];
        for (int i = 1; i <= u[1][0]; i++)
            u[1][i] = lc[u[1][i]];
        return seg_query(u, l, mid, k);
    } else {
        for (int i = 1; i <= u[0][0]; i++)
            u[0][i] = rc[u[0][i]];
        for (int i = 1; i <= u[1][0]; i++)
            u[1][i] = rc[u[1][i]];
        return seg_query(u, mid + 1, r, k - sum);
    }
}

void bit_modify(int k, int x) {
    for (int i = k; i <= n; i += lowbit(i))
        seg_modify(root[i], 1, tn, a[k], -1);
    a[k] = x;
    for (int i = k; i <= n; i += lowbit(i))
        seg_modify(root[i], 1, tn, a[k], 1);
}

int bit_query(int l, int r, int x) {
    memset(que, 0, sizeof(que));
    for (int i = l - 1; i; i -= lowbit(i))
        que[0][++que[0][0]] = root[i];
    for (int i = r; i; i -= lowbit(i))
        que[1][++que[1][0]] = root[i];
    return seg_query(que, 1, tn, x);
}

void bit_build() {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += lowbit(j))
            seg_modify(root[j], 1, tn, a[i], 1);
    }
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
    
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) {
        q[i].opt = readc();
        if (q[i].opt) scanf("%d%d", &q[i].l, &q[i].x), q[i].r = q[i].l;
        else scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].x);
    }
    
    for (int i = 1; i <= n; i++)
        b[++tn] = a[i];
    for (int i = 1; i <= m; i++)
        if (q[i].opt)
            b[++tn] = q[i].x;
    std::sort(b + 1, b + tn + 1);
    tn = std::unique(b + 1, b + tn + 1) - b - 1;
    for (int i = 1; i <= n; i++)
        a[i] = std::lower_bound(b + 1, b + tn + 1, a[i]) - b;
    for (int i = 1; i <= m; i++)
        if (q[i].opt)
            q[i].x = std::lower_bound(b + 1, b + tn + 1, q[i].x) - b;
    
    bit_build();
    for (int i = 1; i <= m; i++) {
        if (q[i].opt) {
            bit_modify(q[i].l, q[i].x);
        } else {
            printf("%d\n", b[bit_query(q[i].l, q[i].r, q[i].x)]);
        }
//		for (int i = 1; i <= n; i++)
//			printf("%d ", bit_query(i, i, 1));
//		puts("");
    }

    return 0;
}
