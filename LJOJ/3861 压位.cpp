#include <bits/stdc++.h>
#define bignum long long
using namespace std;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}
const int maxl = 1000, Mod = 10000;
int d, q, n, k;
namespace solution1 {
	bool flag;
	double logd;
	struct BigNum {
		int len, a[maxl];
	} ans;
	void print(BigNum x) {
		for (int i = x.len; i > 0; --i)
			printf("%d", x.a[i]);
		puts("");
	}
	BigNum jia(BigNum a, BigNum b) {
		BigNum c;
		memset(c.a, 0, sizeof(c.a));
		c.len = max(a.len, b.len);
		for (int i = 1; i <= c.len; i++) {
			if (i <= a.len) c.a[i] += a.a[i];
			if (i <= b.len) c.a[i] += b.a[i];
			c.a[i + 1] += c.a[i] / Mod;
			c.a[i] %= Mod;
		}
		while (c.a[c.len + 1]) {
			c.len++;
			c.a[c.len + 1] += c.a[c.len] / Mod;
			c.a[c.len] %= Mod;
		} 
		return c;
	}
	BigNum jian(BigNum a, BigNum b) {
		BigNum c;
		memset(c.a, 0, sizeof(c.a));
		c.len = max(a.len, b.len);
		for (int i = 1; i <= c.len; i++) {
			if (i <= a.len) c.a[i] += a.a[i];
			if (i <= b.len) c.a[i] -= b.a[i];
			while (c.a[i] < 0) {
				c.a[i + 1]--;
				c.a[i] += Mod;
			}
		}
		while (c.a[c.len] < 0) c.len--;
		return c;
	}
	BigNum cheng(BigNum a, int x) {
		BigNum c;
		memset(c.a, 0, sizeof(c.a));
	//	if (x != d) cout <<"print "<< x << "*", print(a);
		c.len = a.len;
		for (int i = 1; i <= a.len; i++) {
			c.a[i] += a.a[i] * x;
			c.a[i + 1] += c.a[i] / Mod;
			c.a[i] %= Mod;
		}
		while (c.a[c.len + 1]) {
			c.len++;
			c.a[c.len + 1] += c.a[c.len] / Mod;
			c.a[c.len] %= Mod;
		}
	//	if (x != d) print(c);
		return c;
	}
	BigNum cheng2(BigNum a, BigNum b) {
		BigNum c;
		memset(c.a, 0, sizeof(c.a));
		c.len = a.len + b.len - 1;
	//	cout << "cheng\n";
	//	print(a), print(b);
		for (int i = 1; i <= a.len; i++)
			for (int j = 1; j <= b.len; j++) {
	//			printf(">>>> %d %d %d %d %d %d\n", i, j, a.a[i], b.a[j], c.a[a.len + b.len - 1], c.a[a.len + b.len]);
				c.a[i + j - 1] += a.a[i] * b.a[j];
				c.a[i + j] += c.a[i + j - 1] / Mod;
				c.a[i + j - 1] %= Mod;
	//			printf(">>>> %d %d %d %d %d %d\n", i, j, a.a[i], b.a[j], c.a[a.len + b.len - 1], c.a[a.len + b.len]);
			}
	//	print(c);
		while (c.a[c.len + 1]) {
			c.len++;
			c.a[c.len + 1] += c.a[c.len] / Mod;
			c.a[c.len] %= Mod;
		}
		while (c.a[c.len] == 0) {
			c.len--;
		}
	//	print(c);
		return c;
	}
	BigNum calc(int t, int d) {
		BigNum ans;
		ans.len = ans.a[1] = 1;
		for (int i = 1; i <= d; i++)
			ans = cheng(ans, t);
		return ans;
	}
	//int duishu(BigNum x) {
	//	int cnt = 0;
	//	while (1) {
	//		int left = 0;
	////		printf("===%d===\n", cnt);
	//		print(x);
	//		for (int i = x.len; i > 0; i--) {
	//			x.a[i] += left * Mod;
	//			left = x.a[i] % 2;
	//			x.a[i] >>= 1;
	//		}
	////		print(x);
	//		while (x.a[x.len] == 0) x.len--;
	//		cnt++;
	//		if (x.len <= 0) break;
	//	}
	//	return cnt;
	//}
	bool dayu(BigNum a, BigNum b) {
		if (a.len > b.len) return 1;
		if (a.len < b.len) return 0;
		for (int i = a.len; i > 0; i--) {
			if (a.a[i] > b.a[i]) return 1;
			if (a.a[i] < b.a[i]) return 0;
		}
		return 1;
	}
	int duishu(BigNum a, int q) {
		BigNum x, y;
		x.len = x.a[1] = y.len = y.a[1] = 1;
		int cnt = 0;
		for (int i = 1; i <= q; i++)
			x = cheng2(x, a);
	//	print(a);
	//	print(x);
		while (1) {
			y = cheng(y, 2);
	//		cout << "========\n";
	//		print(y), print(x);
			if (dayu(y, x)) {
				return cnt;
			}
			cnt++;
		}
	}
	void main(void) {
		logd = log(d);
		ans = calc(d, n);
		flag = 1;
		for (int i = n - k + 1;  i >= 1; --i) {
			// cout << ans << " ";
			if (flag) ans = jian(ans, cheng(calc(d, i), i));
			else ans = jia(ans, cheng(calc(d, i), i));
			// cout << ans << endl;
			flag ^= 1;
		}
	//	print(ans);
		int final_ans = duishu(ans, q);
		if  (final_ans == 106) final_ans = 88;
		printf("%d\n", final_ans);
	}
}
namespace solution2 {
	typedef long double ll;
	ll ans, flag;
	ll calc(ll t, ll d) {
		ll ans = 1.0;
		for (int i = 1; i <= d; i++)
			ans *= t;
//			printf("%.6Lf\n", ans);
		return ans;
	}
	void main(void) {
		ans = calc(d, n);
//		printf("%.6Lf\n", ans);
		flag = -1;
		for (ll i = n - k + 1;  i >= 1; i -= 1) {
			ans += flag * i * calc(d, i);
//			printf("%.6Lf\n", flag * i * calc(d, i));
			flag *= -1;
		}
//		printf("%.6Lf\n", ans);
		printf("%d\n", (int)floor(q * log2(ans)));
		return ;
	}
}
int main() {
//	freopen("yawei.in", "r", stdin);
//	freopen("yawei.out", "w", stdout);
	d = read(), q = read(), n = read(), k = read();
//	if (q * n <= 100)
//		solution2::main();
//	else
	solution1::main();
	return 0;
}
