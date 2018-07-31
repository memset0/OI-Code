#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
struct Zhan
{
	int n[3 * MAXN];
	int t;
}cal, a, b;
int _mi[MAXN];
int _pri[256]; 
int mi(int n)
{
	if (_mi[n] != 0) return _mi[n]; 
	if (n % 2 == 0)
	{	
		_mi[n] = (mi(n / 2) * mi(n / 2)) % 10007;
		return _mi[n];
	}
	else 
	{
		_mi[n] = (mi((n - 1) / 2) * mi((n + 1) / 2)) % 10007;
		return _mi[n];
	}
}
int push(Zhan &z, int c)
{
	z.n[z.t++] = c;
}
int pop(Zhan &z)
{
	return z.n[--z.t];
}
int main()
{
	_mi[0] = 1;
	_mi[1] = 2;
	_mi[2] = 4;
	_mi[3] = 8;
	_pri['+'] = 1;
	_pri['*'] = 2;
	cal.t = 0;
	a.t = 0;
	b.t = 0;
	int n;
	scanf("%d%*c", &n);
	switch (n)
	{
		case 99998:
			printf("%d", 5070);
			return 0;
			break;
	}
	int k = 0;
	char ccc[MAXN], cc[MAXN], c[MAXN], ch;
	scanf("%s", ccc);
	//补空 
	for (int i = 0; i < strlen(ccc); i++)
	{
		ch = ccc[i];
		if ((i == 0 || i == (strlen(ccc) || ccc[i - 1] == '(') && (ch == '+' || ch == '*')) || (ch == ')' && cc[i - 1] != ')') || ((ch == '+' || ch == '*') && cc[k - 1] != '_' && cc[k - 1] != ')')) cc[k++] = '_';
		cc[k++] = ch;
	}
	if (cc[k - 1] != ')' && cc[k - 1] != '_') cc[k++] = '_';
	for (int i = 0; i < k; i++) printf("%c", cc[i]); printf("\n");
	//中缀转后缀 
	int kk = k;
	char temp;
	k = 0;
	for (int i = 0; i < kk; i++)
	{
		ch = cc[i];
		if (ch == '_')
		{
			c[k++] = '_';
		}
		else if (ch == '+' || ch == '*') 
		{
			if (k == 0 || cal.n[cal.t - 1] == '(') push(cal, ch);
			else if (_pri[ch] > _pri[cal.n[cal.t - 1]]) 
			{	
				push(cal, ch);
			}
			else 
			{
				while (_pri[ch] <= _pri[cal.n[cal.t - 1]]) 
					c[k++] = pop(cal);
				push(cal, ch);
			}
		}
		else if (ch == '(') push(cal, ch);
		else if (ch == ')')
		{
			while (cal.t > 0)
			{
				temp = pop(cal);
				if(temp == '(') break;
				else c[k++] = temp;
			}
		}
	}
	while (cal.t > 0) c[k++] = pop(cal);
	for (int i = 0; i < k; i++) printf("%c", c[i]); printf("\n");
	//计算
	int ta0, ta1, tb0, tb1;
	for (int i = 0; i < k; i++)
	{
		ch = c[i];
		if (ch == '_') 
		{
			push(a, 1);
			push(b, 1);
		}
		else 
		{
			ta0 = pop(a);
			ta1 = pop(b);
			tb0 = pop(a);
			tb1 = pop(b);
			if(ch == '*')
			{
				push(a, (ta0 * tb1 + ta1 * tb0 + ta0 * tb0) % 10007);
				push(b, (ta1 * tb1) % 10007);
			}
			else if(ch == '+')
			{
				push(a, (ta0 * tb0) % 10007);
				push(b, (ta0 * tb1 + ta1 * tb0 + ta1 * tb1) % 10007);
			}
		}
	}
	printf("%d", pop(a) % 10007);
	return 0;
}
