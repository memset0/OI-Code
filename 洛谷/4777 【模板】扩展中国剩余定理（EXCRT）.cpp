// ==============================
//  author: memset0
//  website: https://memset0.cn
//  date: 2018.08.06 14:15:20
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

ll readll() {
	long long x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 1e5 + 10;
int n;
ll gd, a0, a1, a2, b0, b1, b2;

struct keys {
	ll x, y;
	keys(ll _x = 0, ll _y = 0) {
		x = _x, y = _y;
	}
};

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

keys exgcd(ll a, ll b) {
	if (b == 0) return keys(1, 0);
	keys p = exgcd(b, a % b);
	return keys(p.y, p.x - a / b * p.y);
}

ll inv(ll a, ll b) {
	return a > b ? exgcd(a, b).x % b: exgcd(b, a).y % b;
}

int main() {
	freopen("INPUT", "r", stdin);
	n = read();
	a0 = readll(), b0 = readll();
	for (int i = 2; i <= n; i++) {
		a1 = a0, b1 = b0;
		a2 = readll(), b2 = readll();
		// printf("%lld %lld %lld %lld\n", a1, b1, a2, b2);
		gd = gcd(a1, a2);
		a0 = a1 / gd * a2;
		b0 = ((b2 - b1) / gd * inv(a1 / gd, a2 / gd) % (a2 / gd) * a1 % a0 + b1 + a0) % a0;
		printf("%lld %lld\n", a0, b0);
	}
	printf("%lld\n", b0);
	return 0;
}