//众里寻他千百度，蓦然回首，那人却在灯火阑珊处——辛弃疾【青玉案】 
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int m,n,k,r;
	cin>>m>>n; 
	k=m/n;
	r=m-n*k;
	printf("%d\n%d",k,r);
	return 0;
}
