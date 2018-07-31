#include<stdio.h>
#include<string.h>
char str[35];
int k, a[20], b[20], c[20], num;
long long ans = 1;
int fun(int ans)
{
	int j;
	if(c[b[ans]] == 1) return 0;
	c[b[ans]] = 1;
	for(j = 0; j < k; j++)
	{
		if(b[ans] == a[j])
		{
			fun(j);
		}
	}
}
int main()
{
	int i, x, y, len, l, j, m;
	scanf("%s%d", str, &k);
	len=strlen(str);
	for(i = 0; i < k; i++)
	{
		scanf("%d%d", &x, &y);
		a[i] = x; b[i] = y;
	}
	for(i = 0; i < len; i++)
	{
		memset(c, 0, sizeof(c));
		num=str[i] - '0';
		for(j = 0; j < k; j++)
		{
			if(num == a[j])
			{
				c[num] = 1;
				fun(j); 
			}
		}
		m = 0;
		for(l = 0; l < 10; l++) m=m + c[l];
		if(m != 0) ans = ans * m;
	}
	printf("%lld", ans);
	return 0;
}
