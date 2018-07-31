#include <bits/stdc++.h> 
using namespace std;
const int maxn = 110 + 1000;
int n, cnt[300];
char str[maxn];
int main()
{
	scanf("%d\n", &n);
	gets(str);
	for (int i = 0; i < n; i++)
		cnt[str[i]]++;
	for (int i = 'a'; i <= 'z'; i++)
		if (cnt[i] != 0)
		{
			printf("%c %d\n", i, cnt[i]);
		}
	return 0;
}
