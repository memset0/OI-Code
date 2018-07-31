#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int n, m, k = 0;
char str[100];
map < string, int > mp;
vector < int > vt[maxn];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m;
		for (int j = 1; j <= m; j++) {
			scanf("%s", str);
			if(mp.count(str)) {
				if (i != vt[mp[str]].back()) vt[mp[str]].push_back(i);
			} else {
				mp[str] = ++k;
				vt[k].push_back(i);
			}
		}
	}
	cin >> m;
	int t;
	for (int i = 1; i <= m; i++) {
		scanf("%s", str);
		if (mp.count(str)) t = mp[str];
		else t = 0;
		for (int j = 0; j < vt[t].size(); j++)
			printf("%d ", vt[t][j]);
		puts("");
	}
	return 0;
}
