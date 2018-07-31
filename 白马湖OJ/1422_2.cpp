#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int n, sum = 0, a[100];
void DFS(int u)
{
	if (n <= sum || (n - sum) < a[a[0]]) return;
	if (sum != 0)
	{
		for (int i = 1; i <= a[0]; i++)
			printf("%d+", a[i]);
		printf("%d", n - sum);
		puts("");
	}
	for (int i = u; i <= n; i++)
	{
		sum += i;
		a[++a[0]] = i;
		DFS(i);
		sum -= i;
		a[0]--;
	}
}
int main()
{
	scanf("%d", &n);
	sum = 0; a[0] = 0;
	DFS(1);
	return 0;
} 
