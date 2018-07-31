#include <bits/stdc++.h>
using namespace std;
const int maxn = 110, maxk = 110, maxw = 400010;
bool f[maxw];
int main()
{
	int n, a, b;
	long sum = 0;
	scanf("%d", &n);
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a, &b);
		for (long j = sum; j >= 0; j--)
			if (f[j])
				for (int k = 1; k <= a; k++)
					f[j+k*b] = 1;
		sum += a * b;
	}
	int cnt =  0;
	for (long i = 1; i <= sum; i++)
		if(f[i]) cnt += 1;
	printf("Total=%d", cnt);
	return 0;
}
