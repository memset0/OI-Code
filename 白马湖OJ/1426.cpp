#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int n, m, sum, a[210], b[310], ans;
void DFS(int k)
{
	//printf("%d\n", ans);
	if (abs(sum - m) < abs(ans - m))
		ans = sum;
	for (int i = k; i <= n; i++)
		if (a[i] > 0)
		{
			sum += a[i];
			a[i] *= -1;
			if ((abs(sum - m) < abs(ans - m)) || sum < m) DFS(i+1);
			a[i] *= -1;
			sum -= a[i];
		}
}
int main()
{
	//ÊäÈë
	scanf("%d%d", &n, &m);
	int t;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &t);
		b[t]++;
	}
	a[0] = 0;
	for (int i = 300; i >= 1; i--)
		while (b[i]) a[++a[0]] = i, b[i] -= 1;
	ans = m * 10;
		
	//DFS
	sum = 0;
	DFS(1);
	
	//Êä³ö
	printf("%d", ans); 
	
	//½áÊø 
	return 0;
}
 
