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

int n, i;
double ans, cost;

int main() {
	
	n = read();
	cost = 420000.0 / n;
	while (n--) {
		ans += cost, i++;
		cost *= ((i << 1) - 1) / (double) (i << 1);
	}
	printf("%.2lf\n", ans);

	return 0;
}
