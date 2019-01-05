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

priority_queue < int > p;
priority_queue < int, vector < int >, greater < int > > q;

const int maxn = 200010;

int n, m;
int a[maxn], b[maxn];

int main() {
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= m; i++)
		b[read()]++;
	
	for (int i = 1; i <= n; i++) {
		q.push(a[i]);
//		printf("%d %d : %d %d\n", p.size() ? p.top() : -1, q.top(), p.size(), q.size());
		if (p.size() && q.size())
			if (q.top() < p.top()) {
				int tmp = q.top();
				q.pop(), q.push(p.top());
				p.pop(), p.push(tmp);
			}
//		printf("%d %d : %d %d\n\n", p.size() ? p.top() : -1, q.top(), p.size(), q.size());
		while (b[i]--) {
			printf("%d\n", q.top());
			p.push(q.top()), q.pop();
		}
	}
	
    return 0;
}