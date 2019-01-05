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

const int maxn = 110;
int n;
char x[maxn], y[maxn], ans[maxn];

int main() {

	n = read();
	scanf("%s%s", x + 1, y + 1);

	for (int i = 1; i <= n; i++) {
		if (x[i] > y[i]) ans[i] = y[i];
		else if (x[i] == y[i]) ans[i] = x[i] + 1;
		else if (x[i] < y[i]) {
			printf("-1");
			return 0;
		}
	}
	printf("%s", ans + 1);

	return 0;
}
