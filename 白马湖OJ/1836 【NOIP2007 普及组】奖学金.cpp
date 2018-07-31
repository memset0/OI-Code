#include<bits/stdc++.h>
using namespace std;
const int maxn = 310;
struct Stu {
	int i, s, a, b, c;
} a[maxn];
int n;
bool my_sort(Stu a, Stu b) {
	if (a.s == b.s) {
		if (a.a == b.a) return a.i < b.i;
		return a.a > b.a;
	}
	return a.s > b.s;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
		a[i].s = a[i].a + a[i].b + a[i].c;
		a[i].i = i;
	}
	sort(a+1, a+n+1, my_sort);
	for (int i = 1; i <= 5; i++)
		printf("%d %d\n", a[i].i, a[i].s);
	return 0;
}

