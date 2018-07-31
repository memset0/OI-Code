#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	char s[100];
	int k;
	scanf("%s%d", s, &k);
	int l = strlen(s);
	int ans = 0;
	char c;
	int d;
	for (int i = (l - 1); i >= 0; i--)
	{
		c = s[i];
		d = c - '0';
		ans = ans * k + d; 
	}
	cout << ans;
	return 0;
}
