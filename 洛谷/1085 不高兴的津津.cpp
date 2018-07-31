#include <bits/stdc++.h>
int main(){
	int i,t[8],a,b;
	for(i=1;i<=7;i++)
	{
		scanf("%d%d",&a,&b);
		t[i]=a+b;
	}
	a=0,b=0;
	for(i=1;i<=7;i++)
		if(t[i]>8&&t[i]>a) 
		{ 
			a=t[i];
			b=i;
		} 
	printf("%d",b);                                       
	return 0;
}
