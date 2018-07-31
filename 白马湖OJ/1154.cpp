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
	if(s[0]!=' ') {k++; n[k]=0;}
	for(int i=1;i<strlen(s);i++)
	{
		if(s[i]!=' '&&s[i-1]==' ')
		{
			k++;
			n[k]=i;
		}
	}
	s[strlen(s)]=' ';
	for (int i=k;i>=1;i--)
	{
		int j=n[i];
		while(s[j]!=' ')
		{
			putchar(s[j]);
			j++;
		}
		if(i!=1) putchar(' ');
	}
	puts("");
	return 0;
} 
