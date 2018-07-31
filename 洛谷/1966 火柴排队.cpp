#include <bits/stdc++.h>
#define isnum(x) ('0' <= x && x <= '9')
#define read(x) do { \
	x = 0, r::c = getchar(), r::m = 1; \
	while (!isnum(r::c) && r::c != '-') r::c = getchar(); \
	if (r::c == '-') r::c = getchar(), r::m = -1; \
	while (isnum(r::c)) x = x * 10 + r::c - '0', r::c = getchar(); \
	x *= r::m; \
} while (false) 
namespace r { char c; int m; }
using namespace std;

#define sqr(x) ( (x) * (x) )
const int maxn = 1000010;
int n, a[maxn], b[maxn];

int main() {
	
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++)
		read(b[i]);
	
	for (int i = 1; i <= n; i+)
	
	return 0;
}
