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

int n, a;
ll ans;
priority_queue < int > q;

int main() {
	
	n = read();
	for (int i = 1; i <= n; i++) {
		a = read();
		q.push(a);
		if (a <= q.top()) {
			ans += q.top() - a;
			q.pop(), q.push(a); 
		}
	}
	printf("%lld\n", ans);

	return 0;
}
