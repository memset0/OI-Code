#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int n;
	cin >> n;
	char a[100], b[100];
	int s1, s2;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s%s", a, b);
		s1 = 0;
		s2 = 0;
		//cout << a << b;
		if (a[0] == 'R')
		{
			if (b[0] == 'R') s1++,s2++;
			if (b[0] == 'P') s2++;
			if (b[0] == 'S') s1++;
		}
		if (a[0] == 'P')
		{
			if (b[0] == 'R') s1++;
			if (b[0] == 'P') s1++,s2++;
			if (b[0] == 'S') s2++;
		}
		if (a[0] == 'S')
		{
			if (b[0] == 'R') s2++;
			if (b[0] == 'P') s1++;
			if (b[0] == 'S') s1++,s2++;
		}
		//cout << s1 << s2;
		if (s1 > s2) cout << "Player1\n";
		else if (s1 == s2) cout << "Tie\n";
		else if (s1 < s2) cout << "Player2\n";
	}
	return 0;
}
