#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}
int main()
{
	char al[500], bl[500];
	int a[500], b[500], ans[500];
	int lena, lenb, len;
	int i, x;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(ans, 0, sizeof(ans));
	scanf("%s%s", al, bl);
	lena = strlen(al);
	lenb = strlen(bl);
	for (int i = 1; i <= lena; i++) // a[1] = al[lena - 1]
		a[i] = al[lena - i] - '0';
	for (int i = 1; i <= lenb; i++)
		b[i] = bl[lenb - i] - '0';
	len = max(lena, lenb);
	for (int i = 1; i <= len; i++)
	{
		ans[i] += a[i] + b[i];
		ans[i + 1] = ans[i] / 10;
		ans[i] %= 10;
	}
	len++;
	while (ans[len] > 0)
	{
		ans[len + 1] = ans[len] / 10;
		ans[len] %= 10;
		len++;
	}
	for (int i = len - 1; i >= 1; i--)
	{
		printf("%d", ans[i]);
	}
	return 0;
}
