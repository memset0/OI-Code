#include <bits/stdc++.h> 
using namespace std; 
const int maxn = 11;
int n, a[maxn];
char str[20], t[maxn][20];
map < string, int > mp;
map < string, int >::iterator it;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%s", t[i]);
		mp[t[i]] = i;
	}
	int u, s, k;
	for (int i = 1; i <= n; i++) {
		scanf("%s%d%d", str, &s, &k);
		u = mp[str];
		if (k > 0) a[u] -= (s / k) * k;
		for (int j = 1; j <= k; j++) {
			scanf("%s", str);
			a[mp[str]] += s / k;
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%s %d\n", t[i], a[i]);
	return 0;
}
