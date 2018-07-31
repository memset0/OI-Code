#include <bits/stdc++.h>
#define R(a,b) ((a - b + 26) % 26)
using namespace std;
const int maxn = 1010;
int n, m, a[maxn], key[maxn];
char ch, s1[maxn], s2[maxn];
bool tag[maxn];
int main() {
	scanf("%s%s", s1 + 1, s2 + 1);
	n = strlen(s2 + 1), m = strlen(s1 + 1);
	for (int i = 1; i <= n; i++)
		if (islower(s2[i])) a[i] = s2[i] - 'a';
		else a[i] = s2[i] - 'A', tag[i] = 1;
	for (int i = 1; i <= m; i++)
		if (islower(s1[i])) key[i] = s1[i] - 'a';
		else key[i] = s1[i] - 'A';
	for (int i = 1; i <= n; i++)
		a[i] = R(a[i], key[(i - 1) % m + 1]);
	for (int i = 1; i <= n; i++)
		if (tag[i]) putchar('A' + a[i]);
		else putchar('a' + a[i]);
	return 0;
}
