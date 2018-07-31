#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int TEST = 1;
struct my_string
{
	char s[256];
	int len;
}a, b, c;
int mark, len;
void getlen(my_string &a)
{
	a.len = strlen(a.s);
}
int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}
void move(my_string &a, int &len)
{
	int c = len - a.len;
	for (int i = a.len; i >= 1; i--)
	{
		a.s[i + c] = a.s[i - 1];
	}
	for (int i = c; i >= 1; i--)
	{
		a.s[i] = '0';
	}
}
void sum(my_string &a, my_string &b)
{
	len = max(a.len, b.len);
	move(a, len);
	move(b, len);
	mark = 0;
	int x, y, z;
	for (int i = len; i >= 1; i--)
	{
		x = a.s[i] - '0';
		y = b.s[i] - '0';
		z = x + y + mark;
		mark = z % 10;
		z = z / 10;
		c.s[i] = z + '0';
	}
}
int main()
{
	scanf("%s%s", a.s, b.s);
	getlen(a); 
	getlen(b);
	sum(a, b);
	if (mark != 0) printf("%d ", mark % 10);
	for (int i = 1; i <= len; i++)
	{
		printf("%c", c.s[i]);
	}
	if (TEST)
	{
		printf("\n\n\nmy_string a\n    ");
		for (int i = 1; i <= len + 5; i++)
			printf("%d", i % 10);
		printf("\ns = ");
		for (int i = 1; i <= len + 5; i++)
			printf("%c", a.s[i]);
		printf("\nmy_string b\n    ");
		for (int i = 1; i <= len + 5; i++)
			printf("%d", i % 10);
		printf("\ns = ");
		for (int i = 1; i <= len + 5; i++)
			printf("%c", b.s[i]);
		printf("\nmy_string c\n    ");
		for (int i = 1; i <= len + 5; i++)
			printf("%d", i % 10);
		printf("\ns = ");
		for (int i = 1; i <= len + 5; i++)
			printf("%c", c.s[i]);
	}
	return 0;
} 
