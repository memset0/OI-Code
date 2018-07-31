#include <bits/stdc++.h>
using namespace std;
int main()
{
	char a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);
	for (char i = a; i <= b; i++)
		cout << i;
	return 0;
}
