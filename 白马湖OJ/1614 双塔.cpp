#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int maxm = 2010;
int n, a, f[maxm][maxm];
int main()
{
	scanf("%d", &n);
	int sum = 0;
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		sum += a;
		for (int j = sum-a; j >= 0; j--)
			for (int k = sum-a; k >= 0; k--)
				if (f[j][k])
				{
					f[j+a][k] = true;
					f[j][k+a] = true;
				}
	}
//	for (int i = 0; i <= sum; i++)
//	{
//		for (int j = 0; j <= sum; j++)
//			cout << f[i][j];
//		puts("");
//	}
	for (int i = sum; i >= 1; i--)
		if (f[i][i])
		{
			cout << i << endl;
			return 0;
		}
	cout << "Impossible" << endl;
	return 0;
}



/*#include <bits/stdc++.h> 
using namespace std;
const int maxn = 110, maxm = 2010;
int n, a[maxn];
bool f[maxm][maxm];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= 2000; i++)
		f[0][i] = 1, f[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 2000; j >= a[i]; j--)
			for (int k = 2000; k >= a[i]; k--)
				f[j][k] = f[j-a[i]][k] || f[j][k-a[i]];
	for (int i = 0; i <= 15; i++)
	{
		for (int j = 0; j <= 15; j++)
			cout << f[i][j];
		puts("");
	}
	for (int i = 2000; i > 0; i--)
		if (f[i][i])
		{
			printf("%d", i);
			return 0;
		}
	printf("Impossible");
	return 0;
}*/





/*#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int maxm = 2010;
int n, a;
bool f[maxm][maxm];
int main()
{
	int n; cin >> n;
	int sum = 0;
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
	 	scanf("%d", &a);
	 	for (int j = sum-a; j >= 0; j--)
	 		for (int k = sum-a; k >= 0; k--)
	 			if (f[j][k])
	 			{
	 				f[j+a][k] = 1;
	 				f[j][k+a] = 1;
				}
		sum += a;
	}
	for (int i = 1; i <= 15; i++)
	{
		for (int j = 1; j <= 15; j++)
			printf("%d", f[i][j]);
		puts("");
	}
	for (int i = sum; i >= 1; i--)
	{
		if (f[i][i])
		{
			printf("%d\n", i);
		}
	}
	
	return 0;
}*/




/*#include <bits/stdc++.h> 
using namespace std;
const int maxn = 110, maxm = 2010;
int n, a[maxn];
bool f[maxm][maxm];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 2000; j >= 0; j--)
			for (int k = 2000; k >= 0; k--)
				f[j+a[i]][k] |= f[j][k], f[j][k+a[i]] |= f[j][k];
	for (int i = 0; i <= 15; i++)
	{
		for (int j = 0; j <= 15; j++)
			cout << f[i][j];
		puts("");
	}
	for (int i = 2000; i > 0; i--)
		if (f[i][i])
		{
			printf("%d", i);
			return 0;
		}
	printf("Impossible");
	return 0;
}
*/
