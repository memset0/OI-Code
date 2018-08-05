#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 100010;
int n, s1, s2, i, j, ans;
int a[maxn];

int main() {
	
	n = read();
	for (i = 1; i <= n; i++)
		a[i] = read();
		
	for (i = 1; i <= n; i++) {
		s1 = s2 = a[i], ans++;
		for (j = i + 1; j <= n; j++) {
			s1 ^= a[j], s2 &= a[j];
			if (s1 == s2) ans++;
//			printf("%d => %d | %d %d\n", i, j, s1, s2);
		}
	}
	printf("%d\n", ans);
	
	return 0;
}