#include <bits/stdc++.h>
using namespace std;
const int L = 2, M = 1000000007;
struct matrix {
	long long a[2][2];
} a;
long long n;
matrix mul(matrix a, matrix b) {
	matrix c;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++)
			c.a[i][j] = 0;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++)
			for (int k = 0; k < L; k++)
				c.a[i][j] = (c.a[i][j] + (a.a[i][k] * b.a[k][j]) % M) % M;
    return c;
}
matrix mi(matrix x, long long p) {
	if (p == 1) return a;
	if (p % 2) {
		matrix t = mi(x, p / 2);
		return mul(t, mul(t, x));
	} else {
		matrix t = mi(x, p / 2);
		return mul(t, t);
	}
}
int main() {
	cin >> n;
	if (n == 0) printf("0\n");
	else if (n == 1) printf("1\n");
	else if (n == 2) printf("1\n");
	else {
		a = {{{1, 1}, {1, 0}}};
		matrix s = mi(a, n - L);
		printf("%d\n", (s.a[0][0] + s.a[0][1]) % M);
	}
	return 0;
}