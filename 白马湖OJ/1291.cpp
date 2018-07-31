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
	for (int i = 1; i <= lena; i++) // a[1] = al[lena - 1]
		a[i] = al[lena - i] - '0';
	for (int i = 1; i <= lenb; i++)
		b[i] = bl[lenb - i] - '0';
	len = max(lena, lenb);
	int mark = 0;
	if (lena < lenb) mark = 1;
	else
	{
		for (int i = len; i >= 1; i--)
		{
			if (a[i] > b[i]) {mark = 0; break;}
			else if (a[i] == b[i]) continue;
			else if (a[i] < b[i]) {mark = 1; break;};
		}
	}
	int temp;
	if (mark == 1)
	{
		for (int i = 1; i <= len; i++)
		{
			temp = a[i];
			a[i] = b[i];
			b[i] = temp;
		}
	}
	for (int i = 1; i <= len; i++)
	{
		ans[i] += a[i] - b[i];
		while (ans[i] < 0)
		{
			ans[i + 1] -= 1;
			ans[i] += 10;
		}
	}
	if (mark == 1) printf("-");
	mark = 0;
	for (int i = len; i >= 1; i--)
	{
		if (mark == 0 && ans[i] == 0) continue;
		mark = 1;
		printf("%d", ans[i]);
	}
	return 0;
}
