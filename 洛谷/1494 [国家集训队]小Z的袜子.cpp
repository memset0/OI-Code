#include <bits/stdc++.h>
#define read() Read::reader()
using namespace std;
const int maxn = 50010;
namespace Read {
	char c; bool m; int x;
	int reader() {
		c = getchar(), m = x = 0;
		while (!isdigit(c) && c != '-') c = getchar();
	}
}
int n, m, a[maxn];
struct Request {
	int l, r;
} req[maxn];
int main() {
	n = read(), m = read();
	return 0;
}
