#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	char s[100], ss[100] = "";
	gets(s);
	gets(ss);
	char f = ss[0], c, cc;
	int k = 233;
	if (f == 'd' || f == 'D')
	{
		c = ss[2];
		for (int i = 0; i < strlen(s); i++)
		{
			if (s[i] == c)
			{
				k = i;
				break;
			}
		}
		for (int i = 0; i < strlen(s); i++)
		{
			if (i != k) putchar(s[i]);
		}
	}
	else if (f == 'I' || f == 'i')
	{
		c = ss[2];
		cc = ss[4];
		for (int i = (strlen(s) - 1); i >= 0; i--)
		{
			if (s[i] == c)
			{
				k = i;
				break;
			}
		}
		for (int i = 0; i < strlen(s); i++)
		{
			if (i != k) putchar(s[i]);
			else
			{
				putchar(cc);
				putchar(c);
			}
		}
	}
	else if (f == 'R' || f == 'r')
	{
		c = ss[2];
		cc = ss[4];
		bool bo = false;
		for (int i = (strlen(s) - 1); i >= 0; i--)
		{
			if (s[i] == c)
			{
				s[i] = cc;
				bo = true;
			}
		}
		if (bo == false) 
		{
			printf("No such character!");
			return 0;
		}
		for (int i = 0; i < strlen(s); i++)
			putchar(s[i]);
	}
}
