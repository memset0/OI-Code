#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}
const int maxn = 4e6 + 10;
const double pi = acos(-1.0);
int n, k, n1, n2, rev[maxn];
struct cp {
	double x, y;
	cp(double _x = 0, double _y = 0) {
		x = _x, y = _y;
	}
	cp operator + (const cp &b) const {
		return cp(x + b.x, y + b.y);
	}
	cp operator - (const cp &b) const {
		return cp(x - b.x, y - b.y);
	}
	cp operator * (const cp &b) const {
		return cp(x * b.x - y * b.y, x * b.y + y * b.x);
	}
} a[maxn], b[maxn];
void fft(cp *a, int flag) {
	for (int i = 0; i < n; i++)
		if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int len = 1; len < n; len <<= 1) {
		cp wn(cos(pi / len), flag * sin(pi / len));
		for (int i = 0; i < n; i += (len << 1)) {
			cp w(1.0, 0);
			for (int j = 0; j < len; j++, w = w * wn) {
				cp lt = a[i + j], rt = w * a[i + j + len];
				a[i + j] = lt + rt;
				a[i + j + len] = lt - rt;
			}
		}
	}
}
int main() {
	// freopen("INPUT", "r", stdin);
	n1 = read(), n2 = read();
	for (int i = 0; i <= n1; i++) a[i] = cp(read(), 0);
	for (int i = 0; i <= n2; i++) b[i] = cp(read(), 0);
	n = 1; while (n < n1 + n2 + 2) n <<= 1, ++k;
	for (int i = 0; i < n; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
	fft(a, 1), fft(b, 1);
	for (int i = 0; i < n; i++) a[i] = a[i] * b[i];
	fft(a, -1);
	for (int i = 0; i <= n1 + n2; i++) printf("%d ", (int)(a[i].x / n + 0.5));
	return 0;
}