// luogu-judger-enable-o2
#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T > il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}

template < class T > il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}

const int maxn = 4e5 + 10, mod = 1e9 + 7;
const double pi = acos(-1);
int n, m, k, ans;
int f[maxn], sum[maxn], rev[maxn], cnt[maxn], pow[maxn];
char s[maxn];

struct complex {
	double x, y;
	il complex(double a = 0, double b = 0) { x = a, y = b; }
	il complex operator + (const complex &b) { return complex(x + b.x, y + b.y); }
	il complex operator - (const complex &b) { return complex(x - b.x, y - b.y); }
	il complex operator * (const complex &b) { return complex(x * b.x - y * b.y, x * b.y + y * b.x); }
} a[maxn];

void fft(complex *a, int flag) {
	for (int i = 0; i < m; i++) if (i < rev[i]) std::swap(a[i], a[rev[i]]);
	for (int len = 1; len < m; len <<= 1) {
		complex wn(cos(pi / len), flag * sin(pi / len));
		for (int i = 0; i < m; i += (len << 1)) {
			complex w(1, 0);
			for (int j = 0; j < len; j++, w = w * wn) {
				complex x = a[i + j], y = w * a[i + j + len];
				a[i + j] = x + y, a[i + j + len] = x - y;
			}
		}
	}
}

int query_sum(int l, int r) {
	if (l > r) return 0;
	if (l) return sum[r] - sum[l - 1];
	return sum[r];
}

int manacher() {
	int m = (n << 1) - 1, mid = 0, limit = -1, ans = 0;
	for (int i = m - 1; i >= 0; i--) s[i] = i & 1 ? '#' : s[i >> 1];
	for (int i = 0; i < m; i++) {
		if (i < limit) f[i] = std::min(f[mid * 2 - i], limit - i - 1); else f[i] = 0;
		for (int j = f[i] + i + 1; j < m && (2 * i - j) >= 0 && s[j] == s[2 * i - j]; j++) f[i]++;
		if (i + f[i] > limit) limit = i + f[i], mid = i;
	}
	for (int i = 0; i < m; i++) ans = (ans + ((f[i] + (s[i] == '#')) >> 1)) % mod;
	// for (int i = 0; i < m; i++) print(f[i]), putc(i == m - 1 ? '\n' : ' ');
	// for (int i = 0; i < m; i++) putc(s[i]), putc(i == m - 1 ? '\n' : ' ');
	return ans;
}

void main() {
	scanf("%s", s), n = strlen(s);
	for (int i = 0; i < n; i++) a[i] = s[i] == 'a' ? 0 : 1;
	for (int i = 0; i < n; i++) sum[i] = (i ? sum[i - 1] : 0) + (s[i] == 'a' ? 0 : 1);
	m = 1; while (m <= (n << 1)) m <<= 1, ++k;
	for (int i = 0; i < m; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
	pow[0] = 1; for (int i = 1; i <= n; i++) pow[i] = (pow[i - 1] << 1) % mod;
	fft(a, 1);
	for (int i = 0; i < m; i++) a[i] = a[i] * a[i];
	fft(a, -1);
	// for (int i = 0; i < n; i++) print(s[i] == 'a' ? 0 : 1),putc(i == n - 1 ? '\n' : ' ');
	// for (int i = 0; i < m; i++) print((int)(a[i].x / m + 0.5)), putc(i == m - 1 ? '\n' : ' ');
	for (int i = 0, len; i < n; i++) {
		cnt[i] = len = std::min(i, n - i - 1);
		cnt[i] -= query_sum(i - len, i) + query_sum(i, i + len);
		cnt[i] += (int)(a[i << 1].x / m + 0.5) + (s[i] == 'a' ? 0 : 1);
	}
	// for (int i = 0; i < n; i++) print(cnt[i]), putc(i == n - 1 ? '\n' : ' ');
	for (int i = 0; i < n; i++) ans = (ans + pow[cnt[i] + 1] - 2) % mod;
	// printf("ans1 = %d\n", ans);
	for (int i = 1, len; i < n; i++) {
		cnt[i] = len = std::min(i, n - i);
		cnt[i] -= query_sum(i - len, i + len - 1);
		cnt[i] += (int)(a[(i << 1) - 1].x / m + 0.5);
		// printf("%d : %d %d %d %d\n", i+1, len, query_sum(i - len, i + len - 1), (int)(a[(i << 1) - 1].x / m + 0.5), cnt[i]);
	}
	// for (int i = 0; i < n; i++) print(cnt[i]), putc(i == n - 1 ? '\n' : ' ');
	for (int i = 1; i < n; i++) ans = (ans + pow[cnt[i]] - 1) % mod;
	// printf("ans2 = %d\n", ans);
	printf("%d\n", (ans - manacher() + mod) % mod);
}

} int main() { return ringo::main(), 0; }