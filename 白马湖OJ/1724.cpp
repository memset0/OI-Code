#include <bits/stdc++.h>
using namespace std;
int a[25 + 5], b[15 + 5][4 + 2];
int bin[100]; 
int f1(int n) //计算2的n次方
{
	int ans = 1;
	for (int i = 1; i <= n; i++)
		ans *= 2;
	return ans;
} 
void f2(int n) //十进制转二进制 数据存储在Bin[]中 
{
	bin[0] = 0;
	while (n > 0)
	{
		bin[++bin[0]] = n % 2;
		n = n / 2;
	}
	return;
}
int f3() //求bin中所有数的和
{
	int sum = 0;
	for (int i = 1; i <= bin[0]; i++)
		sum += bin[i];
	return sum;
} 
int main()
{
	int n, m;
	bool bo;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d%d", &b[i][1], &b[i][2], &b[i][3], &b[i][4]);
	int p, ans_p = (m + 1), ans_n;
	int k[30];
	for (int _i = 1; _i <= (f1(m) - 1); _i++)
	{
		f2(_i); p = f3();
		if (p > ans_p) continue;
		for (int i = 1; i <= bin[0]; i++)
			k[i] = 0;
		for (int i = 1; i <= bin[0]; i++)
		{
			if (bin[i] == 1)
			{
				for (int j = 1; j <= n; j++)
					k[j] += b[i][j];
			}
		}
		bo = true;
		for (int i = 1; i <= bin[0]; i++)
			if (k[i] < a[i]) 
			{
				bo = false;
				break;
			}
		if (bo)
		{
			ans_p = p;
			ans_n = _i;
		}
	}
	printf("%d ", ans_p);
	f2(ans_n);
	for (int i = 1; i <= bin[0]; i++)
	{
		if (bin[i] == 1)
		{
			printf("%d ", i);
		}		
	}
	return 0;
} 
 
