#include <bits/stdc++.h>
using namespace std;
const int maxn = 310;
struct Student {
	int s, c, i;
}a[maxn];
int n, x, y, z;
bool my_sort(Student a, Student b) {
	if (a.s == b.s) {
		if (a.c == b.c) return a.i < b.i;
		else return a.c > b.c;
	} 
	else return a.s > b.s;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y >> z;
		a[i].s = x + y + z;
		a[i].c = x;
		a[i].i = i;
	}
	sort(a + 1, a + n + 1, my_sort);
	for (int i = 1; i <= 5; i++)
		cout << a[i].i << " " << a[i].s << endl;
	return 0;
}
