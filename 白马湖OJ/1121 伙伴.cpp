//原来写的一份代码，好像能AC 
#include <iostream>
#include <cstdio>
using namespace std;
long long ka[1000] = {0}, kb[1000] = {0};
int main()
{
	long long n, m, s = 0;
	scanf("%lld%lld", &n, &m);
	long long temp;
	for (int i=1; i<=n; i++)
	{ scanf("%lld", &temp); ka[temp]++; }
	for (int i=1; i<=m; i++)
	{ scanf("%lld", &temp); kb[temp]++; }
	for (int i=1; i<=101; i++)
	{
		for (int j=1; j<=101; j++)
		{
			long long t = i + j;
			s += ka[i] * kb[j] * kb[t] * t;
			//if ((ka[i]) && (kb[j]) && (kb[t]))printf("i=%d ka[i]=%d j=%d kb[j]=%d t=%d kb[t]=%d \n", i, ka[i], j, kb[j], t, kb[t]);
		}
	}
	printf("%lld", s);
	return 0;
}






/*#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int maxm = 110;
int n, m, t, a[maxm], b[maxm];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &t), a[t]++;
	for (int i = 1; i <= m; i++)
		scanf("%d", &t), b[t]++;
	long long ans = 0;
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			ans += a[i] * b[j] * b[i+j] * (i + j);
	cout << ans << endl;
	return 0;
}*/
