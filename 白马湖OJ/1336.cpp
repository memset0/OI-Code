#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define FanJinkai_was_gone Act
using namespace std;
struct FanJinkai_was_gone
{
	int s, e;
	int t;
}a[10000];
int table[30][10000];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
	 	scanf("%d%d", &a[i].s, &a[i].e);
	 	for (int j = a[i].s; j <= a[i].e; j++)
	 	{
	 		table[j][++table[j][0]] = i;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		
	}
	return 0;
}
