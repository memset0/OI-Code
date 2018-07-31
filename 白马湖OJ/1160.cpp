#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
bool f(int a,int b,char s[]);
int main()
{
	char s[1010];
	scanf("%s", s);
	int l = strlen(s);
	int k = 0;
	for (int i = 2; i <= l; i++)
	{
		for (int j = 0; j < l; j++)
		{
			if (f(j,(j+i-1),s) == true)
			{
				//cout << "|SB|";
				for (int k = j; k <= (j + i - 1); k++)
				{
					putchar(s[k]);
				}
				puts("");
				k++;
			}
		}
	}
	char ss[100] = "abcba";
	if (k==0) cout << "no\n";
}
bool f(int a,int b, char s[])
{
	if (a == b) return false;
	else
	{
		bool bo = true;
		for (int i = a; i <= floor((a + b) / 2); i++)
		{
			if (s[i] != s[a + b - i]) bo = false;
		}
		return bo;
	}
}
