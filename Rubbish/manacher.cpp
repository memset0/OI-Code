#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
int n, p[maxn << 1];
char s[maxn], a[maxn << 1];
int main() {
	gets(s);
	for (int i = 0; i < strlen(s); i++)
		a[i * 2 + 1] = '#', a[i * 2 + 2] = s[i];
	a[n = strlen(s) * 2 + 1] = '#';
	int mx = 0, id = 0;
	a[0] = -1, a[n + 1] = -2;
	for (int i = 1; i <= n; i++) {
		p[i] = mx > i ? min(p[i - 2 * id], mx - i) : 1;
		while (a[i - p[i]] == a[i + p[i]]) p[i] ++;
		if (i + p[i] > mx) {
			mx = i + p[i];
			id = i;
		}
	}
//	for (int i = 1; i <= n; i++)
//		cout << p[i] << " ";
//	puts("");
//	for (int i = 1; i <= n; i++)
//		cout << a[i] << " ";
//	puts("");
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (p[i] > ans) ans = p[i];
	printf("%d", (ans - 1));
	return 0;
}
