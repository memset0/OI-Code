#include <bits/stdc++.h>
#define isNum(c) ('0'<=c&&c<='9')
#define M 1000000007
using namespace std;
const int maxn = 110;
const int maxm = 1000010;
int n, m, a[maxn], cnt = 0, ans[maxm];
long long sum;
long long ret; char ch; bool mark;
int read() {
	ch = getchar(), ret = 0;;
	while (!isNum(ch) && ch != '-') ch = getchar();
	if (ch == '-') mark = true, ch = getchar();
	else mark = false;
	while (isNum(ch)) ret = (ret * 10 + ch - '0') % M, ch = getchar();
	if (mark) return -ret;
	else return ret;
}
int cal(int x) {
	sum = 0;
	for (int i = n; i >= 0; i--)
		sum = ((sum * x) + a[i] + M) % M;
	return sum;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= m; i++) {
		if (!cal(i)) ans[++cnt] = i;
		
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++)
		printf("%d\n", ans[i]);
	return 0;
}