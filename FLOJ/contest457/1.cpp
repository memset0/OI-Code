#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}

template < class T >
inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
	print(x), putchar(c);
}

const int N = 1010;
int n;
char a[N];

void main() {
	scanf("%s", a + 1), n = strlen(a + 1);
	for (int i = 1; i <= n; i++) {
		ans += (n - i) * (n - i);
		ans -= 
		for (int j = i + 1; j <= n; j++) {
			
		}
	}
}

} signed main() { return ringo::main(), 0; }