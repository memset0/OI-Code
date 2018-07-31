#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 20015;
char a[N];
int main()
{
	int n, m;
	scanf("%d%d\n", &n, &m);
	char ch;
	scanf("%s", a);
	int i;
	for (int k = 1; k <= m; k++)
	{
		i = 0;
		while(i < strlen(a) && a[i] < a[i+1]) i++;  
		for(int j = i; j < strlen(a); j++) a[j] = a[j+1];
	}
	printf("%s", a);
	return 0;
}
