#include <bits/stdc++.h>
using namespace std;

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 60;
const int maxm = 50000;
int n, u, cnt, tmp, f[maxn], a[maxm];
bool flag, t[maxm];

int main() {

	for (int i = 1; i * i < maxm; ++i)
		t[i * i] = 1;

	n = read();
	for (u = 1; 1; flag = 0, ++u) {
		// cout << u << endl;
		for (int i = 1; i <= cnt; i++)
			if (t[u + f[i]]) {
				flag = 1;
				a[u] = i;
				f[i] = u;
				break;
			}
		if (!flag) {
			if (++cnt <= n) {
				a[u] = cnt;
				f[cnt] = u;
			} else {
				break;
			}
		}
	}


	// for (int j = 1; j <= u; j++)
	// 	cout << a[j] << " ";
	// cout << endl;
	printf("%d\n", --u);
	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j <= u; j++)
			if (a[j] == i) {
				printf("%d ", j);
			}
		putchar('\n');
	}

	return 0;
}