#include <cstdio>
using namespace std;
int a[110],b[110];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int temp=0;
		for (int j=1;j<i;j++)
		if (a[i]>a[j]) temp++;
		b[i]=temp;
	}
	for (int i=1;i<=n;i++) printf("%d ",b[i]);
	return 0;
}
