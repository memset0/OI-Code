#include <bits/stdc++.h>
using namespace std;
bool get_enter = 0;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') {
		c = getchar();
	}
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	cout << c << ']';
	// if (c == ' ') c = getchar();
	if (c == '\r' || c == '\n') get_enter = 1;
	cout << x << endl;
	if (m) return -x; else return x;
}
const int maxn = 110, maxm = 5010, inf = 1e9;
int n, m, ans, yours, val[maxn], lnk[maxn][maxn], cst[maxn];
int main() {
	freopen("INPUT", "r", stdin);
	m = read(), n = read();
	for (int i = 1; i <= m; i++) {
		val[i] = read();
		get_enter = 0;
		while (!get_enter)
			cout << '!',
			lnk[i][++lnk[i][0]] = read();
	}
	for (int i = 1; i <= n; i++)
		cst[i] = read();
	fclose(stdin);
	freopen("2762.out", "r", stdin);
	get_enter = 0;
	while (!get_enter)
		ans += val[read()];
	get_enter = 0;
	while (!get_enter)
		ans -= val[read()];
	cout << "!!!";
	if (ans != (yours = read())) printf("Wrong, the answer is %d but yours is %d\n", yours, ans);
	else printf("Currect!\n");
	fclose(stdin);
	return 0;
}