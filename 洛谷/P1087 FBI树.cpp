#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 10;
int n, a[maxn];
char f(int l, int r) {
	if (l == r) {
		char c;
		if (a[l] == 0) c = 'B';
		else c = 'I';
		printf("%c", c);
		return c;
	}
	int mid = (l + r) / 2;
	char c1 = f(l, mid);
	char c2 = f(mid + 1, r);
	if (c1 == c2) {
		printf("%c", c1);
		return c1;
	} else {
		printf("F");
		return 'F';
	}
}
int main() {
	cin >> n, n = 1 << n;
	for (int i = 1; i <= n; i++) 
		scanf("%1d", &a[i]);
	f(1, n);
	puts("");
	return 0;
}