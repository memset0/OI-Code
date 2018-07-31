// === TODO ===
// 1. 特殊数据#1 PASS
// 2. 特殊数据#2 PASS
// 3. 特殊数据#3 PASS
// 4. 最大数据 UNDO 
// 5. 题目理解问题 PASS

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
const int maxm = 110;
int fi[maxn], nxt[maxn];
char s[maxn], t[maxm], f[maxn];
bool usd[maxn];
int n, m, l = 0;

int main() {
//	freopen("censor.in", "r", stdin);
//	freopen("censor.out", "w", stdout);
	
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1), m = strlen(t + 1);
//	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++)
		if (s[i] == t[1]) 
			fi[++fi[0]] = i;
	for (int i = 1; i < n; i++)
		nxt[i] = i + 1;
	nxt[n] = -1;
	
	bool fnd;
	for (int i = 1; i <= n; i++) {
		f[++l] = s[i];
		if (l >= m) {
			fnd = true;
			for (int i = 1; i <= m; i++)
				if (f[i + l - m] != t[i]) {
					fnd = false;
					break;
				}
			if (fnd) {
				l -= m;
			}
		}
	}
	
	for (int i = 1; i <= l; i++)
		printf("%c", f[i]);
	puts("");
	return 0;
}
