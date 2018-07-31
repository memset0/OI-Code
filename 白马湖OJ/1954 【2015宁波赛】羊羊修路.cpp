//并查集 
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
const int maxm = 10010;
struct Road {
	int a, b, l;
}a[maxm];
int n, m, x, f[maxn], ans = 0;
bool my_sort(Road a, Road b) {
	return a.l < b.l;
}
int find_father(int i) {
	if (f[i] == i) return i;
	else {
		x = find_father(f[i]);
		f[i] = x;
		return x;
	} 
}
int main()
{
	//输入 
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].l);
	//并查集初始化 
	for (int i = 1; i <= n; i++)
		f[i] = i;	
	//排序，然后优先选择最短的道路
	sort(a+1, a+m+1, my_sort);
	int fa, fb;
	for (int i = 1; i <= m; i++)
	{
		fa = find_father(a[i].a);
		fb = find_father(a[i].b);
		if (fa != fb)
		{
			ans = a[i].l;
			f[fa] = fb;
		}
	}
	//输出 
	printf("%d", ans);
	return 0;
}
