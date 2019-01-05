#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
int n, m, i, j, p[maxn];
char a[maxn], b[maxn];
int read(char *s) {
	int ret = 0;
	char c = getchar();
	while (c == '\r' || c == '\n') c = getchar();
	while (c != '\n' && c != '\r') s[++ret] = c, c = getchar();
	return ret;
}
int main() {
	n = read(a), m = read(b);
	p[1] = 0;
	j = 0;
	for (i = 2; i <= m; i++) {
		while (j > 0 && b[j + 1] != b[i]) 
			j = p[j];
		if (b[j + 1] == b[i]) j++;
		p[i] = j;
	}
	j = 0;
	for (i = 1; i <= n; i++) {
		while (j > 0 && b[j + 1] != a[i]) j = p[j];
		if (b[j + 1] == a[i]) j++;
		if (j == m) {
			printf("%d\n", i - m + 1);
			j = p[j];
		}
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", p[i]);
	return 0;
}