#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int i,j=0,k=0;
	bool b=false;
	char s1[10],s2[10],s[100];
	gets(s);
	for(i=0;i<strlen(s);i++)
	{
		if ((s[i]!=',')&&(b==false))
		{
			s1[k]=s[i];
			k++;
		}
		if (s[i]==',') b=true;
		if ((s[i]!=',')&&(b==true))
		{
			s2[j]=s[i];
			j++;
		}
	}
	s1[k]='\0';	s2[j]='\0'; 
	printf("%s,%s",s2,s1);
	return 0;
}
