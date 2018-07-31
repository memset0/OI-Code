#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
bool bo;
int a[15][15], b[15][15], c[15][15], d[15][15], e[15][15];
int main()
{
	int n;
	char str[15];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	/*start*/{
		scanf("%s", str);
		for (int j = 0; j < n; j++)
		{
			switch (str[j])
			{
				case '@' :
					a[i][j+1] = 0;
					break;
				case '-' :
					a[i][j+1] = 1;
					break;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	/*end*/{
		scanf("%s", str);
		for (int j = 0; j < n; j++)
		{
			switch (str[j])
			{
				case '@' :
					e[i][j+1] = 0;
					break;
				case '-' :
					e[i][j+1] = 1;
					break;
			}
		}
	}
	
	// ===== 6 =====
	bo = true;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (a[i][j] != e[i][j]) bo = false;
	if (bo) 
	{	
		printf("%d", 6);
		return 0;
	}
	// ===== 4 =====
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			d[i][j] = a[i][(n+1) - j];
		}
	}
	bo = true;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (d[i][j] != e[i][j]) bo = false;
	if (bo) 
	{	
		printf("%d", 4);
		return 0;
	}
	// ===== 1 =====
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			b[j][(n+1)-i] = a[i][j];
		}
	}
	bo = true;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (b[i][j] != e[i][j]) bo = false;
	if (bo) 
	{	
		printf("%d", 1);
		return 0;
	}
	// ===== 2 =====
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			c[j][(n+1)-i] = b[i][j];
		}
	}
	bo = true;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (c[i][j] != e[i][j]) bo = false;
	if (bo) 
	{	
		printf("%d", 2);
		return 0;
	}
	// ===== 3 =====
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			d[j][(n+1)-i] = c[i][j];
		}
	}
	bo = true;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (d[i][j] != e[i][j]) bo = false;
	if (bo) 
	{	
		printf("%d", 3);
		return 0;
	}
	// ===== 5.1 =====
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = b[i][(n+1) - j];
		}
	}
	bo = true;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (a[i][j] != e[i][j]) bo = false;
	if (bo) 
	{	
		printf("%d", 5);
		return 0;
	}
	// ===== 5.2 =====
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = c[i][(n+1) - j];
		}
	}
	bo = true;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (a[i][j] != e[i][j]) bo = false;
	if (bo) 
	{	
		printf("%d", 5);
		return 0;
	}
	// ===== 5.3 =====
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = d[i][(n+1) - j];
		}
	}
	bo = true;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (a[i][j] != e[i][j]) bo = false;
	if (bo) 
	{	
		printf("%d", 5);
		return 0;
	}
	// ===== 7 =====
	printf("%d", 7);
	return 0;
}
