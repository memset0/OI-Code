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

const int maxn = 2000010;

int t, n, k, f, l, r;
int maxx, sum;
int a[maxn], s[maxn];

int main() {

	t = read();
	while (t--) {
		memset(s, 0, sizeof(s));
		
		n = read(), k = read(), f = read();
		for (int i = 1; i <= n; i++)
			a[i] = read();
	
		maxx = a[1];
		for (int i = 2; i <= n; i++)
			if (a[i] > maxx) maxx = a[i];
		
		for (int i = 1; i <= n; i++)
			s[a[i]]++;
		for (int i = 2; i <= maxx; i++)
			s[i] += s[i - 1];
		sort(a + 1, a + n + 1);
		
		for (int g = 1; g <= maxx; g++) {
//			printf("\n=== %d ===\n", g);
			if (g <= k) {
				sum = s[maxx] - s[g - 1];
				if (sum >= n - f)
					printf("%d ", g);
			} else {
				sum = 0;
				for (int i = g; i <= maxx; i += g) {
					l = i, r = min(maxx, i + k);
					sum += s[r] - s[l - 1];
//					printf("%d %d -> %d\n", l, r, s[r] - s[l - 1]);
				}
				if (sum >= n - f)
					printf("%d ", g);
			}
		}
		putchar('\n');
		
	}
	
	return 0;
}
