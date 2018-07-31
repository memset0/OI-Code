#include <bits/stdc++.h>
#define isNum(c) ('0'<=c&&c<='9')
using namespace std;
const int maxn = 100010;
int n, m, a[maxn], c[maxn];
vector < int > v[maxn][2];
int read() {
	char c = getchar();
	while (!isNum(c)) c = getchar();
	int ret = 0;
	while (isNum(c)) {
		ret = ret * 10 + c - '0';
		c = getchar();
	}
	return ret;
}
int ans = 0;
int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = (read() % 10007);
	for (int i = 1; i <= n; i++)
		c[i] = read();
	for (int i = 1; i <= n; i++)
		v[c[i]][i%2].push_back(i);
	int tmp;
	for (int t = 1; t <= m; t++) {
		for (int k = 0; k < 2; k++) {
			if (v[t][k].size() < 2) continue;
			tmp = 0;
			for (int i = 0; i < v[t][k].size(); i++)
				tmp = (tmp + v[t][k][i]) % 10007;
			for (int i = 0; i < v[t][k].size(); i++)
				ans = (ans + a[v[t][k][i]] * (((v[t][k][i] * (v[t][k].size() - 2)) % 10007 + tmp) % 10007)) % 10007;
		}
	}
	cout << ans << endl;
	return 0;
}
