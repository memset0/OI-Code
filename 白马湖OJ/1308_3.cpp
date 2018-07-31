#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const long N = 1000015;
bool mark[1000015];
int boo[2015];
int sum[2015][2015]; 
int ans = 0, ans_l, ans_r, n;
int find_prime(long n)
{
	mark[1] = 1; mark[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (mark[i] == 1) continue;
		else for (int j = 2; j * i <= n; j++) mark[j * i] = 1;
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &boo[i]);
	find_prime(N);
	for (int i = 1; i <= n; i++) 
	{
		sum[i][i] = boo[i];
		for (int j = i + 1; j <= n ;j++)
		{
				sum[i][j] = sum[i][j - 1] + boo[j];
				if (mark[sum[i][j]] == 1) continue;
				if (sum[i][j] > ans) {ans = sum[i][j]; ans_l = i; ans_r = j;}
		}
	}
	printf("%d %d %d", ans_l, ans_r, ans);
	return 0;
}
