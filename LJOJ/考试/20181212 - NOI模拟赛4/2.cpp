// =================================
//   author: memset0
//   date: 2018.12.13 12:20:26
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template < class T > inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template < class T > inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template < class T > inline void maxd(T &a, T b) { if (b > a) a = b; }
template < class T > inline void mind(T &a, T b) { if (b < a) a = b; }
template < class T > inline void print(T x, char c) { print(x), putchar(c); }

const int N = 70;
int n, m, x, y, c, way, tmp, dtx, dty, pos, minx, miny, maxx, maxy;
int l[4], r[4], cho[4], op[N], id[N], al[N], ar[N], ans[N];

void solve() {
	way = l[0] = l[1] = l[2] = l[3] = r[0] = r[1] = r[2] = r[3] = 0;
	for (int i = 1; i <= n; i++) {
		way = (way + (op[i] == 'L' ? 1 : -1) + 4) % 4;
		l[way] += al[i], r[way] += ar[i];
	}
	maxx = r[0] - l[2], minx = l[0] - r[2];
	maxy = r[1] - l[3], miny = l[1] - r[3];
	if (minx <= x && x <= maxx && miny <= y && y <= maxy) {
		print(n, '\n');
		dtx = maxx - x, dty = maxy - y;
		cho[0] = r[0], cho[1] = r[1], cho[2] = l[2], cho[3] = l[3];
		tmp = std::min(r[0] - l[0], dtx), dtx -= tmp, cho[0] -= tmp;
		tmp = std::min(r[2] - l[2], dtx), dtx -= tmp, cho[2] += tmp;
		tmp = std::min(r[1] - l[1], dty), dty -= tmp, cho[1] -= tmp;
		tmp = std::min(r[3] - l[3], dty), dty -= tmp, cho[3] += tmp;
		way = 0;
		for (int i = 1; i <= n; i++) {
			way = (way + (op[i] == 'L' ? 1 : -1) + 4) % 4;
			ans[i] = al[i], cho[way] -= al[i];
		}
		way = 0;
		for (int i = 1; i <= n; i++) {
			way = (way + (op[i] == 'L' ? 1 : -1) + 4) % 4;
			tmp = std::min(cho[way], ar[i] - al[i]);
			ans[i] += tmp, cho[way] -= tmp;
		}
		for (int i = 1; i <= n; i++) {
			putchar(op[i]), putchar(' ');
			print(ans[i], '\n');
		}
		exit(0);
	}
}

void main() {
	srand(20040725);
	read(n), read(x), read(y);
	for (int i = 1; i <= n; i++) {
		while (c = getchar(), c != 'L' && c != 'R' && c != '?');
		op[i] = c; if (c == '?') id[pos++] = i;
		read(al[i]), read(ar[i]);
	}
	if (pos <= 20) {
		for (int x = 0; x < (1 << pos); x++) {
			for (int i = 0; i < pos; i++)
				op[id[i]] = (x & 1 << i) ? 'R' : 'L';
			solve();
		}
	} else {
		for (int T = 2000000; T--; ) {
			for (int i = 0, x; i < pos; i += 20) {
				x = rand();
				for (int j = 0; j < 20 && i + j < pos; j++)
					op[id[i + j]] = (x & 1 << j) ? 'R' : 'L';
			}
			solve();
		}
	}
	puts("-1");
}

} signed main() { return ringo::main(), 0; }