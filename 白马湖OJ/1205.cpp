#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int zs(int);
int dz(int);
int main()
{
	int n, m;
	//printf("%d\n", dz(123456));
	scanf("%d%d", &n, &m);
	int k = 0;
	for (int i = n; i <= m; i++)
	{
		if (zs(i) && zs(dz(i)))
		{
			k++;
		}
	}
	if (k == 0)
	{
		printf("No\n");
		return 0;
	}
	int kk = 0;
	for (int i = n; i <= m; i++)
	{
		if (zs(i) && zs(dz(i)))
		{
			kk++;
			printf("%d", i);
			if (k != kk) printf(",");
			else puts("");
		} 
	}
	return 0;
}
int zs(int n)
{
    int i;
    if(n > 2 && !(n & 1) || n < 2)	return false;
    for(i = 3; i * i <= n; i += 2)
        if(!(n % i)) return 0;
    return 1;
}
int dz(int n)
{
	int a[20] = {0};
	int k = 0;
	int t = n;
	while (t > 0)
	{
		a[++k] = t % 10;
		t = t / 10;
	}
	t = 0;
	for (int i = 1; i <= k; i++)
	{
		t = t * 10 + a[i];
	}
	return t;
}

