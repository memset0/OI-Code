#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n;
vector < int > q;
vector < int > v[maxn];
int LIS() {
	
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]), v[b[i]].push_back(i);
	for (int i = 1; i <= n; i++) {
		if (v[a[i]].size()) {
			for (int j = 0; j < v[a[i]].size(); j++) {
				q.push_back(v[a[i]][j]);
			}
		}
	}
	LIS();
	return 0;
}
