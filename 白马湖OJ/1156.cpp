#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	double f;
	cin >> f;
	char s1[1010],s2[1010];
	scanf("%s%s", s1, s2);
	int l = strlen(s1);
	int n = 0;
	for (int i = 0; i < l; i++)
	{
		if (s1[i] == s2[i]) n++;
	}
	double f_real = n * 1.0 / l;
	if(f_real >= f) cout << "yes\n";
	else cout << "no\n";
	//cout << n << ' ' << l << ' ' << f << ' ' << f_real;
	return 0;
}
