#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmatH>
using namespace std;
int a[110], b[110], bin[10];
int f(int n)
{
	bin[0] = 0;
	while (n > 0)
	{
		bin[++bin[0]] = n % 4 + 1;
		n /= 4;
	}
	return bin[0];
} 
int main()
{
	int n, c;
	scanf("%d%d", &n, &c);
	a[0] = 0; b[0] = 0;
	while (a[a[0]] != -1) scanf("%d", &a[++a[0]]);
	while (b[b[0]] != -1) scanf("%d", &b[++b[0]]);
	a[0]--; b[0]--;
	
	while (c > 4) c -= 2;
	int i = 1;
	while (f(i) <= c)
	{
		
		i++;
	}
	
	return 0;
}
