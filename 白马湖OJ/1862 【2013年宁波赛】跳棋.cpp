#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
int n, l, r, a[maxn], dp[maxn];
struct Simple_Queue {
	int f = 1, e = 0, q[maxn];
	void push(int x) {
		while (f <= e && dp[x] < dp[q[e]]) {
//			printf("push x = %d e= %d q[e] = %d\n", a[x], e, a[q[e]]);
			e--;
		}
		q[++e] = x;
	}
	void pop(int x) {
		while (f <= e && x - q[f] > r + 1) f++;
	}
	int front() {
		return q[f];
	}
	bool empty() {
		return f > e;
	}
	void print() {
		for (int i = f; i <= e; i++)
			printf("%d ", q[i]);
	}
} q;
int main() {
//	freopen("data.txt", "r", stdin);
//	freopen("1.txt", "w", stdout);
	memset(dp, -1, sizeof(dp));
	scanf("%d%d%d", &n, &l, &r);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		q.pop(i);
		if (i - l - 1 >= 0 && dp[i - l - 1] != -1) q.push(i - l - 1);
//		printf("i = %d q = ", i);
//		q.print();
//		puts("");
		if (!q.empty()) dp[i] =  dp[q.front()] + a[i];
	}
//	for (int i = 1; i <= n; i++)
//		printf("%d ", dp[i]);
	printf("%d\n", dp[n]);
	return 0;
}
