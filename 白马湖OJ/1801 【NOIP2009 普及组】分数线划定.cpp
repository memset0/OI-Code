#include <bits/stdc++.h>
using namespace std;
const int maxn = 5010;
struct Struct {
	int id, s;
}a[maxn];
int n, m, s;
bool my_sort(Struct a, Struct b) {
	if (a.s == b.s) return a.id < b.id;
	return a.s > b.s;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d%d",&a[i].id, &a[i].s);
	sort(a + 1, a + n + 1, my_sort);
	s = a[int(m * 1.5)].s, m = 0;
	for (int i = 1; i <= n; i++)
		if (a[i].s >= s) m++;
		else break;
	cout << s << " " << m << endl;
	for (int i = 1; i <= m; i++)	
		printf("%d %d\n", a[i].id, a[i].s);
	return 0;
}
