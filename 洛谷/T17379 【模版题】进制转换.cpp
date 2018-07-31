#include <bits/stdc++.h> 
using namespace std;
int n, r, s[10010];
int main() {
	scanf("%d%d", &n, &r);
	if (n == 0) {
		printf("%d", 0);
	}
	while (n > 0) {
		s[++s[0]] = n % r;
		n /= r;
	}
	for (int i = s[0]; i > 0; i--)
		printf("%d", s[i]);
	puts("");
	return 0;
}
