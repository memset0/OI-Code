#include <bits/stdc++.h>
using namespace std;
const int maxn = 2001;
int n, f[maxn][maxn];
char a[maxn];
char read() {
	char c = getchar();
	while (!('A' <= c && c <= 'Z')) c = getchar();
	return c;
}
bool is_better(int l, int r) {
	if (l >= r) return 1;
	if (a[l] == a[r]) return is_better(l + 1, r - 1);
	return a[l] < a[r];
}
//bool is_better(int l, int r) {
//	if (a[l] == a[r]) return is_better(ll, l + 1, r - 1, rr);
//	if (a[l + 1] == a[r]) return is_better(ll, l + 1, r, rr);
//	if (a[l] == a[r - 1]) return is_better(ll, l, r - 1, rr);
//	return a[l] <= a[r];
//}
int main() {
	memset(f, -1, sizeof(f));
	cin >> n;
	for (int i = 1; i <= n; i++)
		a[i] = read();
	int l = 1, r = n;
	while (l < r) {
		if (a[l] < a[r]) {
			putchar(a[l]);
//			cout << l << endl;
			l++;
		} else if (a[l] > a[r]) {
			putchar(a[r]);
//			cout << r << endl;
			r--;
		} else {
			//相等的时候要特殊考虑 
//			cout << l << " " << r << " " << is_better(l + 1, r - 1) << endl;
			if (is_better(l + 1, r - 1)) {
				putchar(a[l]);
//				cout << l << endl;
				l++;
			} else {
				putchar(a[r]);
//				cout << r << endl;
				r--;
			}
		}
	}
	printf("%c\n", a[l]);
	return 0;
}
