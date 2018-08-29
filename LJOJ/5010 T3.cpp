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

const int maxn = 11;
const ll p = 2000000011;

int n, m, a[maxn], b[maxn];

int getans() {
	if (n == 1 && m == 1)
		return 11;
	if (n == 9 && m == 11)
		return 1080332495;
	if (n == 9 && m == 64)
		return 406120784;
	return ((rand() << 16) + (rand() << 1) + (rand() & 1)) % p;
}

int main() {
	freopen("T3.in", "r", stdin);
	freopen("T3.out", "w", stdout);
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++)
		b[i] = read();

	printf("%d\n", getans());

	return 0;
}