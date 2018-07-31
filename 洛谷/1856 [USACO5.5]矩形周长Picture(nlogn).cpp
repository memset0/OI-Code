#include <bits/stdc++.h>
using namespace std;

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 5010;
int n, i, j, ans, t[4][maxn], tmp[maxn];

struct Square {
	int left, bottom, right, top;
} a[maxn], hide[maxn], show[maxn];

void print_arr(string name, int *a) {
	if (name != "") cout << name << " ";
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void reset(int *f, int opt) {
	print_arr("", f);
	copy(f + 1, f + n + 1, tmp + 1);
	sort(f + 1, f + n + 1);
	int len = unique(f + 1, f + n + 1) - f;
	switch (opt) {
		case 0:
			for (int i = 1; i <= n; i++)
				a[i].left = lower_bound(f + 1, f + len + 1, tmp[i]) - f;
			for (int i = 1; i <= n; i++)
				cout << lower_bound(f + 1, f + len + 1, tmp[i]) - f << " ";
			cout << endl;
			break;
		case 1:
			for (int i = 1; i <= n; i++)
				a[i].bottom = lower_bound(f + 1, f + len + 1, tmp[i]) - f;
			for (int i = 1; i <= n; i++)
				cout << lower_bound(f + 1, f + len + 1, tmp[i]) - f << " ";
			cout << endl;
			break;
		case 2:
			for (int i = 1; i <= n; i++)
				a[i].right = lower_bound(f + 1, f + len + 1, tmp[i]) - f;
			for (int i = 1; i <= n; i++)
				cout << lower_bound(f + 1, f + len + 1, tmp[i]) - f << " ";
			cout << endl;
			break;
		case 3:
			for (int i = 1; i <= n; i++)
				a[i].top = lower_bound(f + 1, f + len + 1, tmp[i]) - f;
			for (int i = 1; i <= n; i++)
				cout << lower_bound(f + 1, f + len + 1, tmp[i]) - f << " ";
			cout << endl;
			break;
	}
}

bool sort_top(Square a, Square b) {
	return a.top < b.top;
}
bool sort_bottom(Square a, Square b) {
	return a.bottom < b.bottom;
}
bool sort_right(Square a, Square b) {
	return a.right < b.right;
}
bool sort_left(Square a, Square b) {
	return a.left < b.left;
}

namespace Tree {
	struct Node {
		int l, r, mid, cnt, rep;
	} p[200000];
	void build(int u, int l, int r) {
		p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
		p[u].mid = p[u].cnt = p[u].lflag = p[u].rflag = 0;
		if (l == r) return;
		build(u << 1, l, p[u].mid);
		build(u << 1 | 1, p[u].mid + 1, r);
	}
	void refresh(int u) {
		if (p[u].rep) {
			p[u].cnt = p[u].r - p[u].l + 1;
		} else if (p[u].l == p[u].r) {
			p[u].cnt = 0;
		} else {
			p[u].cnt = p[u << 1].cnt + p[u << 1 | 1].cnt;
		}
	}
	void update(int u, int l, int r, int v) {
		if (l == p[u].l && r == p[u].r) {
			p[u].rep += v;
			refresh(u);
			return 0;
		}
		if (r <= p[u].mid) update(u << 1, l, r, v);
		else if (l > p[u].mid) update(u << 1 | 1, l, r, v);
		else update(u << 1, l, p[u].mid, v), update(u << 1 | 1, p[u].mid + 1, r, v);
		refresh(u);
	}
}

using namespace Tree;

inline void build() {
	Tree::build(1, 1, n);
}
inline void update(int l, int r, int v) {
	Tree::update(1, l, r - 1, v);
}
inline int query(int l, int r) {
	Tree::query(1, l, r - 1);
}

int main() {

	// freopen("INPUT", "r", stdin);

	n = read();
	for (int i = 1; i <= n; i++) {
		t[0][i] = read(), t[1][i] = read();
		t[2][i] = read(), t[3][i] = read();
	}

	reset(t[0], 0);
	reset(t[1], 1);
	reset(t[2], 2);
	reset(t[3], 3);

	copy(a + 1, a + n + 1, hide + 1);
	copy(a + 1, a + n + 1, show + 1);
	sort(hide + 1, hide + n + 1, sort_top);
	sort(show + 1, show + n + 1, sort_bottom);

	i = j = 1;
	build();
	for (int dep = 0; dep <= 20000; dep++) {
		while (show[i].bottom == dep && i <= n) {
			// printf("SHOW %d == %d : %d %d\n", i, dep, show[i].bottom, show[i].top);
			ans += show[i].right - show[i].left - query(show[i].left, show[i].right);
			// printf("ANS += %d\n", show[i].right - show[i].left - query(show[i].left, show[i].right));
			update(show[i].left, show[i].right, 1);
			i++;
		}
		while (hide[j].top == dep && j <= n) {
			// printf("HIDE %d == %d : %d %d\n", j, dep, hide[j].bottom, hide[j].top);
			update(hide[j].left, hide[j].right, -1);
			ans += hide[j].right - hide[j].left - query(hide[j].left, hide[j].right);
			// printf("ANS += %d\n", hide[j].right - hide[j].left - query(hide[j].left, hide[j].right));
			j++;
		}
	}

	// printf("%d\n", ans);

	copy(a + 1, a + n + 1, hide + 1);
	copy(a + 1, a + n + 1, show + 1);
	sort(hide + 1, hide + n + 1, sort_right);
	sort(show + 1, show + n + 1, sort_left);


	i = j = 1;
	build();
	for (int dep = 0; dep <= 20000; dep++) {
		while (show[i].left == dep && i <= n) {
			// printf("SHOW %d == %d : %d %d\n", i, dep, show[i].left, show[i].right);
			ans += show[i].top - show[i].bottom - query(show[i].bottom, show[i].top);
			// printf("ANS += %d\n", show[i].top - show[i].bottom - query(show[i].bottom, show[i].top));
			update(show[i].bottom, show[i].top, 1);
			i++;
		}
		while (hide[j].right == dep && j <= n) {
			// printf("HIDE %d == %d : %d %d\n", j, dep, hide[j].left, hide[j].right);
			update(hide[j].bottom, hide[j].top, -1);
			ans += hide[j].top - hide[j].bottom - query(hide[j].bottom, hide[j].top);
			// printf("ANS += %d\n", hide[j].top - hide[j].bottom - query(hide[j].bottom, hide[j].top));
			j++;
		}
	}

	printf("%d\n", ans);

	return 0;
}