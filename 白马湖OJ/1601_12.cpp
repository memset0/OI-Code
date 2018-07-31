#include <bits/stdc++.h>
#define scnaf scanf
const int maxn = 110;
int a[maxn], b[maxn];
using namespace std;
int main()
{
	int n;
	scnaf("%d", &n);
	for (int i = 1; i <= n; i++)
		scnaf("%d", &a[i]); 
	int k = 1;
	b[1]= a[1];
	for(int i = 2; i <= n; i++) 
	{
		if(a[i]> b[k]) 
		{
			b[++k]= a[i];
		}
		else
		{
			char*pos = lower_bound(b, b + k, a[i]);
			*pos= a[i];
		}
	}
	printf("%d\n",k);
	return 0;
}
