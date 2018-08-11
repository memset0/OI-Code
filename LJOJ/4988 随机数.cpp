// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define ull unsigned long long
#define y1 this_is_not_y1
#define y2 this_is_not_y2
#define sqr ((x)*(x))
#define lowbit(x) ((x)&(-x))
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 2510;
const ll Mod = 998244353;
int n, m;
bool flag, has_ans = true;
map < int, int > Map;
map < int, int > ::iterator it;
ll t, x, y, sum;
ll a[maxn][maxn], f[maxn][maxn], ans[maxn];

ll inv(ll x) {
	if (x == 0 || x == 1) return 1;
	return (Mod - Mod / x) * inv(Mod % x) % Mod;
}

void merge(ll *a, ll *b, int l) {
	ll t = (Mod - a[l]) % Mod * inv(b[l]) % Mod;
//	printf("=== Merge %d === \n", l);
//	for (int i = 0; i <= n + 1; i++)
//		printf("%d ", a[i]);
//	puts("");
//	for (int i = 0; i <= n + 1; i++)
//		printf("%d ", b[i]);
//	puts("");
	for (int i = l; i <= n + 1; i++)
		a[i] = (a[i] + b[i] * t) % Mod;
//	for (int i = 0; i <= n + 1; i++)
//		printf("%d ", a[i]);
//	puts("");
//	puts("===         ===");
}

bool check(int x, int y) {
	it = Map.find(x);
	if (it == Map.end()) return true;
	else if ((it -> second) == y) return false;
	else {
		has_ans = false;
		return false;
	}
}

int main() {
//	freopen("random.in", "r", stdin);
//	freopen("random.out", "w", stdout);
	
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		x = read(), y = read();
		t = 1;
		if (!check(x, y)) {
			i--, m--;
			if (!has_ans) {
				puts("-1");
				return 0;
			}
		} else {
			Map[x] = y;
			for (int j = 0; j <= n; j++)
				a[i][j] = f[i][j] = t, t = (t * x) % Mod;
			a[i][n + 1] = f[i][n + 1] = y;
		}
	}
	
//	for (int i = 1; i <= m; i++) {
//		for (int j = 0; j <= n + 1; j++)
//			printf("%lld ", f[i][j]);
//		puts("");
//	}
	for (int i = 0; i < n; i++)
		for (int j = m; j > i + 1; j--)
			merge(f[j], f[j - 1], i);
//	for (int i = 1; i <= m; i++) {
//		for (int j = 0; j <= n + 1; j++)
//			printf("%lld ", f[i][j]);
//		puts("");
//	}
//	for (int i = n + 1; i >= 1; i++)
//		ans[i - 1] = inv(f[i][i - 1]) * f[i][n + 1] % Mod;
	
	
	for (int i = n; i >= 0; i--) {
		if (m < i + 1) ans[i] = 1;
		else {
			for (int j = i + 1; j <= n; j++)
				f[i + 1][n + 1] = (f[i + 1][n + 1] - (f[i + 1][j] * ans[j]) % Mod + Mod) % Mod;
			ans[i] = inv(f[i + 1][i]) * f[i + 1][n + 1] % Mod;
		}
	}
	
	flag = 1;
	for (int i = 1; i <= m; i++) {
		sum = 0;
		for (int j = 0; j <= n; j++)
			sum = (sum + a[i][j] * ans[j]) % Mod;
		if (sum != a[i][n + 1]) {
			flag = 0;
			break;
		}
	}	
	
//	puts("==== ANSWER ====");
//	for (int i = 0; i <= n; i++)
//		printf("%d ", ans[i]);
//	putchar('\n');
	if (flag){
		for (int i = 0; i <= n; i++)
			printf("%d ", ans[i]);
		putchar('\n');
	} else {
		printf("-1\n");
	}
	
	return 0;
}
