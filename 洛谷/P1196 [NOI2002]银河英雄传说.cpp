// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

char readc() {
	char c = getchar();
	while (c != 'M' && c != 'C') c = getchar();
	return c;
}

struct node {
	node *father;
	int siz, dis;
} *u, *v, a[30010];

int n, p, q, opt;

node *find(node *x) {
	if (x == x->father) return x;
	node *f = find(x->father);
	x->dis = x->father->dis + x->dis;
	x->father = f;
//	printf(">>> %d %d %d %d\n", x, x->father, x->dis, x->father->dis);
	return f;
}

int order(node *u) {
	for (int i = 1; i <= 30000; i++)
		if (u == &a[i])
			return i;
}

int main() {
    // freopen("INPUT", "r", stdin);
    // freopen("OUTPUT", "w", stdout);
    
    n = read();
    for (int i = 1; i <= 30000; i++)
    	a[i].father = &a[i], a[i].siz = 1;
    for (int i = 1; i <= n; i++) {
    	opt = readc();
    	if (opt == 'M') {
    		u = find(&a[read()]), v = find(&a[read()]);
    		u->father = v;
    		u->dis = v->siz;
    		v->siz += u->siz;
		} else {
			p = read(), q = read();
			find(&a[p]), find(&a[q]);
			u = &a[p], v = &a[q];
//    		printf("%d %d %d %d\n", u->father, v->father, u->dis, v->dis);
			if (u->father != v->father) printf("-1\n");
			else printf("%d\n", abs(u->dis - v->dis) - 1);
		}
//		for (int i = 1; i <= n; i++) {
//			printf("(%d,%d,%d)%c", order(a[i].father), a[i].dis, a[i].siz, i == n ? '\n' : ' ');
//		}
	}

    return 0;
}