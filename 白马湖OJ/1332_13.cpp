#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 20015;
char a[N];
bool b[N];
int main()
{
	int n, m;
	scanf("%d%d\n", &n, &m);
	char ch;
	scanf("%s", a + 1);
	int l = strlen(a), i;
	for (int k = 1; k <= m; k++)
	{
		i = 0;
		while(i <= l && a[i] < a[i+1]) i++;
		for(int j = i; j <= l; j++) a[j] = a[j+1];
	}
	for (int i = 1; i <= l; i++)
	return 0;
}
