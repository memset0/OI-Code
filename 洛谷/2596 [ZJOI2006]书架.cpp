// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define ull unsigned long long
#define y1 this_is_not_y1
#define y2 this_is_not_y2
#define sqr ((x)*(x))
#define lowbit(x) ((x)&(-x))
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

ll readll() {
    ll x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

char readc() {
	char c = getchar();
	while (!('A' <= c && c <= 'Z')) c = getchar();
	return c;
}

#define root (ch[0][1])
const int maxn = 80010;
char opt;
int n, m, x, y, t, d;
int pos[maxn], val[maxn], siz[maxn], fa[maxn], ch[maxn][2];

void update(int x) {
	siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1;
}
int identify(int x) {
	return ch[fa[x]][0] == x ? 0 : 1;
}
void connect(int x, int f, int side) {
	fa[x] = f, ch[f][side] = x;
}
void rotate(int x) {
	int f = fa[x], fside = identify(x);
	int ff = fa[f], ffside = identify(f);
	int y = ch[x][fside ^ 1];
	connect(y, f, fside);
	connect(f, x, fside ^ 1);
	connect(x, ff, ffside);
	update(f), update(x);
}
void splay(int at, int to) {
	to = fa[to];
	while (fa[at] != to) {
		int up = fa[at];
		if (fa[up] == to) rotate(at);
		else if (identify(at) == identify(up)) rotate(up), rotate(at);
		else rotate(at), rotate(at);
	}
}
int find(int u, int k) {
//	printf("FIND %d %d | %d %d %d\n", u, k, siz[ch[u][0]], siz[u], siz[ch[u][1]]);
	if (k <= siz[ch[u][0]]) return find(ch[u][0], k);
	if (k == siz[ch[u][0]] + 1) return u;
	return find(ch[u][1], k - siz[ch[u][0]] - 1);
}
void dfsPrint(int u, int f, int cnt) {
	for (int i = 1; i <= cnt; i++) printf("  ");
	printf("%d(%d,%d) -> %d(%d,%d)\n", f, val[f], siz[f], u, val[u], siz[u]);
	if (ch[u][0]) dfsPrint(ch[u][0], u, cnt + 1);
	if (ch[u][1]) dfsPrint(ch[u][1], u, cnt + 1);
}
void print() {
	printf("=== %c %d ===\n", opt, t);
	for (int i = 1; i <= n; i++)
		printf("%d ", pos[i]);
	puts("");
	for (int i = 1; i <= n; i++)
		printf("%d ", val[i]);
	puts("");
	for (int i = 1; i <= n; i++)
		printf("%d ", siz[i]);
	puts("");
	for (int i = 1; i <= n; i++)
		printf("%d ", fa[i]);
	puts("");
	for (int i = 1; i <= n; i++)
		printf("%d ", ch[i][0]);
	puts("");
	for (int i = 1; i <= n; i++)
		printf("%d ", ch[i][1]);
	puts("");
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read(), m = read();
	root = 1;
	for (int i = 1; i <= n; i++) {
		val[i] = read(), pos[val[i]] = i;
		siz[i] = 1, ch[i][0] = ch[i][1] = 0;
		if (i > 1) {
			ch[i - 1][1] = i, fa[i] = i - 1;
			splay(i, root);
		}
	}
	
	while (m--) {
		opt = readc(), t = read();
//		print();
		switch (opt) {
			case 'T':
				x = pos[t], y = 0;
				splay(x, root);
				if (!ch[x][0]) break;
				if (!ch[x][1]) {
					ch[x][1] = ch[x][0];
					ch[x][0] = 0;
					break;
				}
				y = find(root, siz[ch[x][0]] + 2);
				fa[ch[x][0]] = y;
				ch[y][0] = ch[root][0];
				ch[root][0] = 0;
				splay(y, root);
				break;
			case 'B':
				x = pos[t], y = 0;
				splay(x, root);
				if (!ch[x][1]) break;
				if (!ch[x][0]) {
					ch[x][0] = ch[x][1];
					ch[x][1] = 0;
					break;
				}
				y = find(root, siz[ch[x][0]]);
				fa[ch[x][1]] = y;
				ch[y][1] = ch[root][1];
				ch[root][1] = 0;
				splay(y, root);
				break;
			case 'I':
				x = pos[t], d = read();
				if (!d) break;
				splay(x, root);
				y = find(root, siz[ch[x][0]] + 1 + d);
//    			printf(">>> %d %d\n", x, y);
//				printf(">>> %d %d %d %d\n", pos[val[x]], pos[val[y]], val[x], val[y]);
				swap(pos[val[x]], pos[val[y]]);
				swap(val[x], val[y]);
//				printf(">>> %d %d %d %d\n", pos[val[x]], pos[val[y]], val[x], val[y]);
				break;
			case 'A':
				x = pos[t];
				splay(x, root);
				printf("%d\n", siz[ch[x][0]]);
				break;
			case 'Q':
				printf("%d\n", val[find(root, t)]);
				break;
		}
	}

	return 0;
}
