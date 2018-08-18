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

const ll mod = 1e9 + 7;
int t, n;

struct martix {

	int n, m;
	ll a[3][3];

	martix (int nnn = 3, int mmm = 3,
			int a00 = 0, int a01 = 0, int a02 = 0,
			int a10 = 0, int a11 = 0, int a12 = 0,
			int a20 = 0, int a21 = 0, int a22 = 0) {
		n = nnn, m = mmm;
		a[0][0] = a00, a[0][1] = a01, a[0][2] = a02;
		a[1][0] = a10, a[1][1] = a11, a[1][2] = a12;
		a[2][0] = a20, a[2][1] = a21, a[2][2] = a22;
	}
 	martix operator * (const martix &b) const {
 		martix c(n, b.m);
 		for (int i = 0; i < n; i++)
 			for (int j = 0; j < b.m; j++)
 				for (int k = 0; k < m; k++)
 					c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % mod;
 		return c;
	}

	void print() {
		printf(">>> %d %d\n", n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				printf("%lld ", a[i][j]);
			puts("");
		}
	}

};

martix Pow(martix a, int l) {
	martix ans = a, mul = a;
	l--;
	while (l) {
		if (l & 1) ans = ans * mul;
		mul = mul * mul;
		l >>= 1;
	}
	return ans;
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	t = read();
	while (t--) {
		n = read();
		if (n == 1 || n == 2 || n == 3) {
			printf("1\n");
		} else {
			martix a(1, 3, 1, 1, 1, 0, 0, 0, 0, 0, 0);
			martix b(3, 3, 1, 0, 1, 1, 0, 0, 0, 1, 0);
			printf("%lld\n", (a * Pow(b, n - 3)).a[0][0]);
		}
	}

	return 0;
}

// 1 0 1
// 1 0 0
// 0 1 0