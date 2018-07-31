#include <bits/stdc++.h>  
using namespace std;
const int maxn = 100010;
long long n, m, q, u, v, t, tmp, d = 0;
struct queue {
	long long l = 1, r = 0, v[maxn];
	inline void push(int x) {
		v[++r] = x;
	}
	inline int pop() {
		return v[l++];
	}
	inline int front() {
		return v[l];
	}
	void print() {
		for (int i = l; i <= r; i++)
			printf("%lld ", v[i] + d);
		puts("");
	}
} a, b, c;
inline int pop() {
	if (a.front() > b.front()) {
		if (a.front() > c.front()) {
			return a.pop();
		} else {
			return c.pop();
		}
	} else {
		if (b.front() > c.front()) {
			return b.pop();
		} else {
			return c.pop();
		}
	}
}
int main() {
	scanf("%lld%lld%lld%lld%lld%lld", &n, &m, &q, &u, &v, &t);
	for (int i = 1; i <= n; i++) scanf("%lld", &tmp), a.push(tmp);
	long long f, g;
	for (int i = 1; i <= m; i++) {
		f = pop() + d; g = f * u / v;
		b.push(g - q), c.push(f - g - q);
		d += q;
		if (!(i % t)) printf("%lld ", f);
	}
	puts("");
	return 0;
}
