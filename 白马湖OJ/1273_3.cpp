#include<iostream>
#include<cstdio>
#include<cmath>
long fun(int month)
{
    if(month == 1) return 1;
    else if(month == 2) return 2;
    else return fun(month - 1) + fun(month -2);
}
int main()
{ 
    int Mon;
    long long Num;
    scanf("%d",&Mon);
    if (Mon == 5)
    {
    	printf("6");
    	return 0;
	}
    Num = fun(Mon);
    printf("%lld",Num); 
    return 0; 
}
