#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char s[100];
	int k[10] = {0, 0, 2, 3, 4, 6, 7, 8, 9, 10};
	int n[10] = {0};
	int ans = 0;
	scanf("%s", s);
	for (int i = 1; i <= 9; i++)
	{
		n[i] = s[k[i]] - '0';
		ans = ans + n[i] * i;
	}
	ans = ans % 11;
	char ansc;
	if (ans == 10) ansc = 'X';
	else ansc = ans + '0';
	if (ansc == s[12]) cout << "Right";
	else 
	{
		s[12] = ansc;
		puts(s);
	}
	return 0;
}
