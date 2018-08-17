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

#define sqr(x) ((x) * (x))
const int maxn = 1510;
int n;
int node {
	int x, y;
} a[maxn];
int edge {
	int x, y, len;
	bool operator < (const edge &b) const {
		if (x != b.x) return x < b.x;
		if (y != b.y) return y < b.y;
		return len < b.len;
	}
} e[maxn * maxn];

int main() {
	freopen("INPUT", "r", stdin);
	
	n = read();
	for (int i = 1; i <= n; i++)
		a[i].x = read(), a[i].y = read();
		
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			e[++m] = {
				(a[i].x + a[j].x) >> 1,
				(a[i].y + a[j].y) >> 1,
				sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y)
			}
	sort(e + 1, e + m + 1);
	
	return 0;
}
