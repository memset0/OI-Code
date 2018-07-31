//以前打的代码，现在那个账号上不去了，所以再交一遍 
#include <cstdio>
#define ll long long
using namespace std;
ll a[101];
int main()
{
	ll temp=1;
	int k=0;
	while (temp!=0)
	{
		scanf("%lld",&temp); 
		a[k++]=temp;
	}
	for (int i=k-2;i>=0;i--) printf("%d ",a[i]);
	return 0;
}
