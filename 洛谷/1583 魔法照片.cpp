#include <bits/stdc++.h> 
using namespace std;
const int maxn = 20010;
int n, m, e[11], w[maxn], c[maxn], d[maxn], k[maxn];
bool my_sort(int a, int b) {
	if (w[a] == w[b]) return a < b;
	return w[a] > w[b];
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= 10; i++)
		scanf("%d", &e[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++)
		d[i] = i, k[i] = i;
	sort(d + 1, d + n + 1, my_sort);
	for (int i = 1; i <= n; i++) {
		c[d[i]] = (d[i] - 1) % 10 + 1;
	}
	for (int i = 1; i <= n; i++) {
		w[i] += e[c[i]];
		cout << d[i] << " " << w[d[i]] << " " << e[c[i]] << endl;
	}
	for (int i = 1; i <= n; i++)
		cout << w[i] << " ";
	puts("\n");
	sort(d + 1, d + n + 1, my_sort);
	for (int i = 1; i <= m; i++) {
		cout << d[i] << " " << w[d[i]] << endl;
		printf("%d\n", d[i]);
	}
	return 0;
}
