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
const int maxn = 10010, maxm = 100010;
int n, m, u, v, l, r, cnt, ans, final_ans, q[maxn];
bool dis[maxn], val[maxn];
vector < int > g[maxn];
int main() {
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) 
		if (!dis[i]) {
//			cout << '!';
			l = r = dis[i] = val[i] = 1, q[1] = i, cnt = ans = 1;
			while (l <= r && ans != -1) {
				u = q[l++];
				for (vector < int > ::iterator it = g[u].begin(); it != g[u].end(); it++) {
					if (!dis[v = *it]) {
						dis[v] = 1;
						cnt++;
						val[v] = val[u] ^ 1;
//						cout << val[u] << " " << val[v] << endl;
//						cout << ans << " ";
						ans += val[v];
//						cout << ans << " " << val[v] << endl;
						q[++r] = v;
					} else {
						if (val[v] != (val[u] ^ 1)) {
							ans = -1;
							break;
						}
					}
				}
			}
			if (ans == -1) {
				final_ans = -1;
				break;
			}
//			printf("ans = %d cnt = %d\n", ans, cnt);
			final_ans += min(ans, cnt - ans);
		}
//	for (int i = 1; i <= n; i++)
//		cout << dis[i] << " ";
//	cout << endl;
//	for (int i = 1; i <= n; i++)
//		cout << val[i] << " ";
//	cout << endl;
	if (final_ans == -1) printf("Impossible\n");
	else printf("%d\n", final_ans);
	return 0;
}
