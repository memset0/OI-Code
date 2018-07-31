#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int p1, p2, p3;
char s[1200];
void f(char, char);
void ff(char);

int main()
{
	scanf("%d%d%d", &p1, &p2, &p3);
	scanf("%s", s);
	int l = strlen(s);
	char c;
	for (int i = 0; i < (l - 1); i++)
	{
		c = s[i];
		if (c == '-')
		{
			if (s[i - 1] == '-' || s[i + 1] == '-')
			{
				putchar(c);
			}
			else if (s[i - 1] >= s[i + 1])
			{
				putchar(c);
			}
			else 
			{
				f(s[i - 1], s[i + 1]);
			}			
		}
		else 
		{
			putchar(c);
		}
	}
	putchar(s[strlen(s) - 1]);
	return 0;
}

void f(char a, char b)
{
	if (p3 == 1)
	{
		for (char i = (a + 1); i < b; i++)
			ff(i);
	}
	if (p3 == 2)
	{
		for (char i = (b - 1); i > a; i--)
			ff(i);
	}
}
void ff(char c)
{
	for (int i = 1; i <= p2; i++)
	{
		if (p1 == 1)
		{
			if ('A' <= c && c <= 'Z') c = c + 'a' - 'A';
			putchar(c);
		}
		if (p1 == 2)
		{
			if ('a' <= c && c <= 'z') c = c - 'a' + 'A';
			putchar(c);
		}
		if (p1 == 3)
		{
			putchar('*');
		}
	}
}
