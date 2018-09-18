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

const int maxn = 1010;
const int P = 998244353;

int ID, T, n, m, p, u, v, w, cnt, ans;
int fa[maxn];
bool mrk[maxn], tag[maxn], use[maxn];

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main() {
	freopen("../sample/brethren/brethren1.in", "r", stdin);
//	freopen("../sample/brethren/brethren2.out", "w", stdout);
//	freopen("brethren.in", "r", stdin);
//	freopen("brethren.out", "w", stdout);
	
	ID = read(), T = read();
	for (int U = 1; U <= T; U++) {
		cnt = 0;
		
		n = read(), m = read();
		for (int i = 1; i <= n; i++)
			fa[i] = i;
		memset(mrk, 0, sizeof(mrk));
		memset(tag, 0, sizeof(tag));
		memset(use, 0, sizeof(use));
			
		for (int i = 1; i <= m; i++) {
			u = read(), v = read(), w = read();
			if (w) {
				p++;
				fa[find(u)] = find(v), mrk[find(v)] = 1;
			}
			tag[u] = tag[v] = 1;
		}
		
		for (int i = 1; i <= n; i++)
			if (!mrk[find(i)] && !tag[i])
				cnt++, cout << i << endl;
		for (int i = 1; i <= n; i++)
			if (mrk[find(i)] && !use[find(i)]) {
				cnt++;
				cout << i << endl;
				use[find(i)] = 1;
			}
		
		if (cnt == 1 || p == 1) cnt++;
		printf(">>> %d\n", cnt);
//		for (int i = 1; i <= n; i++)
//			printf("%d ", find(i));
//		puts("");
		
		if (cnt == 0) ans = 1;
		else {
			ans = 1;
			while (--cnt)
				ans = (ans << 1) % P;
		}
		printf("%d\n", ans);
		
	}

	return 0;
}
