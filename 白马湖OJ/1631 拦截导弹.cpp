#include <bits/stdc++.h>
#define read(n) scanf("%d", &n)
using namespace std;
const int maxn = 400;
int n = 0, t, s, a[maxn], f[maxn], b[maxn];
int main()
{
	freopen("data.txt", "r", stdin);
	//输入 
	while (scanf("%d", &t) != EOF) a[++n] = t;
	//最长不上升子序列 
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{ 
		f[i] = 1;
		for (int j = 1; j < i; j++)
			if (a[i] <= a[j])
				f[i] = max(f[i], f[j] + 1);
	}
	int maxx = -1;
	for (int i = 1; i <= n; i++)
		maxx = max(maxx, f[i]);
	printf("%d\n", maxx);
	//最长上升子序列
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{ 
		f[i] = 1;
		for (int j = 1; j < i; j++)
			if (a[i] > a[j])
				f[i] = max(f[i], f[j] + 1);
	}
	maxx = -1;
	for (int i = 1; i <= n; i++)
		maxx = max(maxx, f[i]);
	printf("%d\n", maxx);
	return 0;
}
