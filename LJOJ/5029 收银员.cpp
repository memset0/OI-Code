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

int t, a[30], b[30];

 namespace wyl {
 	
 	int l, r, u, v, ans, mid, t[30];
 	int tot, hed[50], val[200], dis[50], nxt[200], to[200], q[10000];
 	bool inq[50];
 	
 	void add_edge(int u, int v, int w) {
 		nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
 		hed[u] = tot++;
	}
 	
	bool spfa(int x) {
		memset(dis, -63, sizeof(dis));
		memset(inq, 0, sizeof(inq));
		cout << dis[0] << endl;
		l = r = 1, q[1] = 0, dis[0] = 0, inq[0] = 1;
		while (l <= r) {
			u = q[l++], inq[u] = 0;
//			if (dis[u] > x || u == 24) return 0;
			if (dis[u] > x) {
				cout << dis[u] << " " << x << endl;
				return 0;
			}
			for (int i = hed[u]; i; i = nxt[i]) {
				v = to[i];
				if (dis[v] < dis[u] + val[i]) {
					dis[v] = dis[u] + val[i];
					if (!inq[v]) {
						inq[v] = 1;
						q[++r] = v;
					}
				}
			}
		}
		for (int i = 1; i <= 24; i++)
			printf("%d ", dis[i]);
		puts("");
		return dis[24] == x ? 1 : 0;
	}
 	
 	bool check(int x) {
 		tot = 2;
 		memset(hed, 0, sizeof(hed));
 		for (int i = 1; i <= 24; i++) {
 			add_edge(i, i - 1, -b[i]);
 			add_edge(i - 1, i, 0);
		}
		add_edge(0, 24, x);
		add_edge(24, 0, -x);
		for (int i = 8; i <= 24; i++)
			add_edge(i - 8, i, a[i]);
		for (int i = 1; i <= 7; i++)
			add_edge(i + 16, i, a[i] - x);
		return spfa(x);
	}
	
	void mian() {
 		int sum = 0;
		for (int i = 1; i <= 24; i++)
			t[i] = a[i] = read();
		for (int i = 1; i <= 24; i++) {
			b[i] = read(), sum += b[i];
			for (int j = i; j < i + 8; j++)
				t[(j - 1) % 24 + 1] -= b[i];
		}
		for (int i = 1; i <= 24; i++)
			if (t[i] > 0) {
				puts("-1");
				return;
			}
		
		l = 1, r = sum, ans = -1;
		while (l <= r) {
			mid = (l + r) >> 1;
			printf("check(%d) => %d\n", mid, check(mid));
			if (check(mid)) r = mid - 1, ans = mid;
			else l = mid + 1;
		}
		printf("%d\n", ans);
		
	}
	
}

int main() {

	t = read();
	while (t--) {
		wyl::mian();
	}

	return 0;
}
