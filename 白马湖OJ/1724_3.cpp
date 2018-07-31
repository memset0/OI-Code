#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
struct Feed{
	int n, i, s;
	int f[30], b[20];
}q[100000];
Feed u, v, ans;
int n, m;
int a[30], b[20][5];
bool bo;
int main()
{
	//输入 
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d%d", &b[i][1], &b[i][2], &b[i][3], &b[i][4]);
	//DFS初始化 
	q[1].n = 0; q[1].i = 0; q[1].s = 0;
	for (int i = 1; i <= n; i++)
	{
		q[1].f[i] = 0;
		q[1].b[i] = 0;
	}
	ans.n = n + 100;
	int i = 1;
	//DFS 
	while (i > 0)
	{
		u = q[i];
		i--;
		if (u.i > m) continue;
		if (u.n > ans.n) continue;
		if (u.i == m)
		{
			bo = true;
			for (int i = 1; i <= n; i++)
				if (u.f[i] < a[i]) 
				{
					bo = false;
					break; 
				}
			if (bo)
			{
				if (u.n < ans.n) ans = u;
				else if (u.n == ans.n && u.s < ans.s) ans = u;
				//printf("=== u.n=%d u.i=%d u.f[1]=%d u.f[2]=%d u.f[3]=%d u.f[4]=%d u.b[1]=%d u.b[2]=%d u.b[3]=%d u.b[4]=%d ===\n", u.n, u.i, u.f[1], u.f[2], u.f[3], u.f[4], u.b[1], u.b[2], u.b[3], u.b[4]);
			}
			continue;
		}
		//取 
		v = u;
		v.n = u.n + 1;
		v.i = u.i + 1;
		v.b[v.i] = 1;
		for (int i = 1; i <= n; i++)
		{
			v.f[i] += b[v.i][i];
			v.s += b[v.i][i];
		}
		q[++i] = v;
		//不取
		v = u;
		v.i = u.i + 1;
		q[++i] = v;
	}
	//输出
	printf("%d ", ans.n);
	for (int i = 1; i <= m; i++)
	{
		if (ans.b[i] == 1) printf("%d ", i);
	}
} 
