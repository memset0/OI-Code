#include<stdio.h>
#include<string.h>
char str[35];
int k, a[20], b[20], c[20], num;
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
int ans[1000] = {0, 1}, l = 1;
void print()
{
	for (int i = l; i > 0; i--)
		printf("%d", ans[i]);
	puts("");
}
void mul(int x) {
//	printf(">>> %d\n", x);
	for (int i = l; i > 0; i--)
		ans[i] = ans[i] * x;
	for (int i = 1; i <= l; i++)
	{
		ans[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}
	while (ans[l + 1]) {
		l++;
		ans[l + 1] += ans[l] / 10;
		ans[l]  %= 10;
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
        if(m != 0) mul(m);
    }
    print();
    return 0;
}