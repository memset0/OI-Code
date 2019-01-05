#include <bits/stdc++.h>
using namespace std;
int read();

const int maxn = 1000010;
int n, m = 0, f[maxn][2];
char s[maxn];
struct Node {
	int a;
	bool c;
} a[maxn];
int main() {
	scanf("%d%s", &n, s + 1);
	
	a[m = 1].a = 1;
	if (s[1] == 'A') a[1].c = 0;
	else a[1].c = 1;
	for (int i = 2; i <= n; i++) {
		if (s[i] == s[i - 1]) {
			if (a[m].a == 1) a[m].a++;
		}
		else {
			a[++m].a = 1;
			if (s[i] == 'A') a[m].c = 0;
			else a[m].c = 1;
		}
	}
	f[1][a[1].c] = 0;
	f[1][a[1].c ^ 1] = 1;
	for (int i = 2; i <= m; i++) {
		f[i][a[i].c] = min(f[i - 1][a[i].c ^ 1] + 1, f[i - 1][a[i].c]);
		f[i][a[i].c ^ 1] = min(f[i - 1][a[i].c] + 1, f[i - 1][a[i].c ^ 1] + a[i].a);
	}
	
//	for (int i = 1; i <= m; i++)
//		printf("%d %d\n", f[i][0], f[i][1]);
	printf("%d\n", f[m][0]);
	return 0;
}


int ret, mrk; char chr;
int read() {
	chr = getchar(), ret = 0, mrk = 1;
	while (!isdigit(chr) && chr != '-') chr = getchar();
	if (chr == '-') mrk = -1, chr = getchar();
	while (isdigit(chr)) ret = ret * 10 + chr - '0', chr = getchar();
	return ret * mrk;
	return 0;
}