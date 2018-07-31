#include <bits/stdc++.h>
#define is_num(c) ('0' <= c && c <= '9')
#define ch str[i]
using namespace std;
const int maxl = 10010;
int ans;
double x;
int pri[256];
char str[maxl];
struct NUM__ {
	int len = 0;
	double n[maxl];
	void push(double x) {n[++len] = x;}
	double pop() {return n[len--];}
}num;
struct SQL__ {
	int len = 0;
	char c[maxl];
	void push(char x) {c[++len] = x;}
	char pop() {return c[len--];}
}sql;
void cal()
{
    double a = num.n[num.len], b = num.pop();
    char c = sql.pop();
    printf("%d %c %d\n", a, c, b);
    switch (c)
    {
        case '+': ans = a + b; break;
        case '-': ans = a - b; break;
        case '*': ans = a * b; break;
        case '/': ans = a / b; break;
    }
    num.n[num.len] = ans;
}
int main()
{
	pri['+'] = 1;
	pri['-'] = 1;
	pri['*'] = 2;
	pri['/'] = 2;
	gets(str);
	len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (is_num(ch))
		{
			x = 0;
			while (is_num(ch))
				x = x * 10 + ch - '0', i++;
			num.push(x);
		}
		if (sql.c[i] == '(') sql.push('(');
        else if (sql.len == 0 || pri[ch] > pri[sql.c[sql.len]]) sql.push(ch);
        else if (ch == ')')
        {
            while (sql.c[sql.len] != '(') cal(), printf("*");
            sql.pop();
        }
        else
        {
            while (pri[ch] <= pri[sql.c[sql.len]]) cal(), printf("%d %d\n", num.len, sql.len);
            sql.push(ch);
        }
	}
	printf("%.2lf", num.pop());
	return 0;
}
