#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
char a[256], b[256], c[256];
using namespace std;
int main()
{
	scanf("%s %s", a + 1, b + 1);
	int len_a = strlen(a) - 1, len_b = strlen(b), len_c;
	if (len_a >= len_b) 
	{
		len_c = len_a;
	}
	else
	{
		len_c = len_b;
	}
	int temp = len_c;
	while (temp > 0)
	{
		temp--; len_a--; len_b--;
		
	}
	return 0;
}


