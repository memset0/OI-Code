#include<bits/stdc++.h>
int n, m, ans, t;
int gcd(int x, int y)
{
    if(x < y) t = x, x = y, y = t;
    return x % y == 0 ? y : gcd(y, x % y);
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = n; i <= m; i += n)
		if((m * n) % i == 0 && gcd(m * n / i, i) == n)
			ans ++;
	printf("%d", ans);
	return 0;
}
