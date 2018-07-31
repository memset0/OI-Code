#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n;
char a[maxn];
long long fc[maxn], fo[maxn], fw[maxn];
int main() {
//	freopen("cow.in", "r", stdin);
//	freopen("cow.out", "w", stdout);
	
	scanf("%d%s", &n, a + 1);
	
	fc[0] = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] == 'C') fc[i] = fc[i - 1] + 1;
		else fc[i] = fc[i - 1];
//	for (int i = 1; i <= n; i++)
//		printf("%d ", fc[i]);
//	puts("");
	
	fo[0] = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] == 'O') fo[i] = fo[i - 1] + fc[i];
		else fo[i] = fo[i - 1];
//	for (int i = 1; i <= n; i++)
//		printf("%d ", fo[i]);
//	puts("");
	
	fw[0] = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] == 'W') fw[i] = fw[i - 1] + fo[i];
		else fw[i] = fw[i - 1];
//	for (int i = 1; i <= n; i++)
//		printf("%d ", fw[i]);
//	puts("");
	
	printf("%lld\n", fw[n]);
	
	return 0;
}

