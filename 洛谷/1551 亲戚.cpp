#include <bits/stdc++.h>
using namespace std;
int n, m, p, a, b, f[10010];
int find(int x) {if (f[x] != x) f[x] = find(f[x]); return f[x];}
int main()
{
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++) scanf("%d%d", &a, &b), f[find(b)] = find(a);
	for (int i = 1; i <= p; i++)
	{
		scanf("%d%d", &a, &b);
		if (find(a) == find(b)) printf("Yes\n"); else printf("No\n");
	}
}
