#include <bits/stdc++.h>
namespace wyl {

void read(int &x) {
    register char c = getchar();
    register bool f = false;
    while (!isdigit(c)) {
        f ^= c == '-';
        c = getchar();
    }
    x = 0;
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
}

void print(const int &x) {
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

using std::min;

const double inf = 1e40;
int n, m;

namespace solve1 {
	const int maxn = 1010;
	int x, y, opt, ans;
	double min, now;

	struct square {
		int i, x1, y1, x2, y2;
		inline double cross(int x, int y) {
			double u, v, ans = inf;
			u = x1 / (double)x * y;
			v = y1 / (double)y * x;
			if (y1 <= u && u <= y2) ans = fmin(ans, x1);
			if (x1 <= v && v <= x2) ans = fmin(ans, v);
			return ans;
		}
	} a[maxn];
	
	int main() {
		for (int i = 1; i <= m; i++) {
			read(opt);
			if (opt == 1) {
				++n;
				a[n].i = i;
				read(a[n].x1), read(a[n].y1);
				read(a[n].x2), read(a[n].y2);
//				if (i == 582)
//					printf(">>> %d %d %d %d\n", a[n].x1, a[n].y1, a[n].x2, a[n].y2);
			} else {
				read(x), read(y);
//				printf(">>> %d %d\n", x ,y);
				ans = 0;
//				for (int i = 1; i <= n; i++) {
//					now = a[i].cross(x, y);
////					printf("%d %d %.2lf\n", x, y, nowx);
//					if (now <= min || !ans) {
//						min = now;
//						ans = a[i].i;
//					}
//				}
				if (!x) {
					int min;
					for (int i = 1; i <= n; i++)
						if (!a[i].x1) {
							if (a[i].y1 <= min || !ans)
								ans = a[i].i, min = a[i].y1;
						}
				} else if (!y) {
					int min;
					for (int i = 1; i <= n; i++)
						if (!a[i].y1) {
							if (a[i].x1 <= min || !ans)
								ans = a[i].i, min = a[i].x1;
						}
				} else {
					for (int i = 1; i <= n; i++) {
						now = a[i].cross(x, y);
						if (now <= min || !ans) {
							min = now;
							ans = a[i].i;
						}
					}
				}
				print(min == inf ? 0 : ans), putchar('\n');
			}
		}
		return 0;
	}
}

namespace solve2 {
	const int maxn = 100010, maxm = 205;
	int u, a, b, c, d, x, y, opt, ans;
	double t, min;
	
	struct node {
		int l, r, mid, c, tag;
	} p1[maxm][maxm << 3], p2[maxm][maxm << 3];
	
	inline void pushup(int u, int l, node *p) {
		p[u].c = p[u].tag = l;
	}
	
	inline void pushdown(int u, node *p) {
		if (p[u].tag) {
			if (p[u].l != p[u].r) {
				pushup(u << 1, p[u].tag, p);
				pushup(u << 1 | 1, p[u].tag, p);
			}
			p[u].tag = 0;
		}
	}
	
	void build(int u, int l, int r, node *p) {
		p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
		if (l == r) return;
		build(u << 1, l, p[u].mid, p);
		build(u << 1 | 1, p[u].mid + 1, r, p);
	}
	
	void modify(int u, int l, int r, int c, node *p) {
//		printf("modify %d %d %d %d\n", u, l, r, c);
		pushdown(u, p);
		if (p[u].l == l && p[u].r == r) {
			pushup(u, c, p);
			return;
		}
		if (r <= p[u].mid) modify(u << 1, l, r, c, p);
		else if (l > p[u].mid) modify(u << 1 | 1, l, r, c, p);
		else {
			modify(u << 1, l, p[u].mid, c, p);
			modify(u << 1 | 1, p[u].mid + 1, r, c, p);
		}
	}
	
	int query(int u, int k, node *p) {
		pushdown(u, p);
//		printf("query %d %d %d %d\n", u, k, p[u].l, p[u].r);
		if (k > p[u].r) return 0;
		if (p[u].l == p[u].r) return p[u].c;
		if (k <= p[u].mid) return query(u << 1, k, p);
		else return query(u << 1 | 1, k, p);
	}
	
	inline void update(double now, int id, bool flag) {
		if (now < min || !ans) {
//			printf(">>>>>>>>>>>>> %.2lf %d %c\n", now, id, flag ? 'L' : 'R');
			min = now;
			ans = id;
		} else if (now == min && id > ans) {
			ans = id;
		}
	}
	
	int main() {
		for (int i = 0; i <= 200; i++) {
			build(1, 1, 401, p1[i]);
			build(1, 1, 401, p2[i]);
		}
		for (int i = 1; i <= m; i++) {
			read(opt);
			if (opt == 1) {
				read(a), read(b), read(c), read(d);
				modify(1, b << 1 | 1, d << 1 | 1, i, p1[a]);
				modify(1, a << 1 | 1, c << 1 | 1, i, p2[b]);
//				printf("L %d %d %d %d\n", i, a, b << 1 | 1, d << 1 | 1);
//				printf("R %d %d %d %d\n", i, b, a << 1 | 1, c << 1 | 1);
			} else {
				read(x), read(y);
//				printf(">> %d %d\n", x, y);
				ans = 0, min = inf;
				for (int i = 0; i <= 200; i++) {
					t = i / (double)x * y;
//					printf("%d : %.2lf %d\n", i, t, (t == floor(t) ? (int)(t) << 1 | 1 : (int)(floor(t) + 1) << 1) - 1);
					u = query(1, t == floor(t) ? (int)(t) << 1 | 1 : (int)(floor(t) + 1) << 1, p1[i]);
					if (u) update(i, u, 1);
				}
				for (int i = 0; i <= 200; i++) {
					t = i / (double)y * x;
//					printf("%d : %.2lf %d\n", i, t, (t == floor(t) ? (int)(t) << 1 | 1 : (int)(floor(t) + 1) << 1) - 1);
					u = query(1, t == floor(t) ? (int)(t) << 1 | 1 : (int)(floor(t) + 1) << 1, p2[i]);
					if (u) update(t, u, 0);
				}
				print(ans), putchar('\n');
			}
		}
		return 0;
	}
}

int main() {
	// freopen("raytracing.in", "r", stdin);
	// freopen("raytracing.out", "w", stdout);
//	freopen("3.txt", "r", stdin);
//	freopen("1.txt", "w", stdout);

	read(m);
	if (m <= 1000) return solve1::main();
	solve2::main();
    
    return 0;
}

} int main() { wyl::main(); return 0; }
