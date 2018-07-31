#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
map < string, int > mp;
int a[maxn][maxn];
int main() {
	cin >> n >> m;
	string str;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		map[str] = i;
	}
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		a[mp[a]][mp[b]] 
			= a[mp[b]][mp[a]] 
			= a[2 * n - mp[a]][2 * n - mp[b]] 
			= a[2 * n - mp[b]][2 * n - mp[a]] 
			= 1;
	}
	n = 2 * n - 1;
	f[1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			f[j]
	}
	return 0;
}
