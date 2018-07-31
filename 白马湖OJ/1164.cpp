#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int p1, p2, p3;
void f(char, char);
void ff(char);
int main()
{
	char s[200];
	scanf("%d%d%d%s", &p1, &p2, &p3, s);
	for (int i = 0; i < (strlen(s) - 1); i++)
	{
		if (s[i] == '-') 
		{
			if (s[i - 1] == '-' || s[i + 1] == '-') putchar(s[i]);
			else if (s[i - 1] >= s[i + 1]) putchar(s[i]);
			else if ((s[i - 1] + 1) ==  s[i + 1]);
			else f(s[i - 1], s[i + 1]);
		}
		else
		{
			putchar(s[i]);
		}
	}
	putchar(s[strlen(s) - 1]);
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
