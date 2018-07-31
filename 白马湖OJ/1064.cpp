#include <bits/stdc++.h>
using namespace std;
int k[100];
int f(int n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else if (n == 2) return 2;
	else if (k[n] != 0) return k[n];
	else 
	{
		k[n] = f(n - 1) + f (n - 2);
		return k[n];
	}
}
int main()
{
	int n;
	cin >> n;
	cout << f(n);
	return 0;
}
