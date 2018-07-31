#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	char s[40];
	char a, b;
	scanf("%s %c %c", s, &a, &b);
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == a) s[i] = b;
	}
	//cout << a << " " << b;
	puts(s);
	return 0;
}
