#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
	//var
int a[1015];
int b[1015];
	//function
int zs(int);
int wms(int);
int sxhs(int);
int bls(int);	
	//main
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (zs(a[i]) || wms(a[i]) || sxhs(a[i]) || bls(a[i]))
		{
			b[a[i]] = 1;
		}
	}
	int tk = 0;
	for (int i = 1; i <= 1001; i++)
	{
		if(b[i] > 0) 
			{
				tk++;
			}
	}
	int tkk = 0;
	for (int i = 1; i <= 1001; i++)
	{
		if(b[i] > 0) 
			{
				tkk++;
				printf("%d", i);
				if (tk != tkk) printf(" ");
			}
	}
	//putchar('*');
	puts("");
	return 0;
}
	//function
int zs(int k)
{
	bool b = true;
	if (k == 0 || k == 1)
	{
		return 0;
	}
	for (int i = 2; i * i <= k; i++)
	{
		if (k % i == 0) 
		{
			b = false;
		}
	}
	if (b == true) return 1;
	else return 0;
}
int wms(int m)
{
	if (m == 6 || m == 28 || m == 496 || m == 8128) return 1;
	else return 0;
}
int sxhs(int m)
{
	int s = 0;
	int k = m;
	int t;
	while (k > 0)
	{
		t = k % 10;
		k = k / 10;
		s += t * t * t;
	}
	if (m == s) return 1;
	else return 0;
}
int bls(int m)
{
	if (m < 100) return 0;
	int k = m;
	int a = k % 10;
	int b = k / 10 % 10;
	if (a == b) return 0;
	k /= 100;
	while (k > 0)
	{
		if (a != k % 10) return 0;
		if (k / 10 % 10 != 0)
			if (b != k / 10 % 10) return 0;
		k /= 100;
	}
	return 1;
}
