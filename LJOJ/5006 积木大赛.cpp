// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
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

ll readll() {
    ll x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 1010, inf = 1e9;

int n, m;
ll a[maxn];
ll maxh, cnt;
ll L, R, Ans, Mid;
bool flag1, flag2;

bool check(int x) {
	// printf("=== %d ===\n", x);
	for (int i = 1; i <= n; i++) {
		flag1 = flag2 = 0;
		cnt = 0;
		for (int j = i; j >= 1; j--)
			if (a[j] < (x + j - i)) {
				cnt += (x + j - i) - a[j];
				if (cnt > m) break;
			} else {
				flag1 = 1;
				break;
			}
		// printf("> %d %d %d\n", i, cnt, flag1);
		if (a[i] < x) {
			for (int j = i + 1; j <= n; j++) {
				if (a[j] < (x + i - j)) {
					cnt += (x + i - j) - a[j];
					if (cnt > m) break;
				} else {
					flag2 = 1;
					break;
				}
			}
		} else flag2 = 1;
		// printf("> %d %d %d\n", i, cnt, flag2);
		if (flag1 && flag2) {
			// printf("[%d]\n", i);
			return true;
		}
	}
	return false;
}

int main() {
	freopen("block.in", "r", stdin);
	freopen("block.out", "w", stdout);
	// freopen("3.txt", "r", stdin);

	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = readll(), maxh = max(maxh, a[i]);

	L = maxh, R = maxh + n;
	while (L <= R) {
		Mid = (L + R) >> 1;
		// cout << L << " " << Mid << " " << R << endl;
		if (check(Mid)) {
			Ans = Mid;
			L = Mid + 1;
		} else {
			R = Mid - 1;
		}
		// cout << L << " " << R << endl;
	}

	printf("%lld\n", Ans);

	return 0;
}