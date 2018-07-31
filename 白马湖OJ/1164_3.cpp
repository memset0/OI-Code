#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std; 
char a[110], b[2010];
int main()
{
	int a1, a2, a3, j;
	scanf("%d %d %d",&a1,&a2,&a3);
	scanf("%s",a+1); 
	int n=strlen(a+1);
	for(int i=1;i<n;i++)
	{
		if(a[i]!='-') printf("%c",a[i]);
		else if(a[i]=='-'&&(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z')||(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'))
		{
			if(a[i+1]<=a[i-1]) printf("%c",a[i]);
			else if(a[i+1]!=a[i-1]+1) 
			{
				if(a1==1) { j=0;for(int k=a[i-1]+1;k<=a[i+1]-1;k++) b[++j]=k; }
				if(a1==2)
				{ 
					j=0;
					for(int k=a[i-1]+1;k<=a[i+1]-1;k++) b[++j]=k;
					if(a[i-1]>='a'&&a[i+1]<='z')
					for(int j1=1;j1<=j;j1++) b[j1]=b[j1]-'a'+'A';
				}
				if(a1==3) {j=0;
				for(int k=a[i-1]+1;k<=a[i+1]-1;k++) b[++j]='*';}
				if(a3==1)
				{
					for(int k=1;k<=j;k++) 
					{
						for(int o=1;o<=a2;o++) printf("%c",b[k]);
					}
				}
				if(a3==2)
				{
					for(int k=j;k>=1;k--) 
					{
						for(int o=1;o<=a2;o++) 
						printf("%c",b[k]);
					}	
				}
			}
		}
		else printf("%c",a[i]);
	}
	printf("%c",a[n]);
	return 0;
}
