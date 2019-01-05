#include <bits/stdc++.h>
#define isnum(c) ('0' <= c && c <= '9')
#define read(x) do {\
	R::c = getchar(); R::m = 0; x = 0;\
	while (!isnum(R::c) && R::c != '-') R::c = getchar();\
	if (R::c == '-') R::c = getchar(), R::m = 1;\
	while (isnum(R::c)) x = x * 10 + R::c - '0', R::c = getchar();\
	if (R::m) x = -x;\
} while(false)
namespace R { char c; bool m; }
using namespace std;

const int maxn = 25;
int n, m, ans, sum;
struct Project {
	int val, cnt;
} a[maxn];
bool cmp(Project A, Project B) {
	return A.val > B.val;
}

int main() {
	
//	freopen("allow.in", "r", stdin);
//	freopen("allow.out", "w", stdout);
	
	read(n);
	read(m);
	for (int i = 1; i <= n; i++) {
		read(a[i].val);
		read(a[i].cnt);
	}
	
	sort(a + 1, a + n + 1, cmp);
	
//	for (int i = 1; i <= n; i++)
//		if (a[i].val > m)
//			ans += a[i].cnt, a[i].cnt = 0;
	
	while (true) {
		sum = m;
		for (int i = 1; i <= n; i++)
			while (sum > 0 && sum >= a[i].val && a[i].cnt)
				sum -= a[i].val, a[i].cnt--;
		if (sum > 0)
			for (int i = n; i >= 1; i--)
				while (sum > 0 && a[i].cnt) {
					sum -= a[i].val;
					a[i].cnt--;
				}
		if (sum <= 0) ans++;
		else break;
	}
	
	printf("%d\n", ans);
	
	return 0;
} 