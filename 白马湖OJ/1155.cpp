#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	char s[1010]="";
	int n[1000];
	int k=0;
	gets(s);
	for(int i=0;i<strlen(s);i++)
	{
		if((s[i]!=' '&&s[i+1]==' ')||(s[i]!=' '&&s[i+1]=='\0'))
		{
			k++;
			n[k]=i;
		}
	}
	s[strlen(s)]=' ';
	int j=0;
	while (s[j]==' ')
	{
		putchar(' ');
		j++;
	}
	for (int i=1;i<=k;i++)
	{
		int j=n[i];
		while(s[j]!=' '&&j>=0)
		{
			putchar(s[j]);
			j--;
		}
		j=n[i]+1;
		while(s[j]==' '&&j!=strlen(s))
		{
			putchar(' ');
			j++;
		}
	}
	//putchar('|');
	puts("");
	//cout << n[k];
	return 0;
} 
