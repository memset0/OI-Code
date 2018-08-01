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

const int maxn = 2000010;
int n, i;
ll ans, c[256];
char t, a[maxn];

int main() {
	
	scanf("%s", a + 1), n = strlen(a + 1);
//	for (int i = 1; i <= n; i++)
//		printf("%d ", a[i] - 'A');
//	puts("");
	for (i = 1; i <= n; i++) {
		for (t = a[i] + 1; t <= 'Z'; t++)
			ans += c[t];
		c[a[i]]++; 
//		printf("%lld\n", ans);
	}
	printf("%lld\n", ans);

	return 0;
}

