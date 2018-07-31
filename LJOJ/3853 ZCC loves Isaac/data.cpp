#include <cstdio>
#include <cstdlib>
#include <windows.h>

int n=4;

inline int brand(){
	return (rand()<<16)+(rand()<<1)+(rand()&1);
}

int main(){
//	freopen("isaac.in","w",stdout);
	srand(GetTickCount());
	printf("%d\n",n);
	for (int i=1;i<=n;i++) printf("%d\n",brand()%n+1);
	return 0;
}
