#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k[20] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int year, month;
	cin >> year >> month;
	if (month != 2) cout << k[month];
	else 
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) cout << 29;
		else cout << 28;
	}
	return 0;
}
