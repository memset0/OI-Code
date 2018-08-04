#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 110;
int t, n, m, x, ans, a[maxn * maxn], b[maxn * maxn];
void msort(int l, int r) {
    int mid = (l + r) >> 1;
    if (l == r) return ;
    msort(l, mid), msort(mid + 1, r);
    int i = l, j = mid + 1, k = l, r1 = mid, r2 = r;
    while (i <= r1 && j <= r2) {
        while (i <= r1 && a[i] <= a[j]) b[k++] = a[i++];
        while (j <= r2 && a[j] <= a[i]) b[k++] = a[j++], ans += r1 - i + 1;
    }
    while (i <= r1) b[k++] = a[i++];
    while (j <= r2) b[k++] = a[j++];
    for (int i = l; i <= r; i++)
        a[i] = b[i];
}

int main() {
//	freopen("forlove.in", "r", stdin);
//	freopen("forlove.out", "w", stdout);
	t = read();
	while (t--) {
		n = read(), m = 0, ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				x = read();
				if (x) a[++m] = x;
			}
		msort(1, m);
		if (ans % 2) printf("You are destined to be single.\n");
		else printf("You still have a chance.\n");
	}
	return 0;
}

