#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
int a[maxn];
int main()
{
	int n, k;
	bool bo;
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (a[1] < a[2]) bo = true;
	else bo = false;
	cin >> k;
	n += k;
	for (int i = n-k+1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	if (bo)
	{
		printf("%d", a[1]);
		for (int i = 2; i <= n; i++)
		{
			printf(" %d", a[i]);
		}
	}
	else 
	{
		printf("%d", a[n]);
		for (int i = n-1; i >= 1; i--)
		{
			printf(" %d", a[i]);
		}
	} 
	return 0;
}










/*#include <bits/stdc++.h> 
using namespace std;
const int maxn = 220; 
int a[maxn];
int n, k, temp;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> k;
	for (int m = 1; m <= k; m++)
	{
		cin >> temp;
		for (int i = 1; i <= n; i++) 
			if (a[i] <= temp && temp < a[i+1])
			{
				for (int j = n; j >= i; j--)
					a[j+1] = a[j];
				a[i] = temp;
				break;
			}
		n++;
	}
	
	printf("%d", a[1]);
	for (int i = 2; i <= n; i++)
		printf(" %d", a[i]);
	puts("");
	return 0;
}*/
