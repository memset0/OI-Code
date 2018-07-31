#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1000015;
int a[N];
bool mark[N];
int main()
{
	int n, m;
	scanf("%d%d\n", &n, &m);
	char ch;
	for (int i = 1; i <= n; i++)
	{
		scanf("%c", &ch);
		a[i] = ch - '0';
	}
	int t, _t, _find;
	for (int j = 1; j <= m; j++)
	{
		_t = false; _find = false;
		for (int i = 1; i <= n; i++)
		{
			if (mark[i] == 1) continue;
			if (_t == false) {_t = true, t = a[i]; continue;}
			if (t >= a[i])
			{
				mark[i] = 1;
				_find = true;
				break;
			}
			else 
			{
				t = a[i];
			}
		}
		if (!_find)
		{
			for (int i = n; i >= 1; i--) 
				if (mark[i] != 1) 
				{
					mark[i] = 1;
					break;
				}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (mark[i] != 1) printf("%d", a[i]);
	}
	return 0;
}
