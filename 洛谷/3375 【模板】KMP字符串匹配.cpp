#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1000010;
int i, j, an, bn, p[maxn];
char a[maxn], b[maxn];
int main() {
	scanf("%s%s", a + 1, b + 1), an = strlen(a + 1), bn = strlen(b + 1);
	for (i = 2, j = 0, p[1] = 0; i <= n; i++) {
		while (j && b[j + 1] != b[i]) j = p[j];
		if (b[i] == b[j + 1]) j++;
		p[i] = j;
	} 
	return 0;
}

