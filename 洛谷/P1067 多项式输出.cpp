#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, tmp;
	scanf("%d", &n);
	for (int i = n; i >= 0; i--)
	{
		scanf("%d", &tmp);
		if (tmp == 0) continue;
		if (tmp > 0 && i != n) printf("+");
		if (tmp == -1 && i != 0) printf("-");
		else if (tmp != 1 || i == 0) printf("%d", tmp);
		if (i == 1) printf("x");
		else if (i != 0) printf("x^%d", i);
	}
	puts("");
	return 0;
}
