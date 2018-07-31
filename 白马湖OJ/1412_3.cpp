#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
char str[1001];
char c[1001];
char ch;
int ans[1001];
int n[1001];
int w;
bool _sym(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}
int cal()
{
	switch (c[w])
	{
		case '+':
			ans[w] = ans[w] + c[w];
			c[w] = 0;
			break;
		case '-':
			ans[w] = ans[w] - c[w];
			c[w] = 0;
			break;
		case '*':
			ans[w] = ans[w] *
	}
} 
int main()
{
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++)
	{
		ch = str[i];
		if ('0' <= ch && ch <= '9')
		{
			if (n[w] == -1)
			{
				cal();
				n[w] = ch - '0';
			}
			else n[w] = n[w] * 10 + ch - '0';
		}
		else
		{
			if (_sym(ch))
			{
				if (_sym(c[w]))
				{
					cal();
					c[w] = ch;
				}
				else c[w] = ch;
			} 
			else if (ch == '(')
			{
				w++;
			}
			else if (ch == ')')
			{
				if (_sym(c[w])) cal();
				w--;
				if (_sym(c[w])) cal();
			}
		} 
	}
	return 0; 
} 
