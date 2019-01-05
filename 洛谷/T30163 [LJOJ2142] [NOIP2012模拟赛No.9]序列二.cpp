#include <bits/stdc++.h>
using namespace std;
long long n, m, sum, a[100010], s[100010], f[100010];
struct Node {
	int i, j;
	long long val;
} t;
struct Heap {
	long long l;
	Node f[200010];
	void clear() {
		l = 0;
	}
	Node front() {
		return f[1];
	}
	long long size() {
		return l;
	}
	int insert(Node x) {
		f[++l] = x;
		int u = l;
		while (u > 1)
			if (f[u].val < f[u >> 1].val) swap(f[u], f[u >> 1]), u >>= 1;
			else break;
	}
	void pop() {
		f[1] = f[l--];
		int u = 1, v;
		while ((u << 1) <= l) {
			if (f[u << 1].val < f[u << 1 | 1].val) v = u << 1;
			else v = u << 1 | 1;
			if (f[v].val < f[u].val) swap(f[u], f[v]), u = v;
			else break;
		}
	}
} h;
int main() {
//	freopen("Sequence2.in", "r", stdin);
//	freopen("Sequence2.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%lld", &s[i]);
	for (int i = 2; i <= n; i++) {
		for (int i = 1; i <= m; i++)
			scanf("%lld", &a[i]);
		sort(a + 1, a + m + 1);
		for (int i = 1; i <= m; i++)
			h.insert({i, 1, s[i] + a[1]});
		f[1] = h.front().val;
//		for (int i = 1; i <= m; i++)
//			cout << h.f[i].val << " ";
//		cout<< endl;
		for (int i = 2; i <= m; i++) {
			t = h.front(), h.pop();
			h.insert({t.i, t.j + 1, s[t.i] + a[t.j + 1]});
			f[i] = h.front().val;
		}
		for (int i = 1; i <= m; i++)
			s[i] = f[i], h.pop();
//		for (int i = 1; i <= m; i++) 
//			printf("%d ", s[i]);
//		puts("");
	}
	for (int i = 1; i <= m; i++) {
		printf("%lld", s[i]);
		if (i != m) putchar(' ');
	}
	puts("");
	return 0;
}