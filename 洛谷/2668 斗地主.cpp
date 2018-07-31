#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
int t, n, k, a[maxn], b[maxn], c[maxn];
int main() {
	scanf("%d%d", &t, &n);
	while(t--) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &a[i], &k);
			if (a[i] == 0) a[i] = 14;
			else a[i] = (a[i] + 10) % 13 + 1;
		}
		for (int i = 1; i <= n; i++)
			b[a[i]]++;
//		for (int i = 1; i <= 14; i++)
//			cout << b[i];
//		cout << endl; 
		for (int i = 1; i <= 14 - 6; i++)
			if (b[i] && b[i + 1] && b[i + 2] && b[i + 3] && b[i + 4]) {
				for (int j = i; j <= 14; j++)
					if (b[j]) b[j] -= 1;
					else break;
				ans++;
			}
		for (int i = 1; i <= 14 - 4; i++)
			if (b[i] >= 3 && b[i + 1] >= 3 && b[i + 2] >= 3) {
				for (int j = i; j <= 14; j++)
					if (b[j] >= 3) b[j] -= 3;
					else break;
				ans++;
			}
		for (int i = 1; i <= 14 - 4; i++)
			if (b[i] >= 2 && b[i + 1] >= 2 && b[i + 2] >= 2) {
				for (int j = i; j <= 14; j++)
					if (b[j] >= 2) b[j] -= 2;
					else break;
				ans++;
			}
//		for (int i = 1; i <= 14; i++)
//			cout << b[i];
//		cout << endl; 
//		cout << ans << endl;
		for (int i = 1; i <= 14; i++)
			c[b[i]]++;
//		for (int i = 1; i <= 5; i++)
//			cout << c[i];
//		cout << endl;
		while (c[4] >= 1 && c[2] >= 2) {
			c[4] -= 1;
			c[2] -= 2;
			ans ++;
		}
		while (c[4] >= 1 && c[1] >= 2) {
			c[4] -= 1;
			c[1] -= 2;
			ans ++;
		}
		while (c[3] && c[2]) {
			c[3] -= 1;
			c[2] -= 1;
			ans ++;
		}
		while (c[3] && c[1]) {
			c[3] -= 1;
			c[2] -= 1;
			ans ++;
		}
//		cout << ans << endl;
//		for (int i = 1; i <= 5; i++)
//			cout << c[i];
//		cout << endl;
		for (int i = 1; i <= 10; i++) 
			ans += c[i];
		cout << ans << endl;
	}
	return 0;
}
