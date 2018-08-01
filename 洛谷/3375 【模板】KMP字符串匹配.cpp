#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1000010;
int i, j, n, m, p[maxn];
char a[maxn], b[maxn];
int main() {
	scanf("%s%s", a + 1, b + 1), n = strlen(a + 1), m = strlen(b + 1);
	for (i = 2, j = 0, p[1] = 0; i <= m; i++) {
		while (j && b[j + 1] != b[i]) j = p[j];
		if (b[i] == b[j + 1]) j++;
		p[i] = j;
	}
	for (i = 1, j = 0; i <= n; i++) {
		while (j && b[j + 1] != a[i]) j = p[j];
		if (a[i] == b[j + 1]) j++;
		if (j == m) printf("%d\n", i - m + 1);
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", p[i]);
	puts("");
	return 0;
}

