#include <bits/stdc++.h>
#define isNum(c) ('0'<=c&&c<='9')
using namespace std;
const int maxn = 210;
int n, m, s, ans = -1, a, b[maxn];
int read(void) {
	char c = getchar();
	while (!isNum(c)) c = getchar();
	int ret = 0;
	while (isNum(c)) {
		ret = ret * 10 + c - '0';
		c = getchar();
	}
	return ret;
}
bool check(int x) {
	int cnt = 0;
	for (int i = 1; i <= s;)
		if (b[i]) {
			i += x;
		} else {
			i++;
		}
	if (cnt * x < ans || ans == -1) ans = cnt * x;
	return true;
}
int main() {
	cin >> m >> s >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a), b[a] = 1;
	int l = 1, r = s, mid;
	while (l + 3 < r) {
		mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	for (int i = l; i <= r; i++)
		if (check(i)) {
			for (int j = i; j <= s; j++)
				check(j);
			break;
		}
	cout << ans << endl;
	return 0;
}
