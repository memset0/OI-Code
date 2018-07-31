#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
int a[100];
bool f(int k)
{
	if (k <= 0) return false;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == k) return true;
		else if (f(a[i] - k) == true) return true;
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a[i]);
	}
	return 0;
}
