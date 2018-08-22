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

const int maxn = 500010, inf = 2147483647;
int n, m, x, y;
int a[maxn], b[maxn], c[maxn];
multiset < int > s;
multiset < int > ::iterator it;
ll ans;

int main() {
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++)
		b[i] = read();
	
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		ans += b[i], s.insert(b[i]);
//	for (int i = 1; i <= n; i++)
//		cout << a[i] << " ";
//	cout << endl;
//	for (auto it = s.begin(); it != s.end(); it++)
//		cout << *it << " ";
//	cout << endl;
	
	for (int i = 1; i <= n; i++) {
//		cout << '[' << a[i] << ']' << ' ';
//		for (auto it = s.begin(); it != s.end(); it++)
//			cout << *it << " ";
//		cout << endl;
		it = s.upper_bound(a[i]);
		if (it == s.begin()) {
			c[i] = inf; 
//			s.erase(it); ???
		} else {
			--it;
			c[i] = a[i] - (*it);
			s.erase(it);
		}
	}
	
	sort(c + 1, c + n + 1);
//	for (int i = 1; i <= n; i++)
//		cout << c[i] << " ";
//	cout << endl;
	if (c[n - m] == inf) {
		printf("-1\n");
	} else {
		for (int i = 1; i <= n - m; i++)
			ans += c[i];
		printf("%lld\n", ans);
	}
	return 0;
}
