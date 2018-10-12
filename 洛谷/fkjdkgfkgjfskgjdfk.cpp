#include <stdio.h>
int fun(int n, int minNum, int maxNum)
{ 
	int tot, i;
	if (n == 0)
		return 1;
	tot = 0;
	for(i = minNum; i <= maxNum; i++)
		tot += fun(n - 1, i + 1, maxNum);
	return tot;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d\n", fun(m, 1, n));
	return 0;
}
