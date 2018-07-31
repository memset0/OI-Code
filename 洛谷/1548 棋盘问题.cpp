#include <bits/stdc++.h>
using namespace std;
int n, m, s1 = 0, s2 = 0;
int main() {
	scanf("%d%d", &n, &m);
	s2 = ((m + 1) * (n + 1) * m * n) / 4;
	for(; m >= 1 && n >= 1; m--, n--)
		s1 += m * n;
	printf("%d %d", s1, s2 - s1);
	return 0;
}
