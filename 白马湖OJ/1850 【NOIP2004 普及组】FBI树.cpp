#include <bits/stdc++.h> 
using namespace std;
const int maxn = 1100;
int n, a[maxn];
int f(int l, int r){
	if (l == r) {
		if (a[l]) putchar('I');
		else putchar('B');
		return a[l];
	}
	int t1 = f(l, (l + r) / 2), t2 = f((l + r) / 2 + 1, r);
	if (t1 == 2 || t2 == 2 || (t1 == 1 && t2 == 0) || (t2 == 1 && t1== 0)) {
		putchar('F');
		return 2;
	} else if (t1 == 1 && t2 == 1) {
		putchar('I');
		return 1; 
	} else if (t1 == 0 && t2 == 0) {
		putchar('B');
		return 0;
	} else {
		puts("error");
		return 2;
	}
}
int main() {
	cin >> n, n = 1 << n;
	for (int i = 1; i <= n; i++)
		scanf("%1d", &a[i]);
	f(1, n);
	return 0;
}
