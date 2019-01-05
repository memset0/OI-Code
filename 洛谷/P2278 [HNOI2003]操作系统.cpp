#include <bits/stdc++.h>
using namespace std;

struct node {
	int id, tim, sty, ord;
} a[10000010], u;
bool operator < (node a, node b) {
	if (a.ord == b.ord) return a.tim > b.tim;
	return a.ord < b.ord;
}
priority_queue < node > q;

int n, now;

int main() {
//	freopen("1.txt", "r", stdin);
	n = 1;
	while (scanf("%d%d%d%d", &a[n].id, &a[n].tim, &a[n].sty, &a[n].ord) != EOF) n++;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= i; j++)
//			q.push(a[j]);
//		for (int j = 1; j <= i; j++) {
//			u = q.top();
////			printf("(%d,%d,%d,%d) ", u.id, u.tim, u.sty, u.ord);
//			q.pop();
//		}
//		puts("");
//	}
	n--;
	for (int i = 1; i <= n; i++) {
		if (q.size())
			while (now + (u = q.top()).sty <= a[i].tim && q.size()) {
				printf("%d %d\n", u.id, now + u.sty);
				now += u.sty, q.pop();
				if (!q.size()) break;
			}
		if (q.size()) {
			u = q.top(), q.pop();
//			printf(">>> %d %d -> ", u.id, u.sty);
			u.sty -= a[i].tim - now;
//			printf("%d %d\n", u.id, u.sty);
			q.push(u);
		}
		now = max(now, a[i].tim);
		q.push(a[i]);
	}
//	puts("===");
	while (q.size()) {
		u = q.top();
		printf("%d %d\n", u.id, now + u.sty);
		now += u.sty, q.pop();
	}
	return 0;
}