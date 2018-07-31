#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std; 
const int N = 100015;
char str[N];
char a[N];
int b[N];
double num[N];
char ch, temp;
int w, len = 0, num_r;
double tmp;
struct Zhan{
	char c[N];
	int r;
}z;
bool _sym(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}
int _pri(char c)
{
	if (c == '*' || c == '/') return 2;
	else if (c == '+' || c == '-') return 1;
}
int push1(char c)
{
	z.c[++z.r] = c;
}
char pop1()
{
	if (z.r == 0) return 0;
	z.r = z.r - 1;
	return z.c[z.r + 1];
}
double push2(double n)
{
	num[++num_r] = n;
}
double pop2()
{
	if (num_r == 0) return 0;
	return num[num_r--];
}
int i;
int main()
{
	memset(b, -1, sizeof(b)); b[-1] = -1;
	scanf("%s", str);
	
	len = 0; z.r = 0;
	for (i = 0; i < strlen(str); i++)
	{
		ch = str[i];
		if ('0' <= ch && ch <= '9')
		{
			if ('0' <= str[i-1] && str[i-1] <= '9') b[len-1] = b[len-1] * 10 + ch - '0';
			else b[len++] = ch - '0';
		}
		else if (_sym(ch)) 
		{
			if (z.r == 0 || z.c[z.r] == '(') push1(ch);
			else if (_pri(ch) > _pri(z.c[z.r])) push1(ch);
			else {while (_pri(ch) <= _pri(z.c[z.r])) a[len++] = pop1(); push1(ch);}
		}
		else if (ch == '(') push1(ch);
		else if (ch == ')')
		{
			while (z.r > 0)
			{
				temp = pop1();
				if(temp == '(') break;
				else a[len++] = temp;
			}
		}
		/*printf("%d : ", i);
		for (int j = 1; j <= z.r; j++) 
		{
			printf("%d ", j);
			printf("%c ", z.c[j]);
		}
		printf("\n");*/
	}
	while (z.r > 0)	a[len++] = pop1();
	/*for (i = 0; i < len; i++)
	{
		if (b[i] == -1) printf("%c ", a[i]);
		else printf("%d ", b[i]);
	}
	printf("\n");*/
	for (i = 0; i < len; i++)
	{
		if (b[i] != -1)
		{
			push2(b[i]);
			//printf("i=%d : a=%c b=%d r=%d num[%d]=%.2lf\n", i, a[i], b[i], num_r, num_r, num[num_r]);
			continue;
		}
		else 
		{
			ch = a[i];
			/*printf("i=%d : a=%c b=%d r=%d\n", i, a[i], b[i], num_r);
			for (int i = 1; i <= num_r; i++)
				printf("      num[%d]=%.2lf\n", i, num[i]);*/
			tmp = pop2();
			switch (ch)
			{
				case '+':
					num[num_r] += tmp;
					break;
				case '-':
					num[num_r] -= tmp;
					break;
				case '*':
					num[num_r] *= tmp;
					break;
				case '/':
					num[num_r] /= tmp;
					break;
			}
			/*printf("i=%d : a=%c b=%d r=%d\n", i, a[i], b[i], num_r);
			for (int i = 1; i <= num_r; i++)
				printf("      num[%d]=%.2lf\n", i, num[i]);*/
		}
	}
	double tt = num[num_r];
	//printf("%.2lf\n", tt);
	if (tt == (int)tt) printf("%d", (int)tt);
	else if ((tt * 10) == (int)(tt * 10)) printf("%.1lf", tt);
	else printf("%.2lf", tt);
	return 0; 
}



