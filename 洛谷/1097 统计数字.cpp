#include <bits/stdc++.h>
#define isnum(x) ('0' <= x && x <= '9')
#define read(x) do { \
	chr = getchar(), mrk = 1, x = 0; \
	while (!isnum(chr) && chr != '-') chr = getchar(); \
	if (chr == '-') mrk = -1, chr = getchar(); \
	while (isnum(chr)) x = x * 10 + chr - '0', chr = getchar(); \
	x *= mrk; \
} while(0);
char chr; int mrk;
using namespace std;
int n, a, i;
map < int, int > mp;
map < int, int > ::iterator it;
int main() {
	read(n);
	for (i = 1; i <= n; ++i) {
		read(a);
		mp[a] ++;
	}
	for (it = mp.begin(); it != mp.end(); ++it)
		printf("%d %d\n", it -> first, it -> second);
	return 0;
}
