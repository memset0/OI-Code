#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
char a[110], b[110], c[110];
void f(int la, int ra, int lb, int rb)
{
	if (la > ra || lb > rb) return;
	if (la == ra || lb == rb)
	{
		printf("%c", a[la]); 
		return;
	}
	int mid;
	for (int i = lb; i <= rb; i++)
		if (b[i] == a[la]) 
		{
			mid = i;
			break;
		}
	f(la+1, mid+la-lb, lb, mid-1);
	f(mid+la-lb+1, ra, mid+1, rb);
	printf("%c", a[la]);
}
int main()
{
	scanf("%s%s", a+1, b+1);
	int len = 1;
	while ('A' <= a[len] && a[len] <= 'Z') len++; len--;
	f(1, len, 1, len);
	return 0;
}
