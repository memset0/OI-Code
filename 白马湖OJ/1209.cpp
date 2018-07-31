#include <bits/stdc++.h>
using namespace std;
int k;
int move(int n, char a, char b, char c)
{
	if (n == 0) return 0;
	move(n - 1, a, c, b);
	printf("move %d from %c to %c\n", n, a, c);
	k++;
	move(n - 1, b, a, c);
	return 0;
}
int main()
{
	int n;
	char a, b, c;
	cin >> n;
	scanf(" %c %c %c", &a, &b, &c);
	////cout << a << b << c;
	move(n, a, b, c);
	//cout << k;
}
