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
const int inf = 1e6;
int n = 11, m = n >> 1, a[100];
int main() {
	srand(time(0));
	for (int i = 1; i <= m; i++)
		a[i] = rand() % 2 ? inf : -inf;
	for (int i = m + 1; i <= n; i++)
		a[i] = rand() % 10;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (rand() % 2)
				swap(a[i], a[j]);
	for (int i = 1; i <= n; i++)
		if (a[i] == inf) printf("+");
		else if (a[i] == -inf) printf("-");
		else printf("%d", a[i]);
	puts("");
	return 0;
}
