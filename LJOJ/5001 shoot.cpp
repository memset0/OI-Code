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

const int maxn = 1e6 + 10;

int n, fa[maxn];
int cnt, ans1, ans2;

int siz[maxn], vis[maxn], die[maxn];
int tsiz[maxn];

bool tag[maxn];

void dfs1(int u) {
	if (!die[u]) {
		if (!die[fa[u]]) {
			die[fa[u]] = 1;
			ans1++;
		}
	}
	vis[u] = 1;
	siz[fa[u]]--;
	if (!siz[fa[u]])
		dfs1(fa[u]);
}

void dfs2(int u) {
	if (!die[fa[u]]) {
		die[fa[u]] = 1;
		ans2++;
	}
	vis[u] = 1;
	siz[fa[u]]--;
	if (!siz[fa[u]])
		dfs2(fa[u]);
}

//void pa(int *a) {
//	for (int i = 1; i <= n; i++)
//		printf("%d ", a[i]);
//	puts("");
//}
//
//void pa(bool *a) {
//	for (int i = 1; i <= n; i++)
//		printf("%d ", a[i]);
//	puts("");
//}

int main() {
//	freopen("shoot.in", "r", stdin);
//	freopen("shoot.out", "w", stdout);
	
	n = read();
	for (int i = 1; i <= n; i++) {
		fa[i] = read();
		siz[fa[i]]++;
	}
	for (int i = 1; i <= n; i++)
		tsiz[i] = siz[i];
	
	// ===== ans1 =====
	for (int i = 1; i <= n; i++)
		if (fa[i] == i) {
			vis[i] = 1;
			die[i] = 1;
			ans1++;
		}
	for (int i = 1; i <= n; i++)
		if (!siz[i] && !vis[i]) {
			dfs1(i);
		}
//	pa(vis), pa(die);
	for (int i = 1; i <= n; i++)
		if (!vis[i] && die[i]) {
//			printf(">>1>> %d\n", i);
			vis[i] = 1;
			for (int u = fa[i]; u != i; u = fa[u]) {
				if (!die[u]) {
					if (!die[fa[u]]) {
						die[fa[u]] = 1;
						ans1++;
					}
				}
				vis[u] = 1;
			}
		}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
//			printf(">>2>> %d\n", i);
			vis[i] = 1;
			if (!die[fa[i]]) {
				die[fa[i]] = 1;
				ans1++;
			}
			for (int u = fa[i]; u != i; u = fa[u]) {
				if (!die[u]) {
					if (!die[fa[u]]) {
						die[fa[u]] = 1;
						ans1++;
					}
				}
				vis[u] = 1;
			}
		}
//	pa(vis), pa(die);
		
	// ===== init =====
	memset(vis, 0, sizeof(vis));
	memset(die, 0, sizeof(die));
	for (int i = 1; i <= n; i++)
		siz[i] = tsiz[i];
	
	// ===== ans2 =====
	for (int i = 1; i <= n; i++)
		if (!siz[i]) {
			tag[i] = 1;
		}
	for (int i = 1; i <= n; i++)
		if (tag[i]) {
		   siz[fa[i]]--;
		   fa[i] = i;
		}
	for (int i = 1; i <= n; i++)
		if (fa[i] == i) {
			die[i] = 1;
			vis[i] = 1;
			ans2++;
		}
	for (int i = 1; i <= n; i++)
		if (!siz[i] && !vis[i]) {
			dfs2(i);
		}
	for (int i = 1; i <= n; i++)
		if (!vis[i] && die[i]) {
//			printf(">>1>> %d\n", i);
			vis[i] = 1;
			for (int u = fa[i]; u != i; u = fa[u]) {
				if (!die[u]) {
					die[u] = 1;
					ans2++;
				}
				vis[u] = 1;
			}
		}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
//			printf(">>2>> %d\n", i);
			vis[i] = 1;
			for (int u = fa[i]; u != i; u = fa[u]) {
				if (!die[u]) {
					die[u] = 1;
					ans2++;
				}
				vis[u] = 1;
			}
		}
	
	// ===== print =====
	printf("%d %d\n", ans1, ans2);
	
	return 0;
}
