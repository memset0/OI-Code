#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[10], t = 7, ans = 0;
	for (int i = 1; i <= 7; i++)
		scanf("%d", &a[i]);
	while (a[t] == 0) t--;
	if (t == 1) ans = 1;
	else ans += t * a[1] + a[1];
	for (int i = 2; i <= 7; i++)
		ans += i * a[i];
	cout << ans << endl;
	return 0;
}









/*#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
	int a[10], ans = 0;
	for (int i = 1; i <= 7; i++)	
		scanf("%d", &a[i]);
	for (int i = 7; i >= 2; i--)
		if (a[i])
		{
			ans += i * a[1] + a[1];
			a[1] = 0;
		}
	for (int i = 1; i <= 7; i++)
		ans += a[i] * i;
	printf("%d", ans);
	return 0;
}
 */
