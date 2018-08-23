// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define sqr(x) ((x)*(x))
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 50010;
int n, cur;
ll l, nxt;
ll a[maxn], s[maxn], f[maxn];
vector < int > g[maxn];

int main() {
	freopen("INPUT", "r", stdin);
	freopen("OUTPUT", "w", stdout);

	n = read(), l = read();
	for (int i = 1; i <= n; i++)
		a[i] = read(), s[i] = s[i - 1] + a[i];

	cur = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = 0x7fffffffffffffff;
		for (int j = cur; j < i; j++) {
			nxt = f[j] + sqr(s[i] + i - s[j] - j - 1 - l);
			if (nxt <= f[i]) {
				f[i] = nxt;
				cout << j << " ";
				// cur = j;
			}
		}
		cout << endl;
		// cout << cur << endl;
		// printf("%lld\n", f[i]);
	}
	printf("%lld\n", f[n]);

	return 0;
}