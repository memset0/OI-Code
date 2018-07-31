#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m, t, u, f, d;
	char c;
	scanf("%d%d%d%d%d\n", &m, &t, &u, &f, &d);
	int ans = -1, time = 0;
	for (int i = 1;i <=t; i++)
	{
		scanf("%c%*c", &c);
		if (c == 'u' || c =='d') time+= u + d;
		else if (c == 'f') time += f + f;
		if (time > m && ans == -1) ans = i - 1;
	}
	if (ans == -1) ans = t;
	printf("%d", ans);
	return 0;
} 
