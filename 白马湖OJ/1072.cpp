#include <bits/stdc++.h>
using namespace std;
void f(char c, int n)
{
	for (int i = 1; i <= n; i++) printf("%c", c);
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		f(' ', (n - i));
		f('*', (i * 2 - 1));
		puts("");
	}
	for (int i = (n - 1); i >= 1; i--)
	{
		f(' ', (n - i));
		f('*', (i * 2 - 1));
		puts("");
	}
	return 0;
}

