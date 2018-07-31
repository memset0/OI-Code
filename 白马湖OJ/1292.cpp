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
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(ans, 0, sizeof(ans));
	scanf("%s%s", al, bl);
	lena = strlen(al);
	lenb = strlen(bl);
	for (int i = 0; i <= lena - 1; i++) // a[1] = al[lena - 1]
		a[lena - i] = al[i] - '0';
	for (int i = 0; i <= lenb - 1; i++)
		b[lenb - i] = bl[i] - '0';
	int x;
	for (int i = 1; i <= lena; i++)
	{
		x = 0;
		for (int j = 1; j <= lenb; j++)
		{
			ans[i + j - 1] = a[i] * b[j] + x + ans[i + j - 1];
			x = ans[i + j - 1] / 10;
			ans[i + j - 1] %= 10;
		}
		ans[i + lenb] = x;
	}
	len = lena + lenb;
	while (len > 1 && ans[len] == 0) len--; //É¾³ýÇ°µ¼0 
	for (int i = len; i >= 1; i--)
	{
		printf("%d", ans[i]);
	}
	return 0;
}
