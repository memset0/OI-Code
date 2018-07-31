#include <cstdio>
#include <cstdlib>
#include <windows.h>

int n=9,m=1;

int brand(){
	return (rand()<<16)+(rand()<<1)+(rand()&1);
} 

int main(){
//	freopen("thirst.in","w",stdout);
	srand(GetTickCount());
//	srand(time(0));
	printf("%d\n",n);
	for (int i=2;i<=n;i++){
		printf("%d %d\n",brand()%(i-1)+1,i);
	}
	printf("%d\n",m);
	for (int i=1;i<=m;i++){
		int x=brand()%n+1,y=brand()%n+1;
		while (y==x) y=brand()%n+1;
		printf("%d %d\n",x,y);
	}
	
	return 0;
} 
