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

int n, x, op;
std::priority_queue < int, std::vector < int >, std::greater < int > > q;

void main() {
	for (read(n); n--; ) {
		read(op); switch (op) {
			case 1: read(x), q.push(x); break;
			case 2: print(q.top()), putc('\n'); break;
			case 3: q.pop(); break;
		}
	}
}

} int main() { return ringo::main(), 0; }