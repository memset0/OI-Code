#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	char s[1010];
	scanf("%s", s);
	int l = strlen(s);
	int n = 0;
	for (int i = 0; i < l; i++)
	{
		     if(s[i] == 'A') s[i] = 'T';
		else if(s[i] == 'T') s[i] = 'A';
		else if(s[i] == 'G') s[i] = 'C';
		else if(s[i] == 'C') s[i] = 'G';
	}
	puts(s);
	return 0;
}
