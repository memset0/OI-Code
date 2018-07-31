#include <bits/stdc++.h>
using namespace std;
const int maxn = 15010;
int n, m, l, t, fa, fb, fx, q, ans[maxn];
long long a, b, x;
char f;
bool cmp(int a, int b) {
	return a > b;
}
struct Node {
	long long id;
	int val;
	bool living;
} s[maxn];
int find(long long x) {
	for (int i = 1; i <= l; i++)
		if (s[i].id == x && s[i].living) {
			return i;
		}
	return 0;
}
int main() {
	scanf("%d\n", &n);
//	cout << n << endl;
	while (n--) {
		scanf("%c", &f);
		if (f == 'C') {
			scanf("%lld\n", &x);
			fx = find(x);
			if (fx) s[fx].val++;
			else s[++l] = {x, 1, true};
		} else if (f == 'D') {
			scanf("%lld\n", &x);
			fx = find(x);
			if (fx) {
				s[fx].val--;
				if (!s[fx].val) s[fx].living = false;
			}
		} else if (f == 'M') {
			scanf("%lld<%lld\n", &a, &b);
			fa = find(a), fb = find(b);
			if (fa && fb && fa != fb) {
				s[fa].val += s[fb].val;
				s[fb].living = false;
			}
		}
	}
//	for (int i = 1; i <= l; i++)
//		printf("%d | id = %lld | val = %d | liv = %d\n", i, s[i].id, s[i].val, s[i].living);
	for (int i = 1; i <= l; i++)
		if (s[i].living)
			ans[++q] = s[i].val;
	sort(ans + 1, ans + q + 1, cmp);
	scanf("%d\n", &m);
	while (m--) {
		scanf("%d", &t);
//		printf("%d %d\n", t, q);
		if (t > q) printf("NO\n");
		else printf("%d\n", ans[t]);
	}
	return 0;
}

/*
5
C 444444444444
C 888888888888
M 888888888888<444444444444
D 444444444444
C 555555555555
3
1 2 3

*/
