// ==============================
//  author: memset0
//  website: https://memset0.cn
//  date: 2018.08.07 14:22:32
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 1e6 + 10;
int n, m, l, r, cnt, ans, a[maxn], q[maxn];
vector < int > b[maxn];

int main() {
	// freopen("INPUT", "r", stdin);
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		b[a[i]].push_back(i);
		m = max(m, a[i]);
	}
	l = 1, r = 0;
	for (int i = 1; i <= m; i++) 
		if (b[i].size()) {
			cnt = 0;
			for (auto it = b[i].rbegin(); it != b[i].rend(); it++) {
				int i = *it;
				// printf("%d %d\n", i, q[r]);
				while (l <= r && q[r] > i) {
					while (l <= r && a[q[l]] < a[q[r]]) l++;
					r--;
				}
				cnt++;
				ans = max(ans, r - l + 1 + cnt);
			}
			for (auto it = b[i].begin(); it != b[i].end(); it++) {
				q[++r] = *it;
			}
			// for (int i = l; i <= r; i++)
			// 	printf("%d(%d) ", q[i], a[q[i]]);
			// printf("%d => %d\n", i, ans);
		}
	printf("%d\n", n - ans);
	return 0;
}