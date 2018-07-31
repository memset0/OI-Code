#include <bits/stdc++.h>
using namespace std;
long long n, m, a, c, x, g;
struct matrix {
	long long a[2][2];
} k, s;
long long llmul(long long a, long long b) {
	if (b == 0) return 0;
	if (b % 2) {
		long long t = llmul(a, b / 2);
		return ((t + t) % m + a) % m;
	} else {
		long long t = llmul(a, b / 2);
		return (t + t) % m;
	}
//    long long res=0;
//    while(b){
//        if(b&1)res=(res+a)%m;
//        a=(a<<1)%m;
//        b>>=1;
//    }
//    return res;
}
matrix mul(matrix a, matrix b) {
	matrix c = {{{0, 0}, {0, 0}}};
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				c.a[i][j] = (c.a[i][j] + llmul(a.a[i][k], b.a[k][j])) % m;
	return c;
}
matrix mi(matrix x, long long p) {
	if (p == 1) return k;
	if (p % 2) {
		matrix t = mi(x, p / 2);
		return mul(t, mul(t, x));
	} else {
		matrix t = mi(x, p / 2);
		return mul(t, t);
	}
}
void write(matrix a) {
	printf("----\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			printf("%d ", a.a[i][j]);
		puts("");
	}
}
int main() {
	scanf("%lld%lld%lld%lld%lld%lld", &m, &a, &c, &x, &n, &g);
	k = {{{a, 1}, {0, 1}}};
	s = mi(k, n);
//	write(k);
//	write(s);
//	puts("");
	printf("%lld\n", ((llmul(s.a[0][0], x) % m + llmul(s.a[0][1], c) % m) % m) % g);
	return 0;
}
