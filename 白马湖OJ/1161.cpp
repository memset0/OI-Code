#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	bool boolean = true;
	char a[200], b[200], c[200];
	int k[200] = {0};
	scanf("%s%s%s", a, b, c);
	char aa, bb;
	for (int i = 0; i < strlen(a); i++)
	{
		aa = a[i];
		bb = b[i];
		if (k[aa] == 0) k[aa] = bb;
		else if (k[aa] != bb) boolean = false;
	}
	for (int i = 'A'; i <= 'Z'; i++)
	{
		if (k[i] == 0) boolean = false;
	}
	if (boolean == false)
	{
		cout << "Failed";
	}
	else
	{
		for (int i = 0; i < strlen(c); i++)
		{
			c[i] = k[c[i]];
		}
		cout << c;
	}
	return 0;
}
 
