#include <bits/stdc++.h>
#define read(a) scanf("%d", &a)
#define write printf
#define for(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int MAXN = 110, MAXA = 1e7, MAXV = 1e5 + 10;
int a[MAXN], f[MAXV];
int main()
{
	int v, n, a;
	read(v);
	read(n);
	for (i, 1, v)
		f[i] = 	MAXA;
	f[0] = 0;
	for (i, 1, n)
	{
		read(a);
		for (j, a, v)
			f[j] = min(f[j-a] + 1, f[j]);
	}
	//for (i, 1, v)
	//	write("%d ", f[i]);
	if (f[v] == MAXA) printf("0");
	else printf("%d", f[v]);
	return 0;
} 
