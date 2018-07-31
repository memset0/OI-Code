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
	long long aa, bb, n;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(ans, 0, sizeof(ans));
	
	scanf("%d", &n);
	aa = n; bb = n + 1;
	if (aa % 2 == 0) aa /= 2;
	else bb /= 2;
	lena = 0; lenb = 0;
	while (aa > 0)
	{a[++lena] = aa % 10; aa /= 10;}
	while (bb > 0)
	{b[++lenb] = bb % 10; bb /= 10;}
	printf("a[] = ");
	for (int i = 1; i <= lena; i++)
		printf("%d", a[i]);
	printf("\nb[] = ");
	for (int i = 1; i <= lena; i++)
		printf("%d", b[i]);
	printf("\n");
	int x;
	for (int i = 1; i <= lena; i++)
	{
		x = 0;
		for (int j = 1; j <= lenb; j++)
		{
			ans[i + j - 1] = a[i] * b[j] + x + ans[i + j - 1];
			//printf("a[%d] = %d; b[%d] = %d; x = %d; \n", i, a[i], j, b[j], x);
			x = ans[i + j - 1] / 10;
			ans[i + j - 1] %= 10;
		}
		ans[i + lenb] = x;
	}
	len = lena + lenb;
	while (len > 1 && ans[len] == 0) len--; //É¾³ýÇ°µ¼0 
	for (int i = len; i >= 1; i--)
	{
		printf("%d", ans[i] % 10);
	}
	return 0;
}
