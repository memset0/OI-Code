#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
int main()
{
	int n, k;
	char str[maxn];
	scanf("%d %d\n%s", str);
	for (int i = 0; i < strlen(str); i++)
		a[i + 1] = str[i] - '0';
	bool flag = 0;
	for (int i = )
	return 0;
}













/*#include <bits/stdc++.h>
using namespace std;
const int maxn = 50, maxk = 10;
long long f[maxn][maxk];
int n, m, a[maxn];
char str[maxn];
int main()
{
	scanf("%d%d%s", &n, &m, str+1);
	for (int i = 1; i <= n; i++)
		a[i] = str[i] - '0';
	f[0][0] = 1;
	for (int k = 1; k <= m; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			f[i][k] = max(f[i-1][k], f[i][k-1] * a[i]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%d" , f[i][j]);
		puts("");
	}
	printf("%d", f[n][m]);
	return 0;
}*/
