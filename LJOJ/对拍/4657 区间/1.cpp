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

const int maxn = 20000010;
int n, k;
ll p, A, B, C, D;
ll ans, a[maxn], b[maxn];

namespace S1 {
	
	int main() {
		
		a[1] = A;
		for (int i = 2; i <= n; i++)
			a[i] = (a[i - 1] * B + C) % D;
		
		for (int i = 1; i <= n - k + 1; i++) {
			b[i] = 1;
			for (int j = i; j < i + k; j++)
				b[i] = b[i] * a[j] % p;
			ans ^= b[i];
		}
		
		for (int i = 1; i <= n - k + 1; i++)
			printf("%lld\n", b[i]);
		printf("%lld\n", ans);
		
		return 0;
	}
	
}

namespace S2 {
	
	int u, mi2[20], ned[20], mx;
	ll f[200010][20];
	
	int main() {
		
		a[1] = A;
		for (int i = 2; i <= n; i++)
			a[i] = (a[i - 1] * B + C) % D;
		for (int i = 1; i <= n; i++)
			a[i] %= p, f[i][0] = a[i];
		
		mi2[0] = 1;
		if (k & 1) {
			mx = 0;
			ned[0] = 1;
		}
		for (int i = 1; i < 20; i++) {
			mi2[i] = mi2[i - 1] << 1;
			if (mi2[i] & k) {
				mx = i;
				ned[i] = 1;
			}
		}
			
		for (int i = 1; i <= mx; i++)
			for (int j = 1; j <= n; j++)
				if (j + mi2[i] - 1 <= n)
					f[j][i] = f[j][i - 1] * f[j + mi2[i - 1]][i - 1] % p;
		
//		for (int j = 0; j <= mx; j++)
//			cout << ned[j] << " ";
//		cout << endl;

//		for (int i = 1; i <= n; i++) {
//			for (int j = 0; j < 7; j++)
//				printf("%lld ", f[i][j]);
//			puts("");
//		}
	
		for (int i = 1; i <= n - k + 1; i++) {
			u = i, b[i] = 1;
			for (int j = 0; j <= mx; j++)
				if (ned[j]) {
					b[i] = b[i] * f[u][j] % p;
					u += mi2[j];
//					printf("%lld(%d) ", f[u][j], u);
				}
//			cout << b[i] << endl;
			ans ^= b[i];
		}
		
		printf("%lld\n", ans);
		
		return 0;
	}
	
}

namespace S3 {
	
	ll inv(ll x) {
		if (x == 0 || x == 1) return 1;
		return (p - p / x) * inv(p % x) % p;
	}
	
	int main() {
		
		a[1] = A;
		for (int i = 2; i <= n; i++)
			a[i] = (a[i - 1] * B + C) % D;
		for (int i = 1; i <= n; i++)
			a[i] %= p;
		
		b[1] = 1;
		for (int i = 1; i <= k; i++) 
			b[1] = b[1] * a[i] % p;
		for (int i = 2; i <= n - k + 1; i++) {
			b[i] = b[i - 1] * inv(a[i - 1]) % p * a[i + k - 1] % p;
//			printf("%lld => %lld %lld => %lld\n", b[i - 1], a[i - 1], a[i + k - 1], b[i]);
		}
//		for (int i = 1; i <= k; i++)
//			printf("%lld\n", a[i]);
//		for (int i = 1; i <= n - k + 1; i++)
//			printf("%lld\n", b[i]);
		for (int i = 1; i <= n - k + 1; i++)
			ans ^= b[i];
		printf("%lld\n", ans);
		
		return 0;
	}
	
}

int main() {
//	freopen("range.in", "r", stdin);
//	freopen("range.out", "w", stdout);
	
	n = read(), k = read(), p = read();
	A = read(), B = read(), C = read(), D = read();
	
	if ((n <= 1000) || (n <= 2000000 && (n - k) <= 10)) {
//		printf("choose S1\n");
		return S1::main();
	} else if (n <= 200000) {
//		printf("choose S2\n");
		return S2::main();
	} else {
//		printf("choose S3\n");
		return S3::main();
	}
	
	return 0;
}

