#include <bits/stdc++.h>
using namespace std;
int a[11], n, temp;
int main()
{
	for (int i = 1; i <= 10; i++)
		scanf("%d", &a[i]);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &temp);
		a[temp] += 10;
	}
	cout << a[1];
	for (int i = 2; i < 11; i++)
		cout << " " << a[i];
	return 0;
}
 
