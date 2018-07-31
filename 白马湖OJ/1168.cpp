#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	char s[1010], c;
	gets(s);
	int l = strlen(s);
	int ans = 0;
	for (int i = 0; i < l; i++)
	{
		c = s[i];
		if ('1' <= c && c <= '9')
		{
			ans = ans + c - '0';
			//cout << c << " ";
		}
	}
	cout << ans;
	return 0;
} 
