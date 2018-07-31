#include <bits/stdc++.h>
#define isnum(x) ('0' <= x && x <= '9')
#define gc() getchar()
#define read(x) { \
	x = 0, r::c = gc(), r::m = 1; \
	while (!isnum(r::c) && r::c != '-') r::c = gc(); \
	if (r::c == '-') r::m = -1, r::c = gc(); \
	while (isnum(r::c)) x = x * 10 + r::c - '0', r::c = gc(); \
	x *= r::m; \
}
using namespace std;
namespace r {
	char c;
	int m;
}
long long n, m, k, x;

int main() {
//	freopen("1.txt", "r", stdin);
	
	read(n); read(m); read(k); read(x);

	long long ans = 1, base = 10;
	while (k) {
		if (k & 1) ans = ans * base % n;
		base = base * base % n;
		k >>= 1;
	}
	k = ans % n;
//	cout << k << endl; 
	
	for (long long i = 1; i <= k; i++)
		x = (x + m) % n;
	printf("%d\n", x);
	
	return 0;
}
