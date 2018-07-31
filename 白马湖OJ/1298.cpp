#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 1100;
const int P = 100000000;
int a[N], b, t[N];
char aa[N];
int lena, lenb, lent, len;
long long ans;
int max(int, int);
void mod(); 
int main()
{
	//input
	int n;
	scanf("%d %s", &b, aa);
	lent = strlen(aa);
	if (b == 100000000)
	{
		int temp = 0;
		for (int i = lena - 7; i <= lena; i++)
		{
			if (temp == 0 && a[i] == '0') continue;
			temp = 1;
			printf("%c", a[i]);
		}
		return 0;
	}
	lena = 0;
	int t1 = 1, t2 = 0;
	for (int i = lent - 1; i >= 0; i--)
	{
		if (t1 == P)
		{
			lena++;
			a[lena] = t2;
			t2 = 0;
			t1 = 1;
		}
		t2 += (aa[i] - '0') * t1;
		t1 *= 10;
	}
	lena++;
	a[lena] = t2;
	if (a[lena] == 0) lena--;
	/*printf("%d\n", lena);
	for (int i = 1; i <= lena; i++) printf("%d ", a[i]);
	printf("\n");*/
	//main
	mod();
	//output
	printf("%d", ans);
	return 0;
}
void mod()
{
	for (int i = lena; i >= 1; i--)
	{
		ans = (P * ans + a[i]) % b;
	}
}
int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}
