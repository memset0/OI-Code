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

const int maxn = 4e6 + 10;
const double PI = acos(-1.0);
int n = 1, n1, n2;
struct cp {
	double x, y;
	cp(double a = 0, double b = 0) {
		x = a, y = b;
	}
} c1[maxn], c2[maxn];
cp operator + (cp a, cp b) { return cp(a.x + b.x, a.y + b.y); }
cp operator - (cp a, cp b) { return cp(a.x - b.x, a.y - b.y); }
cp operator * (cp a, cp b) { return cp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }

struct FastFourierTransform {
	cp o1[maxn], o2[maxn];
	void init() {
		for (int i = 0; i < n; i++) {
			o1[i] = cp(cos(2 * PI / n * i),  sin(2 * PI / n * i));
			o2[i] = cp(cos(2 * PI / n * i), -sin(2 * PI / n * i));
		}
	}
	void trans(cp *a, cp *o) {
		int k = 0; while ((1 << k) < n) k++;
		for (int i = 0; i < n; i++) {
			int t = 0;
			for (int j = 0; j < k; j++)
				if (i & (1 << j))
					t |= (1 << (k - j - 1));
			if (i < t) swap(a[i], a[t]);
		}
		for (int l = 2; l <= n; l <<= 1) {
			int m = l >> 1;
			for (int i = 0; i < n; i += l)
				for (int j = 0; j < m; j++) {
					cp t = o[n / l * j] * a[m + i + j];
					a[i + j + m] = a[i + j] - t;
					a[i + j] = a[i + j] + t;
				}
		}
	}
	void dft(cp *a) {
		trans(a, o1);
	}
	void idft(cp *a) {
		trans(a, o2);
		for (int i = 0; i < n; i++)
			a[i].x /= n;
	}
} fft;

int main() {
	n1 = read() + 1, n2 = read() + 1;
	for (int i = 0; i < n1; i++) c1[i].x = read();
	for (int i = 0; i < n2; i++) c2[i].x = read();
	while (n < n1 + n2) n <<= 1;
	fft.init(), fft.dft(c1), fft.dft(c2);
	for (int i = 0; i < n; i++) c1[i] = c1[i] * c2[i];
	fft.idft(c1);
	for (int i = 0; i < n1 + n2 - 1; i++)
		printf("%d ", (int)floor(c1[i].x + 0.5));
	putchar('\n');
	return 0;
}
