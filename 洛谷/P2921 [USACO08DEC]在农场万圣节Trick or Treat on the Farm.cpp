#include <bits/stdc++.h>
#define isnum(c) ('0' <= c && c <= '9')
#define read(x) { \
		x = 0, rd::c = getchar(), rd::m = 0; \
		while (!isnum(rd::c) && rd::c != '-') rd::c = getchar(); \
		if (rd::c == '-') rd::m = 1, rd::c = getchar(); \
		while (isnum(rd::c)) x = x * 10 + rd::c - '0', rd::c = getchar(); \
		if (rd::m) x *= -1; \
	}
namespace rd {
	char c;
	bool m;
}
using namespace std;

const int maxn = 100010;
int n, u, v, l, r, q[maxn];
struct Node {
	int e, cnt, val;
	bool nod, cld;
	vector < int > linkin;
} a[maxn];

int main() {

//	freopen("data.txt", "r", stdin);
//	freopen("treat1.in", "r", stdin);
//	freopen("treat1.out", "w", stdout);
//	freopen("treat.in", "r", stdin);
//	freopen("treat.out", "w", stdout);

	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i].e);
		a[a[i].e].cnt += 1;
		a[a[i].e].linkin.push_back(i);
	}
	for (int i = 1; i <= n; i++)
		if (!a[i].cnt) {
			a[i].nod = 1;
			q[++r] = i;
		}
//	for (int i = 1; i <= n; i++)
//		printf("%d ", a[i].cnt);
//	printf("\n");
//	for (int i = 1; i <= n; i++)
//		printf("%d ", a[i].nod);
//	printf("\n");
	l = 1;
	while (l <= r) {
		u = q[l++];
		a[a[u].e].cnt--;
		if (!a[a[u].e].cnt) {
			a[a[u].e].nod = 1;
			q[++r] = a[u].e;
		}
	}
//	for (int i = l; i <= r; i++)
//		cout << q[i] << " ";
//	cout << endl;
//	for (int i = 1; i <= n; i++)
//		printf("%d ", a[i].cnt);
//	printf("\n");
//	for (int i = 1; i <= n; i++)
//		printf("%d ", a[i].nod);
//	printf("\n");
		
	for (int i = 1; i <= n; i++) {
		if (!a[i].nod) {
			q[1] = i, r = 1;
			while (1) {
				a[q[r]].nod = 1;
				q[r + 1] = a[q[r]].e;
				r++;
				if (a[q[r]].nod) {
					r--;
					break;
				}
			}
//			for (int i = 1; i <= r; i++)
//				printf("%d ", q[i]);
//			puts("");
			for (int i = 1; i <= r; i++) {
				a[q[i]].val = r;
				a[q[i]].cld = 1;
			}
		}
	}
	
	l = 1, r = 0;
	for (int i = 1; i <= n; i++)
		if (a[i].cld)
			q[++r] = i;
	while (l <= r) {
		u = q[l++];
		for (int i = 0; i < a[u].linkin.size(); i++) {
			v = a[u].linkin[i];
			if (!a[v].cld) {
				a[v].cld = 1;
				a[v].val = a[u].val + 1;
				q[++r] = v;
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		printf("%d\n", a[i].val);

	return 0;
}