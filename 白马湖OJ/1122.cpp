#include <bits/stdc++.h> 
using namespace std;
const int maxn = 1010;
int n, a[maxn];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) 	
		scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++)
	{
		printf("%d", a[i]);
		if (i != n) printf(" ");
	}
	return 0;
}
