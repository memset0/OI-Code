#include <bits/stdc++.h>
#define read(a) scanf("%d",&a)
#define lowbit(a) (a&-a)
using namespace std;
const int maxn = 500010;
int n, m, c[maxn];
void add(int u, int v) {
	for (int i = u; i <= n; i += lowbit(i)) c[i] += v;
}
int ask(int u) {
	for (int i = u, ret = 0; i > 0; i -= lowbit(i)) ret += c[i]; 
	return ret;
}
int main() {
	read(n), read(m);
	int x, y, z;
	for (int i = 1; i <= n; i++) {
		read(x);
		add(i, x);
	}
	for (int i = 1; i <= m; i++) {
		read(x); read(y); read(z);
		if (x == 1) {
			add(y, z);
		} else {
			printf("%d\n", ask(z) - ask(y - 1));
		}
	}
	return 0;
}
