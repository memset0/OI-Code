#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 100015;
double num[N];
char sql[N];
char str[N];
int pri[256];
bool is_num(char c)
{
	if ('0' <= c && c <= '9') return true;
	else return false;
}
int top_num = 0, top_sql = 0;
double pop_num()
{
	return num[top_num--];
}
char pop_sql()
{
	return sql[top_sql--];
}
void push_num(double n)
{
	num[++top_num] = n;
}
void push_sql(char c)
{
	sql[++top_sql] = c;
}
void cal()
{
	char ch = pop_sql();
	double b = pop_num(), a = num[top_num], ans;
	switch (ch)
	{
		case '+':
			ans = a + b;
			break;
		case '-':
			ans = a - b;
			break;
		case '*':
			ans = a * b;
			break;
		case '/':
			ans = a / b;
			break;
	}
	num[top_num] = ans;
}
int main()
{
	pri['+'] = 1;
	pri['-'] = 1;
	pri['*'] = 2;
	pri['/'] = 2; 
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++)
	{
		if /*读入数字*/(is_num(str[i]))
		{
			if (is_num(str[i - 1]))
			{
				num[top_num] = num[top_num] * 10 + str[i] - '0';
			}
			else 
			{
				num[++top_num] = str[i] - '0';
			}
		}
		else /*读入运算符或括号*/
		{
			if (str[i] == ')')
			{
				while (sql[top_sql] != '(') 
				{
					cal();
				}
				pop_sql();
			}
			else if (str[i] == '(')
			{
				push_sql('(');
			}
			else if (top_sql == 0 || pri[str[i]] > pri[sql[top_sql]])
			{	
				push_sql(str[i]);
			}
			else 
			{
				while (pri[str[i]] <= pri[sql[top_sql]]) 
				{
					cal();
				}
				push_sql(str[i]);
			}
		}
	}
	while (top_sql > 0) cal();
	double tt = num[1];
	if (tt == floor(tt)) printf("%d", (int)tt);
	else if ((tt * 10) == floor(tt * 10)) printf("%.1lf", tt);
	else
	{
		/*int aa = floor(tt), bb = (int)floor(tt * 100) % 100, cc = (int)floor(tt * 1000) % 10;
		if (cc >= 5) bb += 1;
		printf("%d.%d", aa, bb);*/
		printf("%.2lf", tt);
	}
	return 0; 
}
