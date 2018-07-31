#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 50015;
struct cow
{
	int s, v;
};
cow a[N];
int n, l, r, ans;
void qsort(int l, int r)
{
	if (l >= r) return;
	cow key = a[l];
	int i = l, j = r;
	while (i < j)
	{
		while (i < j && a[j].v > key.v) j--;
		if (i < j) a[i++] = a[j];
		while (i < j && a[j].v < key.v) i++;
		if (i < j) a[j--] = a[i];
	}
	a[i] = key;
	qsort(l, i - 1);
	qsort(i + 1, r);
}
int getmid(int l, int r)
{
	int s = a[l].v + a[r].v;
	if (s % 2 == 0) return (s / 2);
	else return -1;
}
int getl(int i)
{
	if (i == 0) return 1;
	return ((a[i].v + a[i-1].v) / 2 + 1);
}
int getr(int i)
{
	if (i == n) return 1000000000;
	int s = a[i].v + a[i+1].v;
	if (s % 2 == 0) return s / 2 + 1;
	else return s / 2;
}
void slove()
{
	for (int i = 1; i <= n; i++)
		if (a[i].s)
		{
			int x = getl(i);
			int y = getr(i);
			if (x < l) x = l;
			if (y > r) y = r;
			if (x <= y) ans += (y - x + 1);
		}
	for (int i = 1; i <= (n - 1); i++)
		if (a[i].s || a[i+1].s)
		{
			int mid = getmid(i, i + 1);
			if (mid != -1 && mid >= l && mid <= r) ans += 1;
		}
}
int main()
{ 
	scanf("%d%d%d", &n, &l, &r);
	char str[10];
	for (int i = 1; i <= n; i++)
	{
		scanf("%s%d", str, &a[i].v);
		if (str[0] == 'S') a[i].s = 1;
		else a[i].s = 0;
	}
	qsort(1, n);
	ans = 0;
	slove();
	printf("%d", ans);
	return 0;
}
