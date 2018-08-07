// ==============================
//  author: memset0
//  website: https://memset0.cn
//  date: 2018.08.07 15:19:16
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
int n, l, r, cnt, ans, a[maxn], q[maxn];
vector < int > b[maxn];

int main() {
	// freopen("INPUT", "r", stdin);
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read(), b[a[i]].push_back(i);
	for (int i = 1; i <= 1e6; i++)
		if (b[i].size()) {
			cnt = 0;
			for (auto it = b[i].rbegin(); it != b[i].rend(); it++) {
				int k = *it;
				while (l <= r && q[r] > k) {
					while (l < r && a[q[l]] < a[q[r]]) l++;
					r--;
				}
				ans = max(ans, r - l + 1 + (++cnt));
			}
			for (auto it = b[i].begin(); it != b[i].end(); it++)
				q[++r] = *it;
		}
	printf("%d\n", n - ans);
	return 0;
}