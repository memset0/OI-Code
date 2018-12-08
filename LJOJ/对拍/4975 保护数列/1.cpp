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

const int maxn = 100010;
int n, lst;
ll ans;
int a[maxn], s[maxn], sb[maxn];
vector < int > t[maxn];
vector < int > g[maxn];
map < int, int > Map;

struct query {
	int k, w, flag;
	bool operator < (const query &a) const {
		return k < a.k;
	}
};
vector < query > q;

void add_query(int l, int r, int w) {
	if (l <= r) {
		q.push_back({l - 1, w, -1});
		q.push_back({r, w, 1});
	}
}

// void print(vector < int > a) {
// 	for (vector < int > ::iterator it = a.begin(); it != a.end(); it++)
// 		printf("%d ", *it);
// 	putchar('\n');
// }
// void print(vector < query > q) {
// 	for (vector < query > ::iterator it = q.begin(); it != q.end(); it++)
// 		printf(">>> %d %d %d\n", (*it).k, (*it).w, (*it).flag);
// 	puts("");
// }

int main() {
	
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] ^ a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 32; j++)
			if (!(a[i] & (1 << j)))
				g[j].push_back(i);
	}
	for (int j = 0; j < 32; j++)
		g[j].push_back(n + 1);
	// for (int i = 0; i < 32; i++)
	// 	print(g[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 32; j++)
			if (a[i] & (1 << j))
				t[i].push_back(j);
		// printf("=== %d : %d ===\n", i, a[i]);
		// print(t[i]);
		for (int j = 0; j < t[i].size(); j++)
			t[i][j] = *lower_bound(g[t[i][j]].begin(), g[t[i][j]].end(), i);
		sort(t[i].begin(), t[i].end());
		// print(t[i]);
		lst = i;
		for (int j = 0; j < t[i].size(); j++) {
			add_query(lst, t[i][j] - 1, a[i] ^ s[i - 1]);
			a[i] &= a[t[i][j]];
			lst = t[i][j];
		}
		add_query(lst, n, a[i] ^ s[i - 1]);
	}

	// print(q);
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", s[i]);
	// puts("");

	sort(q.begin(), q.end());
	lst = 0;
	for (vector < query > ::iterator it = q.begin(); it != q.end(); it++) {
		query u = *it;
		while (lst < u.k) Map[s[++lst]]++;
		ans += u.flag * Map[u.w];
	}
	printf("%lld\n", ans);
	
	return 0;
}