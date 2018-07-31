#include <bits/stdc++.h>
using namespace std;

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 5010, maxm = 20010;
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
	switch (opt) {
		case 0:
			for (int i = 1; i <= n; i++)
				a[i].left = f[i] + 10000;
			break;
		case 1:
			for (int i = 1; i <= n; i++)
				a[i].bottom = f[i] + 10000;
			break;
		case 2:
			for (int i = 1; i <= n; i++)
				a[i].right = f[i] + 10000;
			break;
		case 3:
			for (int i = 1; i <= n; i++)
				a[i].top = f[i] + 10000;
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

namespace Array {
	int f[maxm];
	void build(int u, int l, int r) {
		memset(f, 0, sizeof(f));
	}
	int query(int u, int l, int r) {
		int ans = 0;
		for (int i = l; i < r; i++)
			if (f[i]) ans++;
		// printf("QUERY %d %d %d\n", l - 10000, r - 10000, ans);
		// for (int i = 10000; i <= 10003; i++)
		// 	cout << f[i] << " ";
		// cout << endl;
		return ans;
	}
	void update(int u, int l, int r, int v) {
		for (int i = l; i < r; i++)
			f[i] += v;
		// printf("UPDATE %d %d %d \n", l - 10000, r - 10000, v);
		// for (int i = 10000; i <= 10003; i++)
		// 	cout << f[i] << " ";
		// cout << endl;
	}
}
using namespace Array;

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
	build(1, 1, n);
	for (int dep = 0; dep <= 20000; dep++) {
		while (show[i].bottom == dep && i <= n) {
			// printf("SHOW %d == %d : %d %d\n", i, dep, show[i].bottom, show[i].top);
			ans += show[i].right - show[i].left - query(1, show[i].left, show[i].right);
			// printf("ANS += %d\n", show[i].right - show[i].left - query(1, show[i].left, show[i].right));
			update(1, show[i].left, show[i].right, 1);
			i++;
		}
		while (hide[j].top == dep && j <= n) {
			// printf("HIDE %d == %d : %d %d\n", j, dep, hide[j].bottom, hide[j].top);
			update(1, hide[j].left, hide[j].right, -1);
			ans += hide[j].right - hide[j].left - query(1, hide[j].left, hide[j].right);
			// printf("ANS += %d\n", hide[j].right - hide[j].left - query(1, hide[j].left, hide[j].right));
			j++;
		}
	}

	// printf("%d\n", ans);

	copy(a + 1, a + n + 1, hide + 1);
	copy(a + 1, a + n + 1, show + 1);
	sort(hide + 1, hide + n + 1, sort_right);
	sort(show + 1, show + n + 1, sort_left);


	i = j = 1;
	build(1, 1, n);
	for (int dep = 0; dep <= 20000; dep++) {
		while (show[i].left == dep && i <= n) {
			// printf("SHOW %d == %d : %d %d\n", i, dep, show[i].left, show[i].right);
			ans += show[i].top - show[i].bottom - query(1, show[i].bottom, show[i].top);
			// printf("ANS += %d\n", show[i].top - show[i].bottom - query(1, show[i].bottom, show[i].top));
			update(1, show[i].bottom, show[i].top, 1);
			i++;
		}
		while (hide[j].right == dep && j <= n) {
			// printf("HIDE %d == %d : %d %d\n", j, dep, hide[j].left, hide[j].right);
			update(1, hide[j].bottom, hide[j].top, -1);
			ans += hide[j].top - hide[j].bottom - query(1, hide[j].bottom, hide[j].top);
			// printf("ANS += %d\n", hide[j].top - hide[j].bottom - query(1, hide[j].bottom, hide[j].top));
			j++;
		}
	}

	printf("%d\n", ans);

	return 0;
}