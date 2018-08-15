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
	while (!('A' <= c && c <= 'Z')) c = getchar();
	return c;
}

void print_array(int *arr, int length, string name = "None") {
	cout << "    " << name << ' ';
	for (int i = 1; i <= length; i++)
		printf("%3d", arr[i]);
	puts("");
	return;
}

// Splay

#define root (ch[0][1])

const int maxn = 100010;
int tot, points;
int val[maxn], sum[maxn], cnt[maxn], fa[maxn], ch[maxn][2];

void print() {
	printf("root = %d points = %d\n", root, points);
	print_array(val, tot, "val");
	print_array(sum, tot, "sum");
	print_array(cnt, tot, "cnt");
	print_array(fa , tot, "fa ");
	//cout << "ch0" << " "; for (int i = 1; i <= tot; i++) cout << ch[i][0] << " "; cout << endl;		
	//cout << "ch1" << " "; for (int i = 1; i <= tot; i++) cout << ch[i][1] << " "; cout << endl;
}

void update(int x) {
	sum[x] = sum[ch[x][0]] + sum[ch[x][1]] + cnt[x];
}
int identify(int x) {
	return ch[fa[x]][0] == x ? 0 : 1;
}
void connect(int x, int f, int side) {
	fa[x] = f, ch[f][side] = x;
}
void rotate(int x) {
	int f = fa[x], ff = fa[f], fson = identify(x), ffson = identify(f), y = ch[x][fson ^ 1];
	connect(y, f, fson), connect(f, x, fson ^ 1), connect(x, ff, ffson);
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

void crepoint(int uval, int ufa, int side) {
	int x = ++tot;
	val[x] = uval, sum[x] = cnt[x] = 1;
	fa[x] = ufa, ch[x][0] = ch[x][1] = 0;
}
void delpoint(int x) {
	val[x] = sum[x] = cnt[x] = 0;
	fa[x] = ch[x][0] = ch[x][1] = 0;
}

void insert(int v) {
	int u = root;
	points++;
	if (points == 1) {
		crepoint(v, 0, 1);
		root = tot;
		return;
	}
	while (u) {
		sum[u]++;
		if (v == val[u]) {
			cnt[u]++;
			splay(u, root);
			return;
		}
		int side = v < val[u] ? 0 : 1;
		if (!ch[u][side]) {
			crepoint(v, u, side);
			ch[u][side] = tot;
			update(u);
			splay(tot, root);
			return;
		}
		u = ch[u][side];
	}
}

void erase(int x) {
    splay(x, root);
    points -= cnt[x];
    if (!ch[x][0]) {
        root = ch[x][1];
        fa[ch[x][1]] = 0;
    } else {
        int lft = ch[x][0], rit = ch[x][1];
        while (ch[lft][1]) lft = ch[lft][1];
        splay(lft, ch[x][0]);
        connect(rit, lft, 1);
        connect(lft, 0, 1);
        update(lft);
    }
    delpoint(x);
}
void erase_tree(int x) {
	ch[fa[x]][identify(x)] = 0;
	if (sum[x] == cnt[x]) {
		points -= cnt[x];
		delpoint(x);
		return;
	}
	if (ch[x][0]) erase_tree(ch[x][0]);
	if (ch[x][1]) erase_tree(ch[x][1]);
	points -= cnt[x], delpoint(x);
	if (fa[x]) update(fa[x]);
}

int findkth(int k) {
	int u = root;
//printf("findkth: %d\n", k);
	while (u) {
//printf("findkth : 1 : %d %d\n", u, k);
		if (k <= sum[ch[u][1]]) u = ch[u][1];
		else if (k <= sum[ch[u][1]] + cnt[u]) break;
		else k -= sum[ch[u][1]] + cnt[u], u = ch[u][0];
//printf("findkth : 2 : %d %d\n", u, k);
	}
	if (u) splay(u, root);
	return val[u];
}

int m, x, Min, Dta, Died;
char opt;

void refresh(int u = root) {
	if (!u) return;
//printf("refresh %d\n", u);
	if (val[u] + Dta < Min) {
//printf("refresh erase %d\n", u);
		Died += cnt[u] + sum[ch[u][0]];
		if (ch[u][0]) erase_tree(ch[u][0]);
		refresh(ch[u][1]);
		erase(u); 
	} else refresh(ch[u][0]);
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
//	freopen("data.txt", "r", stdin);
	
	m = read(), Min = read();
	for (int i = 1; i <= m; i++) {
		opt = readc();
//printf(">>> [%d] %c Dta = %d\n", i, opt, Dta);
		switch (opt) {
			case 'I':
				x = read();
				if (x >= Min) {
					insert(x - Dta);
				}
				break;
			case 'A':
				Dta += read();
				refresh();
				break;
			case 'S':
				Dta -= read();
				refresh();
				break;
			case 'F':
				x = read();
				if (x > points) printf("-1\n");
				else printf("%d\n", findkth(x) + Dta);
				break;
		}
//		print();
	}
	printf("%d\n", Died);
	
	return 0;
}
