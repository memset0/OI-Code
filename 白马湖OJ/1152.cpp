#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	char s[1010];
	gets(s);
	int k=0;
	for (int i=0;i<strlen(s);i++)
	{
		char c=s[i];
		if (c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c=='0')
			k++;
	}
	cout<<k;
	return 0;
} 
