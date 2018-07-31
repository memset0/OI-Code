#include <bits/stdc++.h>
int main()
{
	int i, m, s, plan, flag=0, l=0, mark=0;
	for(m=1; m<=12; m++)
	{
		l+=300;
		scanf("%d",&plan);
		l = l - plan;
		if(l<0)
		{
			flag=1;
			break;
		}
		else
		{
			i = l/100;
			mark += (100*i);
			l -= (100*i);
		}
	}
	if(flag)
		printf("-%d",m);
	else
	{
		s=((1.2*mark) + l);
		printf("%d",s);
	}
	return 0;
}
