#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int a[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int m;
	scanf("%d", &m);
	m += 30;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	 	if (m >= a[i]) ans++;
	printf("%d", ans);
	return 0;
}
