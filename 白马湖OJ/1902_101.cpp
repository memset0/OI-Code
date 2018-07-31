#include <bits/stdc++.h>
#define min lll
#define max rrr 
using namespace std;
const int maxn = 50010;
int ans = -1;
int a[maxn], s[maxn], min[10], max[10];
int main()
{
	int n;
	scanf("%d", &n);
	s[0] = 0;
	for (int i = 1; i <= n; i++)
	{ 
		scanf("%d", &a[i]);
		a[i] %= 7;
		s[i] = (s[i-1] + a[i]) % 7;
	}
	for (int i = 1; i <= n; i++)
		if (!min[s[i]]) min[s[i]] = i;
	for (int i = n; i >= 1; i--)
		if (!max[s[i]]) max[s[i]] = i;
	for (int i = 0; i < 7; i++)
		if (max[i] - min[i] >= ans) ans = max[i] - min[i];
	printf("%d", ans);
	return 0;
}
